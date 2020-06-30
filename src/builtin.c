# include "minishell.h"

int num_builtins() {
  char *builtin_str[] = {"cd","exit","echo"};
  return sizeof(builtin_str) / sizeof(char *);
}

int ft_cd(char **args)
{
  if (args[1] == NULL)
    ft_putstr("bash: expected argument to \"cd\"\n");
  else 
    if (chdir(args[1]) != 0)
      ft_putstr("bash: No such file or directory\n");
  
  return 1;
}

int ft_exit(char **args)
{
  if (*args)
    return 0;
  return 0;
}