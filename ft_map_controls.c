/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:30:54 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 14:38:15 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangular(t_data *data)
{
	int	x;
	int	a;

	a = data->map_width * data->map_height + (data->map_height -1) - 1;
	x = 0;
	while (x <= a)
	{
		if (data->buffer[x] == '1' || data->buffer[x] == 'E' 
			|| data->buffer[x] == 'P' || data->buffer[x] == 'C' 
			|| (data->buffer[x] == '\n' && data->buffer[x + 1] != '\n') 
			|| data->buffer[x] == '0')
		{
			x++;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_check_rectangular2(t_data *data)
{
	size_t	b;

	b = data->map_width * data->map_height + (data->map_height -1);
	if (ft_strlen(data->buffer) != b)
		return (0);
	return (1);
}

int	ft_check_wall_x(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
	{
		if (data->map[y][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	y = data->map_height - 1;
	while (x < data->map_width)
	{
		if (data->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_wall_y(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < data->map_height)
	{
		if (data->map[y][x] != '1')
			return (0);
		y++;
	}
	y = 0;
	x = data->map_width - 1;
	while (y < data->map_height)
	{
		if (data->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_valid(t_data *data)
{
	int	i;

	i = 0;
	while (data->buffer[i])
	{
		if (data->buffer[i] == 'C')
		{
			data->coin_n++;
		}
		if (data->buffer[i] == 'P')
		{
			data->player_n++;
		}
		if (data->buffer[i] == 'E')
		{
			data->exit_n++;
		}
		i++;
	}
	if (data->exit_n != 1 || data->player_n != 1)
		return (0);
	return (1);
}
