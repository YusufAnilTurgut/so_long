/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:59:55 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 14:33:33 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_move_count(t_data *data)
{
	data->move_count++;
	ft_printf("Number of movements = %d\n", data->move_count);
}

int	ft_loops(t_data *data)
{
	ft_pos_to_ber(data);
	ft_game_finish(data);
	ft_check_exit(data);
	return (0);
}

int	ft_check_map(t_data *data)
{
	if (!ft_check_rectangular(data) || !ft_check_valid(data))
	{
		ft_printf("Map characters are not valid!!\n");
		return (0);
	}
	if (!ft_check_rectangular2(data))
	{
		ft_printf("Map is not rectangular!!\n");
		return (0);
	}
	if (!ft_check_wall_x(data) || !ft_check_wall_y(data))
	{
		ft_printf("Map must surounded by walls!!\n");
		return (0);
	}
	ft_find_player_first(data);
	ft_path(data, data->player_bx, data->player_by);
	ft_path_exit(data, data->player_bx, data->player_by);
	if (!ft_path_check(data))
	{
		ft_printf("Not finishible map!!\n");
		return (0);
	}
	return (1);
}

int	ft_check_exit(t_data *data)
{
	if (data-> coin_n == 0)
	{
		return (1);
	}
	return (0);
}

void	ft_pos_to_ber(t_data *data)
{
	data -> player_bx = (data->player_position_x) / 64;
	data -> player_by = (data->player_position_y) / 64;
}
