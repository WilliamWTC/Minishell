# include "minishell.h"

int main(int argc, char **argv, char **envp)
{
  char *line;
  char **args;
  int status;

  if(argc < 1)
    return (-1);
  (void)argv;
  status = 1;
  while (status)
  {
    ft_putstr("$> ");
    line = ft_gnl();
    args = ft_split(line);
    free(line);
    status = ft_execute(args, envp);

    ft_strdel(args);
  }
  return EXIT_SUCCESS;
}

