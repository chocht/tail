/*
** my_power_rec.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 17:19:53 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:22:50 2016 Pierre Chauchoy
*/

int		rec(int nb, int power, int i, int temp)
{
  if (i >= power)
    return (nb);
  nb = nb * temp;
  i = i + 1;
  rec(nb, power, i, temp);
  return (rec(nb, power, i, temp));
}

int		my_power_rec(int nb, int power)
{
  int		temp;

  temp = nb;
  if (power == 0 && nb != 0)
    return (1);
  else if (power < 0)
    return (0);
  else
    return (rec(nb, power, 1, temp));
}
