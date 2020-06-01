# include "minishell.h"

static void	ft_echostr(const char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isprint(str[i]))
			write(1, &str[i], 1);
	}
}

int		ft_echo(char **str)
{
	int i;
	int j;

	i = 1;
	if (!str[1])
		ft_putstr("\n");
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

    return 1;
}