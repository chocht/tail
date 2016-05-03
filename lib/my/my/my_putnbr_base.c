/*
** my_putnbr_base.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Thu Jan  7 10:53:20 2016 Pierre Chauchoy
** Last update Thu Jan  7 10:57:38 2016 Pierre Chauchoy
*/

void		my_putnbr_base(int nb, int base)
{
  if (nb > 9)
    my_putnbr_base(nb / base, base);
  if (nb % base > 9)
    my_putchar(nb % base + 55);
  else
    my_putchar(nb % base + 48);
}
