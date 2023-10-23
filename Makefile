INCFLAGS = /opt/X11/include/X11/
UNAME := $(shell uname)
LIBFT = libft/libft.a
MLX = minilibx/libmlx_Darwin.a
CFLAGS = -Wall -Wextra -Werror
NAME = mlx-test
SRCS = visual.c \
    handle_window_funcs.c \
    mandel.c \
    julia.c \
    color_hand.c\
    key_treat.c\
    error_hand.c\
    atod.c\
    treat_sets.c\
    set_rgb.c\

OBJ_DIR = fractol_obj
OBJS = $(SRCS:.c=.o)
# OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

INCLUDE = /opt/X11/include/X11

LFLAGS = -I libft -L libft -lft \
         -I $(INCFLAGS) \
         -I /usr/local/include -L /usr/local/lib  \
         -L ./minilibx -l mlx -framework OpenGL -framework Appkit -L/opt/X11/lib -lX11

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

# オブジェクトファイルつくる時-lのフラグはつけない。実行ファイルをつくる時つける。
#  LDFLAGSで-Lでライブラリを入れる。そうするとわかりやすい。LDFLAGS += で追加できる
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
