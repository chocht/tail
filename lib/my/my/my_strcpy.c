/*
** my_strcpy.c for copystring in /home/chauch_p/Repositories/Piscine_C_J06
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Oct  5 10:58:56 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:21:26 2016 Pierre Chauchoy
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = -1;
  while (src[++i] != '\0')
    dest[i] = src[i];
  return (dest);
}
