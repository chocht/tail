/*
** my_str_to_wordtab.c for lib in /home/chauch_p/librairie/lib/my
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Mon Nov 16 18:09:26 2015 Pierre Chauchoy
** Last update Wed Mar 16 11:20:24 2016 Pierre Chauchoy
*/

#include <stdlib.h>

int		difference_c_l(char c, char *letters)
{
  int		i;

  i = -1;
  while (letters[++i] != c && letters[i] != '\0');
  if (letters[i] != '\0')
    return (1);
  return (0);
}

int		size_height(char *s, char *letters)
{
  int		i;
  int		height;

  i = 0;
  height = 0;
  while (difference_c_l(s[i], letters))
    i = i + 1;
  while (s[i] != '\0')
    {
      while (difference_c_l(s[i], letters) == 0 && s[i] != '\0')
	i = i + 1;
      height++;
      while (difference_c_l(s[i], letters))
	i = i + 1;
    }
  return (height);
}

int		size_width(char *s, int *i, char *letters)
{
  int		width;
  int		x;

  width = 0;
  while (difference_c_l(s[*i], letters))
    *i = *i + 1;
  x = *i - 1;
  while (difference_c_l(s[++x], letters) == 0 && s[x] != '\0')
    width++;
  return (width);
}

int		fill_lines_of_tab(char **tab, char *s, int height,
				  char *letters)
{
  int		x;
  int		y;
  int		i;
  int		width;

  y = -1;
  i = 0;
  while (++y < height)
    {
      x = -1;
      width = size_width(s, &i, letters);
      if (!(tab[y] = malloc(sizeof(char) * (width + 1))))
	return (1);
      while (++x < width)
	tab[y][x] = s[i++];
      tab[y][x] = '\0';
    }
  tab[y] = NULL;
  return (0);
}

char		**my_str_to_wordtab(char *s, char *letters)
{
  char		**tab;
  int		height;

  height = size_height(s, letters);
  if (!(tab = malloc(sizeof(char*) * (height + 1))))
    return (NULL);
  if (fill_lines_of_tab(tab, s, height, letters))
    return (NULL);
  return (tab);
}
