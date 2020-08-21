# include "minishell.h"

void ft_free_double_char(char **ss)
{
  int i;

  i = 0;
  while(ss[i] != 0)
  {
    free(ss[i]);
    i++;
  }
  free(ss);
}

void sigintHandler() 
{
    signal(SIGINT, sigintHandler);
    ft_putstr("\n");
    ft_putstr("\033[1m\033[34mminishell $> \033[0m");
}

int main()
{
  char *line;
  char **args;
  int status;

  signal(SIGINT, sigintHandler);
  status = 1;
  while (status)
  {
    ft_putstr("\033[1m\033[34mminishell $> \033[0m");
    line = ft_gnl();
    args = ft_split(line);
    status = ft_execute(args);
    free(line);
    ft_free_double_char(args);
  }
  return 0;
}