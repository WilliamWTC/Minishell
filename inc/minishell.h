# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"

char   *ft_gnl();
char   **ft_split();
int    get_next_line();

char    **ft_help();
char    **ft_cd();
char    **ft_env();
char    **ft_setenv();
char    **ft_unsetenv();
char    **ft_echo();
int    num_builtins();

int    ft_launch();
int    ft_execute();