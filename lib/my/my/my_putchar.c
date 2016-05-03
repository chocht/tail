/*
** my_putchar.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 17:20:02 2015 Pierre Chauchoy
** Last update Mon Feb 15 16:22:56 2016 Pierre Chauchoy
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
