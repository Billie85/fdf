/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:39:03 by root              #+#    #+#             */
/*   Updated: 2022/08/31 01:09:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	color(t_fdf *data)
{
	if (data->ax.z != 0 || data->ax.z1 != 0)
		data->ax.color = data->ax.new_color + data->ax.z * 4;
	else
		data->ax.color = 0xffffff;
}
