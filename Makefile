INCFLAGS = -I/opt/X11/include/X11/
UNAME := $(shell uname)
LIBFT = libft/libft.a
MLX = minilibx/libmlx_Darwin.a
CFLAGS = -Wall -Wextra -Werror
NAME = mlx-test
SRCS = visual.c \
    handle_window_funcs.c \
    mandel.c \
    julia.c \
    color_hand.c \
    key_treat.c \
    error_hand.c \
    atod.c \
    treat_sets.c \
    set_rgb.c

OBJ_DIR = objs
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE = /opt/X11/include/X11

LFLAGS = -I libft -L libft -lft \
        -I $(INCFLAGS) \
        -L ./minilibx -lmlx -framework OpenGL -framework AppKit -L /opt/X11/lib -lX11

LFLAGS += -lX11 -lXext

ifeq ($(UNAME), Darwin)
    # mac
    CC = clang
else ifeq ($(UNAME), FreeBSD)
    # FreeBSD
    CC = clang
else
    # Linux and others...
    CC = gcc
    LFLAGS += -lbsd
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LFLAGS) $(LIBFT) $(MLX)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)/*.o
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
