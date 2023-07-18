/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:57:58 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 15:07:15 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_move_up(data, 13);
	if (keycode == 1)
		ft_move_down(data, 1);
	if (keycode == 2)
		ft_move_right(data, 2);
	if (keycode == 0)
		ft_move_left(data, 0);
	if (keycode == 53)
		exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *) ft_calloc(sizeof(t_data), 1);
		if (!data)
			exit(1);
		if (ft_check_ber(argv[1]) == 1)
			ft_get_map(data, argv[1]);
		if (ft_check_map(data) == 0)
			ft_error_msg();
		ft_create_window(data);
		ft_create_map(data);
		mlx_loop_hook(data->mlx, ft_loops, data);
		mlx_hook(data->mlx_window, 2, 0, key_event, data);
		mlx_hook(data->mlx_window, 17, 0, ft_close_game_button, data);
		mlx_loop(data->mlx);
	}
	else
		ft_printf("ARGUMENT ERROR");
}
