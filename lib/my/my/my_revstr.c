/*
** my_revstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 17:20:37 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:23:33 2016 Pierre Chauchoy
*/

char		*my_revstr(char *str)
{
  char		c;
  int		i;
  int		j;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i = i + 1;
      j = j - 1;
    }
  return (str);
}
