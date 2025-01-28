NAME = so_long
MLX_DIR = minilibx-linux/
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBFT = libft/libft.a minilibx-linux/libmlx.a \

SRC = mapcontrol.c mapcontrol2.c map_control3.c mlx_control.c key_code.c main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

INCLUDES = -I/usr/include -Imlx
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ./libft -s
		make -C ./minilibx-linux
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) ${INCLUDES} -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

clean:
		make clean -C ./libft
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re