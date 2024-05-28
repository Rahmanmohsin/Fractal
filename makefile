CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -ldl -lglfw -pthread -lm -lmlx42

NAME = fractal

SRCS = fractal.c fractal_utils.c errors.c mandelbrot.c events.c julia.c 

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFT_DIR = Libft

PRINTF = libftprintf.a
PRINTFT_DIR = FtPrintf

MLX = libmlx42.a
MLX_DIR = MLX42

all: $(NAME)

install_brew:
	@echo "----- installing brew -----"
	rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
	git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
	source $HOME/.zshrc && brew update
install_glfw:
	@echo "----- installing glfw -----"
	brew install glfw
install: install_brew install_glfw

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	make -sC $(PRINTFT_DIR)
	make -sC $(MLX_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(PRINTFT_DIR) -lftprintf -L$(MLX_DIR) -lmlx42 $(INCLUDE) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make -sC $(LIBFT_DIR) clean
	make -sC $(PRINTFT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(LIBFT_DIR) fclean
	make -sC $(PRINTFT_DIR) fclean
	make -sC $(MLX_DIR) fclean

re: fclean all