/*
** backtracking.c for backtracking in /home/delafo_c/rendu/sudoki-bi/src
** 
** Made by delafo_c
** Login   <delafo_c@epitech.net>
** 
** Started on  Sat Mar  1 05:23:22 2014 delafo_c
** Last update Sun Mar  2 20:20:20 2014 delafo_c
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/sudoku.h"

int		is_valid_number(char **grids, char c, int i, int j)
{
  int		ret;

  ret = 0;
  ret = ((is_nb_in_line(grids, c, i)) + (is_nb_in_column(grids, c, j))
	 + (is_nb_in_square(grids, c, i, j)));
  if (ret == TRUE)
    return (TRUE);
  return (FALSE);
}

int		is_nb_in_line(char **grids, char c, int i)
{
  int		j;

  j = 0;
  while (j < 9)
    {
      if (grids[i][j] == c)
        return (FALSE);
      j++;
    }
  return (TRUE);
}

int		is_nb_in_column(char **grids, char c, int j)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      if (grids[i][j] == c)
        return (FALSE);
      i++;
    }
  return (TRUE);
}


int		is_nb_in_square(char **grids, char c, int i, int j)
{
  int		line;
  int		column;

  line = i - (i%3);
  column = j - (j%3);
  i = line;
  j = column;
  while (i < (line + 3))
    {
      while (j < (column + 3))
        {
          if (grids[i][j] == c)
            return (FALSE);
          j++;
        }
      i++;
    }
  return (TRUE);
}

int		bt_check_grids(char **grids, int pos)
{
  int		i;
  int		j;
  char		c;

  c = '1';
  i = pos / 9;
  j = pos % 9;
  if (pos == 81)
    return (TRUE);
  if (grids[i][j] != '0')
    return (bt_check_grids(grids, pos + 1));
  while (c <= '9')
    {
      if (is_valid_number(grids, c, i, j) == TRUE)
	{
          grids[i][j] = c;
          if (bt_check_grids(grids, pos + 1) == TRUE)
            return (TRUE);
	}
      c++;
    }
  grids[i][j] = '0';
  return (FALSE);
}
