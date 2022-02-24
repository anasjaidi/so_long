NAME = so_long
B_NAME = so_long_bonus
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

B_SRCS = bonus/so_long_bonus.c \
	bonus/moving/moving_utils_bonus.c \
	bonus/moving/moving_bonus.c \
	bonus/moving/anime.c \
	bonus/parsing/add_line_bonus.c \
	bonus/parsing/check_line_bonus.c \
	bonus/parsing/check_name_bonus.c \
	bonus/parsing/get_next_line_bonus.c \
	bonus/parsing/get_next_line_utils_bonus.c \
	bonus/parsing/parser_bonus.c \
	bonus/rendering/put_img_bonus.c \
	bonus/rendering/put_utils.c \
	bonus/rendering/render_bonus.c \
	bonus/so_long_utils_bonus.c \
	bonus/moving/utils.c

M_OBJ = $(M_SRCS:.c=.o)

B_OBJ = $(B_SRCS:.c=.o)


all : $(NAME)

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(FLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx
$(NAME): $(M_OBJ)
	$(CC) $(FLAGS) $^ -o $@ -framework AppKit -framework OpenGL -lmlx
%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all
