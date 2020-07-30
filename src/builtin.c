# include "minishell.h"

char *builtin_str[] = {"help", "cd", "env", "setenv","exit","echo"};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int     ft_help(char **args, char **envp)
{
    int i;

    i = 0;
    (void)args;
    (void)envp;
    ft_putendl("Type program names and arguments.");
    ft_putendl("The following are built in:");
    while(i < num_builtins())
    {
        ft_putstr(" ");
        ft_putendl(builtin_str[i]);
        i++;
    }
    return (1);
}

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
  return 1;
}

int ft_exit()
{
  return 0;
}