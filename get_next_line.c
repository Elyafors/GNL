#include "get_next_line.h"

void  check_remainder(char **remainder, char ***line, char **p_n)
{
  char  *tmp;

  if ((*p_n=ft_strchr(*remainder,'\n')))
  {
    **p_n = '\0';
    tmp = **line;
    **line = ft_strjoin(**line, *remainder);
    free(tmp);
    tmp = *remainder;
    *remainder = ft_strdup(++(*p_n));
    free(tmp);
  }
  else
  {
    tmp = **line;
     **line = ft_strjoin(**line, *remainder);
     free(tmp);
    tmp = *remainder;
    *remainder = NULL;
     free(tmp);
   }
}

int  cheking(int b_w_r, char *p_n)
{
  if (b_w_r == -1)
   return(-1);
  if(p_n)
   return (1);
  return(0);
}
int		get_next_line(int fd, char **line)
{
  //int BUFFER_SIZE = 32;
  char			buf[BUFFER_SIZE + 1];
  int			b_w_r;
  char			*p_n;
  static char	*remainder;
  char			*tmp;

  b_w_r = 0;
  p_n = NULL;
 
  if (!line || fd < 0 || BUFFER_SIZE < 1 || !(*line = ft_strdup("\0")))
		return (-1);
  *line[0] = 0;
  if (remainder)
    check_remainder(&remainder, &line, &p_n);
  while (!p_n && (b_w_r = read(fd, buf, BUFFER_SIZE)))
  {
    buf[b_w_r] = '\0';
    if ((p_n = ft_strchr(buf, '\n'))) 
    {
      *p_n = '\0';
      tmp = remainder;
      remainder = ft_strdup(++p_n);
      free(tmp);
    }
    tmp = *line;
    *line = ft_strjoin(*line, buf);
    free(tmp);
  }
  return (cheking(b_w_r, p_n));
}