NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
M_SRCS = so_long.c \
	moving/moving_utils.c \
	moving/moving.c \
	parsing/add_line.c \
	parsing/check_line.c \
	parsing/check_name.c \
	parsing/get_next_line.c \
	parsing/get_next_line_utils.c \
	parsing/parser.c \
	rendering/put_img.c \
	rendering/render.c \
	so_long_utils.c

M_OBJ = $(M_SRCS:.c=.o)


all : $(NAME)

$(NAME): $(M_OBJ)
	$(CC) $(FLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx
%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all