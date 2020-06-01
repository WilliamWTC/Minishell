# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>

char   *ft_gnl();
char   **ft_split();
int    get_next_line();

int    ft_cd();
int    ft_exit();
int    ft_echo();
int    num_builtins();

int    ft_launch();
int    ft_execute();