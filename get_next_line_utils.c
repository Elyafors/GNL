#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
size_t n;

n = 0;
while (str[n])
  n++;
return (n);
}

char *ft_strchr(const char *s, int c)// поиск первого вхождения символа
{
  size_t i;
  size_t n;
  char *str;

  i = 0;
  n = ft_strlen((char *)s);
  str = (char *)s;
  if (c == '\0')
    return (&str[i]);
  while ( i <= n)
  {
    if (str[i] == c)
      return (&str[i]);
    i++;
  }
  return (0);
}

char *ft_strdup(char const *s) // дублирование строк с выделением памяти под новую строку
{
size_t i;
char *str;

i = ft_strlen(s);
if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
return (0);
while (*s != '\0')
{
*str = *s;
s++;
str++;
}
*str = '\0';
str = str - i;
return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc((len + 1) * sizeof(char))))
			return (0);
		while (*s1 != '\0')
			str[i++] = *s1++;
		while (*s2 != '\0')
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}