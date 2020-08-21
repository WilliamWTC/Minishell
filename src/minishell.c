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
  char **cmd;
  int i;

  signal(SIGINT, sigintHandler);
  status = 1;
  while (status)
  {
    ft_putstr("\033[1m\033[34mminishell $> \033[0m");
    line = ft_gnl();
    i = 0;
    cmd = ft_strsplit(line, ';');
    while(cmd[i] != NULL)
    {
      args = ft_split(cmd[i]);
      status = ft_execute(args);
      ft_free_double_char(args);
      i++;
    }
    free(line);
    ft_free_double_char(cmd);
  }
  return 0;
}