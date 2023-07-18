/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_finish2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:03:19 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 15:22:32 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_free2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_check[i])
	{
		free(data->map_check[i]);
		data->map_check[i++] = NULL;
	}
	free(data->map_check);
}

void	ft_destroy_game(t_data *data)
{
	ft_free_img(data);
	mlx_destroy_window(data->mlx, data->mlx_window);
	ft_map_free(data);
	ft_map_free2(data);
	free(data->buffer);
	free(data);
	exit(1);
}

void	ft_game_finish(t_data *data)
{
	if (data->map[data->player_by][data->player_bx] == 'E' && data->coin_n == 0)
	{
		ft_printf("YOU WIN\n");
		ft_destroy_game(data);
	}
}
