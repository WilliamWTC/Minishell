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
	free(buff);
	return (0);
}

/*
char    *ft_gnl()
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
		return 0;

  	while (1) {
    	// Read a character
    	c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += 1024;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  free(buffer);
}
*/