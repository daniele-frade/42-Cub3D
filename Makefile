NAME 	= 	cub3D

CC 		= 	cc
FLAGS 	= 	-Wall -Werror -Wextra -g -I. -I./$(INCDIR)

MLXFLAGS = 	-ldl -lglfw -pthread -lm

RM 		= 	rm -rf
LIBFT 	= 	libft/libft.a

SRCDIR 	= 	src/

SRCS	= 	$(SRCDIR)main.c \

OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

INCDIR	=	includes/
INC		=	$(INCDIR)cub3d.h

all: MLX42/build/libmlx42.a $(OBJDIR) $(OBJS) $(LIBFT) $(NAME)

MLX42/build/libmlx42.a:
	cmake -B build
	cmake --build build -j4

$(LIBFT):
	$(HIDE)make -C ./libft --no-print-directory

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)mkdir -p $(dir $@)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(HIDE) $(CC) $(OBJS) MLX42/build/libmlx42.a $(LIBFT) -I libft/headers -I MLX42/include $(CFLAGS) $(MLXFLAGS) -o $@


$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)make -C libft clean
	$(HIDE)$(RM) $(OBJDIR)

fclean: clean
	$(HIDE)make -C libft fclean
	$(HIDE)$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
