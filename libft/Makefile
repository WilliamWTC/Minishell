NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	  ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	  ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
	  ft_strstr.c ft_tolower.c ft_toupper.c ft_strlcat.c ls_paths.c \
	  ft_itoa.c	ft_putendl.c ft_putstr_fd.c ft_striteri.c ft_strnew.c \
	  ft_memalloc.c	ft_putendl_fd.c	ft_strclr.c	ft_strjoin.c ft_strsplit.c \
	  ft_memdel.c ft_putnbr.c ft_strdel.c ft_strmap.c ft_strsub.c \
	  ft_putchar.c ft_putnbr_fd.c ft_strequ.c ft_strmapi.c ft_strtrim.c \
	  ft_putchar_fd.c ft_isspace.c ft_putstr.c ft_striter.c ft_strnequ.c \

SRCS_PATH = srcs/
OBJ_PATH  = obj/
INC = -I ./inc/
FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(SRCS_PATH), $(SRC))
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re