# include "minishell.h"

char *builtin_str[] = {
  "help",
  "cd",
  "env",
  "unsetenv",
  "setenv",
  "echo"
};

int (*builtin_func[]) (char **, char **) = {
  &ft_help,
  &ft_cd,
  &ft_env,
  &ft_setenv,
  &ft_unsetenv,
  &ft_echo
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int     ft_help(char **args, char **envp)
{
    int i;

    (void)args;
    (void)envp;
    i = 0;
    ft_putendl("Minnishel, version 1.0.0.");
    ft_putendl("The following are built in:");
    ft_putstr("\n");
    while(i < num_builtins())
    {
        ft_putstr(" ");
        ft_putendl(builtin_str[i]);
        i++;
    }
    return (1);
}

int ft_execute(char **args, char **envp)
{
  int i;
  int res;
  char **new_envp;

  if (args[0] == NULL)
    return 1;

  i = 0;
  while (i < num_builtins())
  {
    if(ft_strcmp(args[0], "exit") == 0)
    {
      ft_putendl("exit");
      return 0;
    }
    else if(ft_strcmp(args[0], builtin_str[i]) == 0)
    {
      res = (*builtin_func[i])(args, envp);
      ft_putnbr(res);
      ft_putstr("\n");
      return res;
    }
    i++;
  }
  return ft_launch(args, envp);
}