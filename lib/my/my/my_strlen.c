/*
** my_strlen.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 18:04:00 2015 Pierre Chauchoy
** Last update Mon Apr 11 03:03:43 2016 Pierre Chauchoy
*/

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}
