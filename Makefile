NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AFLAGS = -g -L./mlx -lmlx -I./printf -framework AppKit -framework OpenGL
SRCS =  so_long.c xpm_to_image.c ft_move.c ft_get_map.c ft_create_map_window.c\
 ft_check.c ft_game_finish.c ft_map_controls.c ft_map_controls2.c\
 ft_create_map_window2.c ft_game_finish2.c
 
R = "\033[31m"
B = "\033[34m"


OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
GNL = ./get_next_line/get_next_line.a
PRNT = ./ft_printf/libftprintf.a

all: ${NAME}

$(GNL):
	@make -C ./get_next_line
$(MINI):
	@make -C ./mlx
$(LIBFT):
	@make -C ./libft
$(PRNT):
	@make -C ./ft_printf



$(NAME): $(MINI) $(LIBFT) $(GNL) $(PRNT)  $(OBJS) 
	$(CC) $(CFLAGS) $(AFLAGS) $(OBJS) $(LIBFT) $(PRNT) $(GNL) -o $(NAME)
	@echo "Creating Game"

%.o: %.c
	@echo $(R)Complining [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)
	@make clean -C mlx/
	@make clean -C libft/
	@make clean -C get_next_line/
	@make clean -C ft_printf/

fclean: clean
	@rm -rf ${NAME}
	@echo $(R)Removed [$(NAME)]$(B)
	@make clean -C mlx/
	@make fclean -C libft/
	@make fclean -C get_next_line/
	@make fclean -C ft_printf/

re: fclean all
.PHONY: fclean re all clean