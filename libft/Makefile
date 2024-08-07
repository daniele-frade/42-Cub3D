NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -I headers

SRC =	./src/get_next_line/get_next_line.c \
		./src/get_next_line/get_next_line_utils.c \
		./src/printf/printf.c \
		./src/printf/printf_utils.c \
		./src/ft_isalpha.c \
		./src/ft_isdigit.c \
		./src/ft_isalnum.c \
		./src/ft_isascii.c \
		./src/ft_isprint.c \
		./src/ft_strlen.c \
		./src/ft_memset.c \
		./src/ft_bzero.c \
		./src/ft_memcpy.c \
		./src/ft_memmove.c \
		./src/ft_strlcpy.c \
		./src/ft_strlcat.c \
		./src/ft_toupper.c \
		./src/ft_tolower.c \
		./src/ft_strchr.c \
		./src/ft_strrchr.c \
		./src/ft_strncmp.c \
		./src/ft_memchr.c \
		./src/ft_memcmp.c \
		./src/ft_strnstr.c \
		./src/ft_atoi.c \
		./src/ft_calloc.c \
		./src/ft_strdup.c \
		./src/ft_substr.c \
		./src/ft_putchar_fd.c \
		./src/ft_putstr_fd.c \
		./src/ft_putendl_fd.c \
		./src/ft_putnbr_fd.c \
		./src/ft_strjoin.c \
		./src/ft_strtrim.c \
		./src/ft_striteri.c \
		./src/ft_strmapi.c \
		./src/ft_itoa.c \
		./src/ft_split.c 

SRC_BONUS =		./src/ft_lstnew_bonus.c \
				./src/ft_lstadd_front_bonus.c \
				./src/ft_lstsize_bonus.c \
				./src/ft_lstlast_bonus.c \
				./src/ft_lstadd_back_bonus.c \
				./src/ft_lstdelone_bonus.c \
				./src/ft_lstclear_bonus.c \
				./src/ft_lstiter_bonus.c \
				./src/ft_lstmap_bonus.c

OBJECTS = $(SRC:./src/%.c=./objects/%.o)

BONUS_OBJECTS = $(SRC_BONUS:./src/%.c=./objects/%.o)

$(NAME): mkdir $(OBJECTS)

all: mkdir $(NAME)

objects/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< $(INCLUDE) -o $@
	ar -rsc $(NAME) $@

mkdir:
	mkdir -p objects
	mkdir -p objects/printf
	mkdir -p objects/get_next_line

bonus: mkdir $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS) -r objects

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re