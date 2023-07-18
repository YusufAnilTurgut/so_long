/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_controls2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:15:44 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 14:23:18 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *argv2)
{
	size_t	size;

	if (!argv2)
		return (0);
	size = ft_strlen(argv2) - 1;
	if (argv2[size] == 'r' && argv2[size - 1] == 'e'
		&& argv2[size - 2] == 'b' && argv2[size - 3] == '.')
		return (1);
	else
	{
		ft_printf("Your map is not a .ber file!!\n");
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}

void	ft_path(t_data *data, int x, int y)
{
	if (data->map_check[y][x] != '1' && data->map_check[y][x] != 'E' 
		&& data->map_check[y][x] != '.' ) 
	{
		if (data-> map_check[y][x] == 'C' || data-> map_check[y][x] == 'P'
			|| data-> map_check[y][x] == '0' || data ->map_check[y][x] == 'E')
		{
			data->map_check[y][x] = '.';
		}
		ft_path(data, x + 1, y);
		ft_path(data, x - 1, y);
		ft_path(data, x, y + 1);
		ft_path(data, x, y - 1);
	}
}

void	ft_path_exit(t_data *data, int x, int y)
{
	if (data->map_check[y][x] != '1' && data->map_check[y][x] != 'C')
	{
		if (data-> map_check[y][x] == 'C' || data-> map_check[y][x] == 'P'
			|| data-> map_check[y][x] == '0' || data ->map_check[y][x] == '.'
			|| data ->map_check[y][x] == 'E')
		{
			data->map_check[y][x] = '1';
		}
		ft_path_exit(data, x + 1, y);
		ft_path_exit(data, x - 1, y);
		ft_path_exit(data, x, y + 1);
		ft_path_exit(data, x, y - 1);
	}
}

int	ft_path_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (data->map_height))
	{
		while (x < (data->map_width))
		{
			if ((data-> map[y][x] == 'E' && data->map_check[y][x] == 'E')
				|| (data-> map[y][x] == 'C' && data->map_check[y][x] == 'C'))
			{
				return (0);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

void	ft_find_player_first(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (data->map_height))
	{
		while (x < (data->map_width))
		{
			if (data->map_check[y][x] == 'P')
			{
				data->player_bx = x;
				data->player_by = y;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
