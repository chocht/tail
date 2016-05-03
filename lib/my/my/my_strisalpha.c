/*
** my_strisalpha.c for sr_isalpha in /home/chauch_p/Repositories/Piscine_C_J06/ex_11
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue Oct  6 09:38:24 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:27:28 2016 Pierre Chauchoy
*/

int		my_str_isalpha(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] > 122 || str[i] < 65 || (str[i] < 97 && str[i] > 90))
      return (0);
  return (1);
}
