/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:35:32 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/17 20:39:59 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_files_to_image(t_data *data)
{
	data->mlx = mlx_init();
	data->img = (void **)malloc(sizeof(void *) * 9);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, PF,
			&data->imgx, &data->imgy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, PL,
			&data->imgx, &data->imgy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, PR,
			&data->imgx, &data->imgy);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, PB,
			&data->imgx, &data->imgy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->imgx, &data->imgy);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->imgx, &data->imgy);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, CLC,
			&data->imgx, &data->imgy);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, EXT,
			&data->imgx, &data->imgy);
}

void	ft_error_msg(void)
{
	ft_printf("Error\n");
	exit(1);
}
