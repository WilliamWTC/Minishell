# include "minishell.h"

static void	ft_echostr(const char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
	}
}

void	ft_search_env(char *var, char **envp)
{
	int i;
	char **env;

	i = 0;
	while(envp[i] != NULL)
	{
		env = ft_strsplit(envp[i], '=');
		if(ft_strcmp(var, env[0]) == 0)
			ft_putstr(env[1]);
		i++;
	}
}

char	**ft_echo(char **str, char **envp)
{
	int i;
	int j;
	char **var;

	i = 1;
	if (!str[1])
		ft_putstr("\n");
	else if(str[1][0] == '$')
	{
		var = ft_strsplit(str[1], '$');
		ft_search_env(var[0], envp);
		ft_putstr("\n");
	}
	else
	{	
		while (str[i])
		{
			j = -1;
			while (str[i][++j] != '\0')
			{
				if (str[i][j] == '\"')
					str[i][j] = 127;
			}
			ft_echostr(str[i++]);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
    return envp;
}