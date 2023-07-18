/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:00:36 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 13:34:56 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (data->map_height))
	{
		while (j < (data->map_width))
		{
			if (data-> map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[4], data->map_pos_x, data->map_pos_y);
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[7], data->map_pos_x, data->map_pos_y);
			}
			data -> map_pos_x += 64;
			j++;
		}
		i++;
		j = 0;
		data -> map_pos_x = 0;
		data -> map_pos_y += 64;
	}
}

void	ft_create_map_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (data->map_height))
	{
		while (j < (data->map_width))
		{
			if (data-> map[i][j] == 'P')
			{
				ft_get_player_pos(data);
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[4], data->map_pos_x, data->map_pos_y);
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[0], data->map_pos_x, data->map_pos_y);
			}
			data -> map_pos_x += 64;
			j++;
		}
		i++;
		j = 0;
		data -> map_pos_x = 0;
		data -> map_pos_y += 64;
	}
}

void	ft_create_map(t_data *data)
{
	ft_create_map_coin(data);
	data -> map_pos_x = 0;
	data -> map_pos_y = 0;
	ft_create_map_player(data);
	data -> map_pos_x = 0;
	data -> map_pos_y = 0;
	ft_create_map_wall(data);
	data -> map_pos_x = 0;
	data -> map_pos_y = 0;
	ft_create_map_ground(data);
	data -> map_pos_x = 0;
	data -> map_pos_y = 0;
	ft_create_map_exit(data);
}
