/*
** my_atoi_base.c for exam in /home/exam/rendu/ex_4
** 
** Made by Exam User
** Login   <exam@epitech.net>
** 
** Started on  Sat Apr  9 09:52:39 2016 Exam User
** Last update Tue Apr 12 02:21:33 2016 Pierre Chauchoy
*/

int		pos_in_base(char *s, char c)
{
  int		i;

  i = -1;
  while (s[++i] && s[i] != c);
  if (!(s[i]))
    return (-1);
  return (i);
}

int		my_getnbr_base(char *str, char *base)
{
  int		len;
  int		nb;
  int		i;
  int		dec;
  int		pos;

  len = my_strlen(base);
  nb = 0;
  i = my_strlen(str);
  dec = 1;
  while (--i >= 0)
    {
      if (str[i] == '-')
	return (-nb);
      if ((pos = pos_in_base(base, str[i])) == -1)
	return (-1);
      nb += pos * dec;
      dec *= len;
    }
  return (nb);
}
