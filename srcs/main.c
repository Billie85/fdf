/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:42:19 by root              #+#    #+#             */
/*   Updated: 2022/08/27 09:42:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	destroy_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

static int	check_error(int argc, char **argv)
{
	int	file_name;

	if (argc != 2)
	{
		(void)ANSI_COLOR_ORANGE;
		ft_printf("Error input file.\n");
		(void)BACK_COLOR;
		exit (EXIT_FAILURE);
	}
	file_name = ft_strlen(argv[1]) - 4;
	if (ft_memcmp(&argv[1][file_name], ".txt", 4) != 0)
	{
		(void)ANSI_COLOR_ORANGE;
		ft_printf("The file it's not 'txt'.\n");
		(void)BACK_COLOR;
		exit (EXIT_FAILURE);
	}
	else if (ft_memcmp(&argv[1][file_name], ".txt", 4) == 0)
		return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		*data;

	check_error (argc, argv);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->file_name = argv[1];
	read_map(data);
	window(data);
	draw_wireframe(data);
	mlx_hook(data->win_ptr, 2, 5, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, destroy_window, data);
	mlx_loop(data->mlx_ptr);
	close(data->map_fd);
	free(data);
	return (0);
}
