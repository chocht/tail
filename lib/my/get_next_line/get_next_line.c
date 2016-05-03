/*
** read_and_display_line_read_1.c for getnextline in /home/chauch_p/Repositories/CPE/CPE_2015_getnextline_bootstrap
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu Jan  7 16:11:21 2016 Pierre Chauchoy
** Last update Mon Apr 11 18:11:48 2016 Pierre Chauchoy
*/

#include <unistd.h>
#include <stdlib.h>

static char	*my_strcat_read(char *line, char rd)
{
  char		*tmp;
  static int	len = 0;
  int		i;

  if (!(tmp = malloc(sizeof(char) * (len + 2))))
    return (NULL);
  i = -1;
  len++;
  while (line[++i] != '\0')
    tmp[i] = line[i];
  tmp[i++] = rd;
  tmp[i++] = '\0';
  free(line);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  char		rd;
  char		*line;
  static int	len = 1;

  if (!(line = malloc(sizeof(char) * 1)))
    return (NULL);
  line[0] = '\0';
  while (1)
    {
      if ((len = read(fd, &rd, 1)) < 0)
	return (NULL);
      if (len == 0 && line[0] == '\0')
	{
	  free(line);
	  return (NULL);
	}
      if (len == 0 || rd == '\n')
	return (line);
      if (!(line = my_strcat_read(line, rd)))
	return (NULL);
    }
  return (NULL);
}
