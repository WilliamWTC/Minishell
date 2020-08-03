# include "minishell.h"

int main()
{
  char *line;
  char **args;
  int status;

  status = 1;
  while (status)
  {
    ft_putstr("\033[1m\033[34mminishell $> \033[0m");
    line = ft_gnl();
    args = ft_split(line);
    free(line);
    status = ft_execute(args);

    ft_strdel(args);
  }
  return EXIT_SUCCESS;
}