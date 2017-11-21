NAME = libft.a
CC = gcc
C_FLAGS = -c -Wall -Wextra -Werror
O_FLAGS = -Wall -Wextra -Werror -o
RM = rm -f
C_FILES =
O_FILES =

all: $(NAME)

$(NAME):
	$(CC) $(C_FLAGS) $(C_FILES)
	$(CC) $(O_FLAGS) $(NAME) $(O_FILES)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all
