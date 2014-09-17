/*
** recup_file.c for recup_file in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Rush2/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Mar  1 16:29:34 2014 Kevin LOISELEUR
** Last update Sun Mar  2 20:03:20 2014 delafo_c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/sudoku.h"

char		**recup_maps(void)
{
  int		yes;
  char		**map;

  yes = 0;
  if ((map = malloc(sizeof(char *) * NB_LINE)))
    {
      if ((yes = recup_read(map)) == 2)
	exit(1);
      else if (yes == 1)
	map[0] = NULL;
    }
  return (map);
}

int		recup_read(char **tab_map)
{
  char		*s;
  char		*tmp;
  int		yes;
  int		i;

  yes = 0;
  i = 0;
  while (yes < 2)
    {
      if (!(s = get_next_line(0)))
	return (1);
      else if (s[0] == '|' && s[1] == '-')
	(yes == 0) ? (yes = 1) : (yes = 2);
      else
	{
	  if (!(tmp = analyse_line(s)))
	    return (2);
	  tab_copy(tmp, tab_map, i);
	  i++;
	  free(tmp);
	}
      free(s);
    }
  tab_map[i] = NULL;
  return (0);
}

char		*analyse_line(char *s)
{
  int		i;
  char		*tmp;
  int		j;

  i = 1;
  j = 0;
  if (!(tmp = malloc(sizeof(char) * NB_GRID)))
    return (NULL);
  while (s[0] == '|' && s[i] && ((s[i] <= '9' && s[i] >= '1') || s[i] == ' '))
    {
      if (s[i] == ' ' && ((i % 2) == 0))
	tmp[j++] = '0';
      else if (s[i] <= '9' && s[i] >= '1')
	tmp[j++] = s[i];
      i++;
    }
  if (s[i] == '|')
    {
      tmp[j] = 0;
      return (tmp);
    }
  my_printf("Bad character in the map.\n");
  return (NULL);
}

void		tab_copy(char *tmp, char **tab_map, int i)
{
  int		j;

  j = 0;
  if (!tmp || !tab_map)
    exit(-1);
  if (!(tab_map[i] = malloc(sizeof(char *) * NB_GRID)))
    exit (-1);
  while (tmp[j])
    {
      tab_map[i][j] = tmp[j];
      j++;
    }
  return ;
}
