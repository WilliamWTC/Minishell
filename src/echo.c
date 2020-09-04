#include "minishell.h"

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

void ft_old_pwd(char *s1, char *s2)
{
	char *var;
	char *oldpwd;

	oldpwd = ft_getenv("OLDPWD");
	if(oldpwd == NULL)
	{
    	var = (char *)malloc(sizeof(var) * (ft_strlen(s1) + ft_strlen(s2 + 2)));
    	ft_strcpy(var, s1);
    	ft_strcat(var, "=");
    	ft_strcat(var, s2);
    	ft_putenv(var);
	}
	else
		free(oldpwd);
    free(var);
}

int ft_new_pwd()
{
	int i;
	int environ_len;
	char cwd[1024];
	char *temp;
	int j;

	environ_len = ft_array_size(environ);
	j = 0;
	if(tmp_environ)
		j = 1;
	tmp_environ = (char **)malloc(sizeof(char *) * (environ_len + 1));
	i = 0;
	while(environ[i] != NULL)
	{
		if(ft_strncmp(environ[i], "OLDPWD", ft_strlen("OLDPWD")) == 0)
		{
			temp = ft_getenv("PWD");
			tmp_environ[i] = ft_strjoin("OLDPWD=", temp);
			free(temp);
		}
		else if (ft_strncmp(environ[i], "PWD", ft_strlen("PWD")) == 0)
			tmp_environ[i] = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
		else
			tmp_environ[i] = ft_strdup(environ[i]);
		i++;
	}
	tmp_environ[environ_len] = NULL;
	if (j)
		ft_free_double_char(environ);
	environ = tmp_environ;
	return 1;
}

int ft_putenv(char *s)
{
	int i;
	int environ_len;

	environ_len = ft_array_size(environ);
	tmp_environ = (char **)malloc(sizeof(char *) * (environ_len + 2));
	i = 0;
	while(environ[i] != NULL)
	{
		tmp_environ[i] = ft_strdup(environ[i]);
		i++;
	}
	tmp_environ[environ_len] = ft_strdup(s);
	tmp_environ[environ_len + 1] = NULL;
	environ = tmp_environ;
	return 1;
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