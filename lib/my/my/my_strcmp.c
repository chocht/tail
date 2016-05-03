/*
** my_strcmp.c for lib in /home/chauch_p/librairie/lib/my/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Apr 11 18:24:54 2016 Pierre Chauchoy
** Last update Mon Apr 11 18:24:55 2016 Pierre Chauchoy
*/

int		my_strcmp(char *s1, char *s2)
{
  while (*s1 && (*s1 == *s2))
    {
      s1++;
      s2++;
    }
  return (*(unsigned char*)(s1) - *(unsigned char*)(s2));
}
