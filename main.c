/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:04 by root              #+#    #+#             */
/*   Updated: 2022/07/07 23:06:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int argc, char **argv)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
}