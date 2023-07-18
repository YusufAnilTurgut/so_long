/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:25:21 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 15:07:17 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game_button(t_data *data)
{
	ft_destroy_game(data);
	return (0);
}

void	ft_free_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	free (data->img);
}

void	ft_map_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i++] = NULL;
	}
	free(data->map);
}
