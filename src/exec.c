# include "minishell.h"

int ft_execute(char **args)
{
  int i;
  char *builtin_str[] = {"cd","exit","echo","setenv","unsetenv"};
  int (*builtin_func[]) (char **) = {&ft_cd, &ft_exit, &ft_echo};

  if (args[0] == NULL)
    return 1;

  i = 0;
  while (i < num_builtins())
  {
    if(ft_strcmp(args[0], builtin_str[i]) == 0)
      return (*builtin_func[i])(args);
    i++;
  }

  return ft_launch(args);
}