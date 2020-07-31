# include "minishell.h"

int ft_cd(char **args, char **envp)
{
  (void)envp;
  if (args[1] == NULL)
    ft_putstr("minishell: expected argument to \"cd\"\n");
  else 
    if (chdir(args[1]) != 0)
      ft_putstr("minishell: No such file or directory\n");
  return 1;
}

int ft_env(char **args, char **envp)
{
  int i;

  (void)args;
  i = 0;
  while(envp[i] != NULL)
  {
    ft_putendl(envp[i]);
    i++;
  }
  return 1;
}

int ft_setenv(char **args, char **envp)
{
  (void)args;
  (void)envp;
  ft_putendl("Set env variable.");
  return 1;
}

int ft_unsetenv(char **args, char **envp)
{
  (void)args;
  (void)envp;
  ft_putendl("Unset env variable.");
  return 1;
}