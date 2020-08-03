# include "minishell.h"

int ft_cd(char **args)
{
  if (args[1] == NULL)
    ft_putstr("minishell: expected argument to \"cd\"\n");
  else 
    if (chdir(args[1]) != 0)
      ft_putstr("minishell: No such file or directory\n");
  return 1;
}

int ft_env()
{
  int i;

  i = 0;
  while(environ[i] != NULL)
  {
    ft_putendl(environ[i]);
    i++;
  }
  return 1;
}

int ft_array_size(char **envp)
{
  int i;

  i = 0;
  while(envp[i] != NULL)
    i++;
  return i;
}

int ft_handle_setenv(char **args)
{
  (void)args;
  return 1;
}

int ft_setenv(char **args)
{
  /*
  int i;
  int envp_size;
  char **new_envp;

  envp_size = ft_array_size(envp);
  new_envp = (char **)malloc(sizeof(char *) * (envp_size + 1));
  i = 0;
  while(i < envp_size)
  {
    new_envp[i] = ft_strdup(envp[i]);
    free(envp[i]);
    i++;
  }
  new_envp[envp_size] = ft_strdup(args[1]);
  new_envp[envp_size + 1] = NULL;
  return new_envp;
  */
 setenv(args[1], args[2], 1);
 return 1;
}

void ft_handle_unsetenv(char *env)
{
  char **ep, **sp;
  size_t len;

  len = strlen(env);

  for (ep = environ; *ep != NULL; )
  {
    if (strncmp(*ep, env, len) == 0 && (*ep)[len] == '=')
    {
      for (sp = ep; *sp != NULL; sp++)
        *sp = *(sp + 1);
    }
    else
    {
      ep++;
    }
  }
}

int ft_unsetenv(char **args)
{
  ft_handle_unsetenv(args[1]);
  return 1;
}

int ft_exit()
{
  ft_putendl("exit");
  return 0;
}