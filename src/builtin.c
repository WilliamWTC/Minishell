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
    if(ft_strcmp(envp[i], " ") != 0)
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

char **ft_unsetenv(char **args, char **envp)
{
  int i;
  char **env;

  i = 0;
  while(envp[i] != NULL)
  {
    env = ft_strsplit(envp[i], '=');
		if(ft_strcmp(args[1], env[0]) == 0)
			ft_strcpy(envp[i], " ");
		i++;
  }
  return envp;
}