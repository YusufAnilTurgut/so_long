/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_window2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:41:36 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 14:18:37 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_window(t_data *data)
{
	data->mlx_window = mlx_new_window (data->mlx, 64 * data->map_width, 
			64 * data-> map_height, "SO_LONG");
}

void	ft_create_map_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (data->map_height))
	{
		while (j < (data->map_width))
		{
			if (data-> map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[5], data->map_pos_x, data->map_pos_y);
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

void	ft_create_map_ground(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (data->map_height))
	{
		while (j < (data->map_width))
		{
			if (data-> map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[4], data->map_pos_x, data->map_pos_y);
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

void	ft_create_map_coin(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (data->map_height))
	{
		while (j < (data->map_width))
		{
			if (data-> map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[4], data->map_pos_x, data->map_pos_y);
				mlx_put_image_to_window(data->mlx, data->mlx_window, 
					data->img[6], data->map_pos_x, data->map_pos_y);
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

void	ft_get_player_pos(t_data *data)
{
	data->player_position_x = data->map_pos_x;
	data->player_position_y = data->map_pos_y;
}
