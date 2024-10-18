NAME = cub3D
INCLUDE = -I ./src/ -I $(LIBMLX)/include/MLX42

CFLAGS = -Wall -Werror -Wextra -g3

MLX = ./MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

LIBMLX = ./MLX42
MLXFLAGS = $(MLX) $(INCLUDE) -ldl -lglfw -pthread -lm

OBJ_DIR = ./obj

SOURCES	 = 	$(addprefix src/,	data_validation_01.c \
									data_validation_02.c \
									data_validation_03.c \
									data_validation_04.c \
									data_validation_05.c \
									data_processing_01.c \
									data_processing_02.c \
									error_and_free.c \
									getters.c \
									render.c\
									render_utils.c\
									move.c \
									raycasting.c \
									init.c \
									main.c)

OBJECTS = $(SOURCES:%.c=%.o)

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./includes/cub3D.h

$(LIBFT):
	make -C ./libft

$(MLX):
	cmake -S ./MLX42 -B ./MLX42/build -DDEBUG=1
	cmake --build ./MLX42/build -j4

libclean:
	@make clean -C ./libft --no-print-directory

libfclean: libclean
	@make fclean -C ./libft --no-print-directory

clean: libclean
	@rm -rf $(OBJECTS)

fclean: clean libfclean
	@cd ./MLX42/build && make clean --no-print-directory
	@rm -f $(NAME)

re: fclean all


mlxre:
	cmake --build ./MLX42/build --clean-first --no-print-directory

reall: fclean mlxre all

.PHONY: all clean fclean re mlxre reall libfclean libclean libft
# rodar com valgrind:
# valgrind --suppressions=codam.sup --leak-check=full --show-leak-kinds=all ./cub3D maps/...