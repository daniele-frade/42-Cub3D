NAME 	 = 	cub3D

CC 		 = 	cc
FLAGS	 = 	-Wall -Werror -Wextra -g -I. -I./$(INCDIR)

MLXFLAGS = 	-ldl -lglfw -pthread -lm

RM 		 = 	rm -rf
LIBFT 	 = 	libft/libft.a

SRCDIR 	 = 	src/

SRCS	 = 	$(addprefix $(SRCDIR),	data_validation_01.c \
									data_validation_02.c \
									data_validation_03.c \
									data_validation_04.c \
									data_validation_05.c \
									data_processing_01.c \
									data_processing_02.c \
									utils.c \
									main.c)

OBJDIR	 =	bin/
OBJS	 =	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

INCDIR	 =	includes/
INC		 =	$(INCDIR)cub3d.h

HIDE	 = @

all: MLX42/build/libmlx42.a $(OBJDIR) $(OBJS) $(LIBFT) $(NAME)

MLX42/build/libmlx42.a:
	cmake -B build
	cmake --build build -j4

$(LIBFT):
	$(HIDE)make -C ./libft --no-print-directory --silent

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)mkdir -p $(dir $@)
	$(HIDE)$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(HIDE) $(CC) $(OBJS) MLX42/build/libmlx42.a $(LIBFT) -I libft/headers -I MLX42/include $(FLAGS) $(MLXFLAGS) -o $@


$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)make -C libft clean --silent
	$(HIDE)$(RM) $(OBJDIR)

fclean: clean
	$(HIDE)make -C libft fclean --silent
	$(HIDE)$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
