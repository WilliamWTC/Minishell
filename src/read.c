# include "minishell.h"

static int     ft_invalid(char c)
{
    if(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\a')
        return (1);
    return (0);
}

char	**ft_split(const char *s)
{
	char	**ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !(ret = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_invalid(s[i]))
			i++;
		else
		{
			len = 0;
			while (s[len + i] && !ft_invalid(s[len + i]))
				len++;
			ret[j++] = ft_strsub(s, i, len);
			i += len;
		}
	}
	ret[j] = 0;
	return (ret);
}

char    *ft_gnl()
{
	int ret;
	char *buff;

	if ((ret = get_next_line(0, &buff)) > 0)
    	return (buff);
	return (0);
}