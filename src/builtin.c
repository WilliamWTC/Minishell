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
    ft_putendl((char *)environ[i]);
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
  char *var;

  if (!args[1] || !args[2])
    ft_putendl("Minishel: setenv format, setenv VARIABLE VALUE");
  else
  {
    var = (char *)malloc(sizeof(var) * (ft_strlen(args[1]) + ft_strlen(args[2] + 2)));
    ft_strcpy(var, args[1]);
    ft_strcat(var, "=");
    ft_strcat(var, args[2]);
    ft_putenv(var);
    free(var);
  }
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

int ft_clear()
{
  ft_putstr("\e[1;1H\e[2J");
  return 1;
}

int ft_exit()
{
  if(tmp_fd)
    free(tmp_fd);
  if(tmp_environ)
    ft_free_double_char(tmp_environ);
  ft_putendl("exit");
  return 0;
}