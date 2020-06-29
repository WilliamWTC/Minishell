# include "minishell.h"

int main(void)
{
  char *line;
  char **args;
  int status;

  while (status)
   {
    ft_putstr("$ ");
    line = ft_gnl();
    // add_history(line);
    args = ft_split(line);
    free(line);
    status = ft_execute(args);

    ft_strdel(args);
  }
  return EXIT_SUCCESS;
}

