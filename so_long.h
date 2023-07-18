/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:33:01 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 15:06:26 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

# define PB "./img/player_back.xpm"
# define PF "./img/player_front.xpm"
# define PL "./img/player_left.xpm"
# define PR "./img/player_right.xpm"
# define WALL "./img/wall.xpm"
# define GROUND "./img/ground.xpm"
# define CLC "./img/collectible.xpm"
# define EXT "./img/exit.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	void	**img;
	char	**map;
	char	**map_check;
	char	*buffer;
	int		imgx;
	int		imgy;
	int		player_position_x;
	int		player_position_y;
	int		map_width;
	int		map_height;
	int		map_pos_x;
	int		map_pos_y;
	int		coin_n;
	int		player_n;
	int		exit_n;
	int		player_bx;
	int		player_by;
	int		move_count;
}	t_data;

void	ft_mlx_files_to_image(t_data *data);
void	ft_get_map(t_data *data, char *argv2);
void	ft_create_window(t_data *data);
void	ft_create_map(t_data *data);
int		ft_check_map(t_data *data);
void	ft_pos_to_ber(t_data *data);
void	ft_game_finish(t_data *data);
int		ft_loops(t_data *data);
int		ft_check_exit(t_data *data);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		ft_close_game_button(t_data *data);
void	ft_destroy_game(t_data *data);
void	ft_check_move_count(t_data *data);
int		ft_check_ber(char *argv2);
int		ft_check_wall_x(t_data *data);
int		ft_check_wall_y(t_data *data);
int		ft_check_rectangular(t_data *data);
void	ft_get_map_height(t_data *data);
void	ft_move_up(t_data *data, int keycode);
void	ft_move_down(t_data *data, int keycode);
void	ft_move_right(t_data *data, int keycode);
void	ft_move_left(t_data *data, int keycode);
int		ft_check_valid(t_data *data);
int		ft_check_rectangular2(t_data *data);
void	ft_error_msg(void);
void	ft_create_map_coin(t_data *data);
void	ft_create_map_player(t_data *data);
void	ft_create_map_wall(t_data *data);
void	ft_create_map_ground(t_data *data);
void	ft_create_map_exit(t_data *data);
void	ft_get_player_pos(t_data *data);
void	ft_path(t_data *data, int x, int y);
int		ft_path_check(t_data *data);
void	ft_find_player_first(t_data *data);
void	ft_path_exit(t_data *data, int x, int y);
void	ft_map_free(t_data *data);
void	ft_map_free2(t_data *data);
void	ft_free_img(t_data *data);
void	ft_destroy_game(t_data *data);

#endif