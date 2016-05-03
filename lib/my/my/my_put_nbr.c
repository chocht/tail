/*
** my_put_nbr.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu Jan  7 11:03:19 2016 Pierre Chauchoy
** Last update Mon Feb 15 16:23:05 2016 Pierre Chauchoy
*/

void		my_put_nbr(int nb)
{
  int		l;

  l = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  nb = -2147483647;
	  l = 1;
	}
      nb = -nb;
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48 + l);
}
