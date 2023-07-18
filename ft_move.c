/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:44:56 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 13:27:50 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *data, int keycode)
{
	if (keycode == 13)
	{
		if ((data->map[data->player_by - 1][data->player_bx] == '0' 
			|| data->map[data->player_by - 1][data->player_bx] == 'C' 
			|| data->map[data->player_by - 1][data->player_bx] == 'P') 
			|| (data->map[data->player_by - 1][data->player_bx] == 'E' && 
					ft_check_exit(data) == 1))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
				data->player_position_x, data->player_position_y);
			data->player_position_y -= 64;
			ft_pos_to_ber(data);
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
				data->player_position_x, data->player_position_y);
			if (data->map[data->player_by][data->player_bx] == 'C')
			{
				data->coin_n--;
				data->map[data->player_by][data->player_bx] = '0';
			}
			ft_check_move_count(data);
		}
	}
}

void	ft_move_down(t_data *data, int keycode)
{
	if (keycode == 1)
	{
		if ((data->map[data->player_by + 1][data->player_bx] == '0' 
			|| data->map[data->player_by + 1][data->player_bx] == 'C' 
			|| data->map[data->player_by + 1][data->player_bx] == 'P') 
			|| (data->map[data->player_by + 1][data->player_bx] == 'E'
			&& ft_check_exit(data) == 1))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
				data->player_position_x, data->player_position_y);
			data->player_position_y += 64;
			ft_pos_to_ber(data);
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3],
				data->player_position_x, data->player_position_y);
			if (data->map[data->player_by][data->player_bx] == 'C')
			{
				data->coin_n--;
				data->map[data->player_by][data->player_bx] = '0';
			}
			ft_check_move_count(data);
		}
	}
}

void	ft_move_right(t_data *data, int keycode)
{
	if (keycode == 2)
	{
		if ((data->map[data->player_by][data->player_bx + 1] == '0' 
			|| data->map[data->player_by][data->player_bx + 1] == 'C' 
			|| data->map[data->player_by][data->player_bx + 1] == 'P') 
			|| (data->map[data->player_by][data->player_bx + 1] == 'E'
			&& ft_check_exit(data) == 1))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
				data->player_position_x, data->player_position_y);
			data->player_position_x += 64;
			ft_pos_to_ber(data);
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2],
				data->player_position_x, data->player_position_y);
			if (data->map[data->player_by][data->player_bx] == 'C')
			{
				data->coin_n--;
				data->map[data->player_by][data->player_bx] = '0';
			}
			ft_check_move_count(data);
		}
	}
}

void	ft_move_left(t_data *data, int keycode)
{
	if (keycode == 0)
	{
		if ((data->map[data->player_by][data->player_bx - 1] == '0' 
			|| data->map[data->player_by][data->player_bx -1] == 'C' 
			|| data->map[data->player_by][data->player_bx - 1] == 'P') 
			|| (data->map[data->player_by][data->player_bx - 1] == 'E'
			&& ft_check_exit(data) == 1))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
				data->player_position_x, data->player_position_y);
			data->player_position_x -= 64;
			ft_pos_to_ber(data);
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1],
				data->player_position_x, data->player_position_y);
			if (data->map[data->player_by][data->player_bx] == 'C')
			{
				data->coin_n--;
				data->map[data->player_by][data->player_bx] = '0';
			}
			ft_check_move_count(data);
		}
	}
}
