# include "minishell.h"

int     ft_launch(char **args, char **envp)
{
    pid_t   pid;
    int     status;

    /*
    char *envp[] =
    {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        "TZ=UTC0",
        "USER=beelzebub",
        "LOGNAME=tarzan",
        NULL
    };
    */

    pid = fork();
    if(pid == 0)
    {
        if(execve(args[0], args, envp) == -1)
        {
            ft_putstr("minishell: command not found: ");
            ft_putendl(args[0]);
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
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}
