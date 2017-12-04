SRC_PATH = srcs
NAME = fillit
CC = gcc
C_FLAGS = -c -Wall -Wextra -Werror
O_FLAGS = -Wall -Wextra -Werror -o
RM = rm -f
SRC_NAME = parsing.c \
		   map.c \
		   lst.c \
		   solver.c \
		  main.c \
		  Libft/ft_bzero.c \
		  Libft/ft_putstr.c \
		  Libft/ft_putchar.c \
		  Libft/ft_memset.c \
		  Libft/ft_memalloc.c \
		  Libft/ft_isalpha.c \
		  Libft/ft_memdel.c \
		  Libft/ft_strnew.c
O_FILES = parsing.o \
		  map.o \
		  lst.o \
		  solver.o \
		  main.o \
		  ft_bzero.o \
		  ft_putstr.o \
		  ft_putchar.o \
		  ft_memset.o \
		  ft_memalloc.o \
		  ft_isalpha.o \
		  ft_memdel.o \
		  ft_strnew.o
all: $(NAME)

$(NAME) :
	$(CC) $(C_FLAGS) $(SRC_NAME)
	$(CC) $(O_FLAGS) $(NAME) $(O_FILES)

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
