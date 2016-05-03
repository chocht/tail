/*
** parsing.c for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 12:06:02 2016 Pierre Chauchoy
** Last update Tue May  3 17:11:17 2016 Pierre Chauchoy
*/

#include <stdlib.h>
#include "tail.h"
#include "my.h"
#include "my_printf.h"

static int	short_parsing2(t_list *files, char **argv, int *i)
{
  if (my_strncmp(argv[*i], "-", 1) == 0)
    {
      my_fprintf(2, "tail : option invalide -- '%s'\n", &argv[*i][1]);
      my_fprintf(2, "Try 'tail --help' for more information.\n");
      return (1);
    }
  else if (add_list(files, argv[*i]))
    return (1);
  return (0);
}

static int	short_parsing(t_list *files, t_parsing *parsing,
			      char **argv, int *i)
{
  int		j;

  j = -1;
  while (parsing->short_args[++j] &&
	 my_strcmp(parsing->short_args[j], argv[*i]));
  if (parsing->args_short[j])
    {
      if (!argv[++(*i)])
	{
	  my_fprintf(2, "tail : l'option requiert un argument -- %s\n",
		     &argv[*i - 1][1]);
	  my_fprintf(2, "Try 'tail --help' for more information.\n");
	  return (1);
	}
      if (parsing->args_short[j](parsing, argv[*i]))
	return (1);
    }
  else
    if (short_parsing2(files, argv, i))
      return (1);
  return (0);
}

static int	long_parsing(t_list *files, t_parsing *parsing,
			     char **argv, int *i)
{
  int		j;
  int		len;

  j = -1;
  len = my_strlen(argv[*i]);
  while (parsing->long_args[++j] &&
	 (my_strncmp(parsing->long_args[j], argv[*i], len) == 0 ?
	  (parsing->long_args[j][len] != '=' ? 0 : 1) : 0) == 0);
  if (parsing->args_long[j])
    {
      if (parsing->args_long[j](parsing, argv[*i]))
	return (1);
    }
  else if (my_strncmp(argv[*i], "--", 2) == 0)
    {
      my_fprintf(2, "tail : option non reconnue << %s >>\n", argv[*i]);
      my_fprintf(2, "Try 'tail --help' for more information.\n");
      return (1);
    }
  else
    if (short_parsing(files, parsing, argv, i))
      return (1);
  return (0);
}

static int	simple_parsing(t_list *files, t_parsing *parsing,
			       char **argv, int *i)
{
  int		j;

  j = -1;
  while (parsing->simple_args[++j] &&
	 my_strcmp(parsing->simple_args[j], argv[*i]));
  if (parsing->args_simple[j])
    {
      if (parsing->args_simple[j](parsing))
	return (2);
    }
  else
    if (long_parsing(files, parsing, argv, i))
      return (1);
  return (0);
}

int		parsing(char **argv, t_tail *tail)
{
  int		i;
  int		ret;

  i = 0;
  while (argv[++i])
    {
      if ((ret = simple_parsing(&tail->files, &tail->parsing, argv, &i)) == 1)
	return (1);
      else if (ret == 2)
	break ;
    }
  return (0);
}
