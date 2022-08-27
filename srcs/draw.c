/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:42:37 by root              #+#    #+#             */
/*   Updated: 2022/08/27 18:46:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	color(t_fdf *data)
{
	data->ax.color = ( data->ax.z != 0 ||  data->ax.z1 != 0) ?
	data->ax.old_color +  data->ax.z * 2 : 0xffffff;
}

static float	find_max_num(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	change_sign(float num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}

void	init_xyz(t_fdf *i)
{
	i->ax.z = i->z_matrix[(int)i->ax.y_f][(int)i->ax.x_f] * i->ax.alt;
	i->ax.z1 = i->z_matrix[(int)i->ax.y1_f][(int)i->ax.x1_f] * i->ax.alt;
	i->ax.x = i->ax.x_f;
	i->ax.x1 = i->ax.x1_f;
	i->ax.y = i->ax.y_f;
	i->ax.y1 = i->ax.y1_f;
}

//画面右向きに増えていくスクリーンX座標。
//xは開始座標　x1は終了座標

//画面下向きに増えていくスクリーンY座標。
//yは開始座標　y1は終了座標

void	breseham(t_fdf *b)
{
	float	x_step;
	float	y_step;
	float	max;

	init_xyz(b);
	color(b);
	isometric (b);
	x_step = b->ax.x1 - b->ax.x;
	y_step = b->ax.y1 - b->ax.y;
	max = find_max_num(change_sign(x_step), change_sign(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(b->ax.x - b->ax.x1) || (int)(b->ax.y - b->ax.y1))
	{
		mlx_pixel_put(b->mlx_ptr, b->win_ptr, b->ax.x, b->ax.y, b->ax.color);
		b->ax.x += x_step;
		b->ax.y += y_step;
	}
}

void	draw_wireframe(t_fdf *data)
{
	data->ax.y_f = 0;
	while (data->ax.y_f < data->map_height)
	{
		data->ax.x_f = 0;
		while (data->ax.x_f < data->map_width)
		{
			if (data->ax.x_f < data->map_width -1)
			{
				data->ax.x1_f = data->ax.x_f + 1;
				data->ax.y1_f = data->ax.y_f;
				breseham(data);
			}
			if (data->ax.y_f < data->map_height -1)
			{
				data->ax.x1_f = data->ax.x_f;
				data->ax.y1_f = data->ax.y_f + 1;
				breseham(data);
			}
			data->ax.x_f++;
		}
		data->ax.y_f++;
	}
}
