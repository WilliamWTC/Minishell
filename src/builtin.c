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

int ft_setenv(char **args)
{
  /*
  char *es;

  ft_unsetenv(args);
  es = ft_memalloc(strlen(args[1]) + strlen(args[2]) + 2);
  ft_strcpy(es, args[1]);
  ft_strcat(es, "=");
  ft_strcat(es, args[2]);
  putenv(es);
  return 1;
  */
  int i;
  int environ_len;
  char **env;

  environ_len = ft_array_size(environ);
  env = (char **)malloc(sizeof(char *) * (environ_len + 1));
  i = 0;
  while(environ[i] != NULL)
  {
    env[i] = ft_strdup(environ[i]);
    i++;
  }
  env[environ_len] = ft_strdup(args[1]);
  env[environ_len + 1] = NULL;
  environ = env;
  return 1;
}

int ft_unsetenv(char **args)
{
  char **ep;
  char **sp;
  int len;

  len = (int)ft_strlen(args[1]);

  ep = environ;
  while(*ep != NULL)
  {
    if (ft_strncmp(*ep, args[1], len) == 0 && (*ep)[len] == '=')
      for (sp = ep; *sp != NULL; sp++)
        *sp = *(sp + 1);
    else
      ep++;
  }
  return 1;
}

int ft_exit()
{
  ft_putendl("exit");
  return 0;
}