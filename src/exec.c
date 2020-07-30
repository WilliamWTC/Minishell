# include "minishell.h"

int ft_execute(char **args, char **envp)
{
  int i;
  char *builtin_str[] = {"help", "cd", "env", "exit","echo"};
  int (*builtin_func[]) (char **, char **) = {&ft_help, &ft_cd, &ft_env, &ft_exit, &ft_echo};

  if (args[0] == NULL)
    return 1;

  i = 0;
  while (i < num_builtins())
  {
    if(ft_strcmp(args[0], builtin_str[i]) == 0)
    {
      return (*builtin_func[i])(args, envp);
    }
    i++;
  }

  return ft_launch(args, envp);
}