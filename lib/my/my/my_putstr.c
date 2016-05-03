/*
** my_putstr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 17:20:28 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:23:23 2016 Pierre Chauchoy
*/

int		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
  return (0);
}
