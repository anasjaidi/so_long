NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
M_SRCS = moving/moving_utils.c moving/moving.c parsing/add_line.c parsing/check_line.c parsing/get_next_line.c parsing/get_next_line_utils.c parsing/parser.c rendering/put_img.c rendering/render.c so_long.c so_long_utils.c
M_OBJ = $(M_SRCS:.c=.o)

$(NAME):$(M_SRCS)
	$(CC) $(FLAGS) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit so_long.c $(M_SRCS) -o $(NAME)
