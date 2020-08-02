# include "minishell.h"

char **ft_cd(char **args, char **envp)
{
  if (args[1] == NULL)
    ft_putstr("minishell: expected argument to \"cd\"\n");
  else 
    if (chdir(args[1]) != 0)
      ft_putstr("minishell: No such file or directory\n");
  return envp;
}

char **ft_env(char **args, char **envp)
{
  int i;

  (void)args;
  i = 0;
  while(envp[i] != NULL)
  {
    ft_putendl(envp[i]);
    i++;
  }
  return envp;
}

char **ft_setenv(char **args, char **envp)
{
  (void)args;
  ft_putendl("Set env variable.");
  return envp;
}

int ft_numenv(char **envp)
{
  int i;

  i = 0;
  while(envp[i] != NULL)
    i++;
  return i;
}

char **ft_unsetenv(char **args, char **envp)
{
  int i;
  char **env;
  int size;
  int position = 0;

  size = ft_numenv(envp);
  if(args[1])
  {
    i = 0;
    while(envp[i] != NULL)
    {
      env = ft_strsplit(envp[i], '=');
      if(ft_strcmp(args[1], env[0]) == 0)
      {
        position = i + 1;
        break;
      }
      i++;
    }
  }
  if(position > 0)
  {
    i = position - 1;
    while(i < size - 1)
    {
      envp[i] = envp[i + 1];
      i++;
    }
  }
  return envp;
}