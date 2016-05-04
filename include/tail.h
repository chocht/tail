/*
** tail.h for tail in /home/chauch_p/Repositories/tail
** 
** Made by Pierre Chauchoy
** Login   <chauch_p@epitech.net>
** 
** Started on  Tue May  3 10:29:26 2016 Pierre Chauchoy
** Last update Wed May  4 09:03:58 2016 Pierre Chauchoy
*/

#ifndef TAIL_H_
# define TAIL_H_

# define DEFAULT_LINES	10

# define HELP		"--help"
# define VERB_1		"-v"
# define VERB_2		"--verbose"
# define NB_SIMPLE_ARGS	3

# define BYTES_SHORT	"-c"
# define LINES_SHORT	"-n"
# define NB_SHORT_ARGS	2

# define BYTES_LONG	"--bytes"
# define LINES_LONG	"--lines"
# define NB_LONG_ARGS	2

typedef struct		s_elem
{
  char			*file;
  struct s_elem		*prev;
  struct s_elem		*next;
}			t_elem;

typedef struct		s_list
{
  int			len;
  struct s_elem		*head;
  struct s_elem		*tail;
}			t_list;

typedef struct		s_parsing
{
  char			*simple_args[NB_SIMPLE_ARGS + 1];
  char			*short_args[NB_SHORT_ARGS + 1];
  char			*long_args[NB_LONG_ARGS + 1];
  int			(*args_simple[NB_SIMPLE_ARGS + 1])(struct s_parsing*);
  int			(*args_short[NB_SHORT_ARGS + 1])(struct s_parsing*, char*);
  int			(*args_long[NB_LONG_ARGS + 1])(struct s_parsing*, char*);
  int		        starting_line;
  int			lines;
  int			bytes;
  int			verbose;
  int			index;
}			t_parsing;

typedef struct		s_tail
{
  t_list		files;
  t_parsing		parsing;
  int			(*parsing_func[2])(t_list*, t_parsing);
}			t_tail;

/*
** tail
*/

int			disp_with_lines(t_list*, t_parsing);
int			disp_with_bytes(t_list*, t_parsing);
int			loop_disp(t_tail*);
int			my_tail(char**);

/*
** parsing
*/

int			parsing(char**, t_tail*);

int			p_verb(t_parsing*);
int			p_help(t_parsing*);

int			p_bytes(t_parsing*, char*);
int			p_lines(t_parsing*, char*);

int			p_bytes_l(t_parsing*, char*);
int			p_lines_l(t_parsing*, char*);

int			disp_lines(t_list*);
int			disp_bytes(t_list*);

/*
** list
*/

void			swap_elem(t_list*, t_elem*, t_elem*);
void			init_list(t_list*);
void			show_list(t_list*);
int			add_list(t_list*, char*);
int			free_list(t_list*);

#endif /* !TAIL_H_ */
