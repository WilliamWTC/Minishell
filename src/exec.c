# include "minishell.h"

char *builtin_commands[] = {
  "help",
  "cd",
  "env",
  "echo",
  "setenv",
  "unsetenv",
  "clear",
  "exit",
};

int (*builtin_functions[]) (char **) = {
  &ft_help,
  &ft_cd,
  &ft_env,
  &ft_echo,
  &ft_setenv,
  &ft_unsetenv,
  &ft_clear,
  &ft_exit,
};

int num_builtins() {
  return sizeof(builtin_commands) / sizeof(char *);
}

int ft_help()
{
    int i;

    i = 0;
    ft_putendl("Minnishel, version 1.0.0.");
    ft_putendl("Functions allowed in Minishell:");
    ft_putendl("--------------------------------");
    while(i < num_builtins())
    {
        ft_putstr("-> ");
        ft_putendl(builtin_commands[i]);
        i++;
    }
    ft_putendl("--------------------------------");
    return 1;
}

int ft_execute(char **args)
{
  int i;

  if (args[0] == NULL)
    return 1;

  i = 0;
  while (i < num_builtins())
  {
    if(ft_strcmp(args[0], builtin_commands[i]) == 0)
      return (*builtin_functions[i])(args);
    i++;
  }
  return ft_launch(args);
}