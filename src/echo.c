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

char *ft_getenv(char *s)
{
	size_t len;
	
	len = ft_strlen(s);
	for(int i = 0; environ[i] != NULL; i++)
	{
		if(ft_strncmp(environ[i], s, len) == 0)
			return ft_strsub(environ[i], len + 1, ft_strlen(environ[i]));
	}
	return 0;
}

int ft_putenv()
{
	return 0;
}

int	ft_echo(char **str)
{
	int i;
	int j;
	char *var;
	char *value;

	i = 1;
	if (!str[1])
		ft_putstr("\n");
	else if(str[1][0] == '$')
	{
		var = ft_strsub(str[1], 1, ft_strlen(str[1]));
		value = ft_getenv(var);
		ft_putendl(value);
		free(var);
		free(value);
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
    return 1;
}