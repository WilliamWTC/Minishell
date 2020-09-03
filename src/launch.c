# include "minishell.h"

int     ft_launch(char **args)
{
    pid_t   pid;
    int     status;
    char    *temp;

    pid = fork();
    if(pid == 0)
    {
        if ((temp = ft_getenv("PATH")) && ft_strncmp("/bin/", args[0], 5)){
            free(temp);
            temp = ft_strjoin("/bin/", args[0]);
            if(execve(temp, args, environ) == -1)
            {
                free(temp);
                ft_putstr("minishell: command not found: ");
                ft_putendl(args[0]);
            }
        }else{
            free(temp);
            if(execve(args[0], args, environ) == -1)
            {
                ft_putstr("minishell: command not found: ");
                ft_putendl(args[0]);
            }
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0)
    {
        ft_putendl("minishell: fork: process creation failed!");;    
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}
