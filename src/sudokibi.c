/*
** sudokibi.c for sudokibi in /home/delafo_c/rendu/sudoki-bi/src
** 
** Made by delafo_c
** Login   <delafo_c@epitech.net>
** 
** Started on  Fri Feb 28 23:25:35 2014 delafo_c
** Last update Sun Mar  2 20:20:49 2014 delafo_c
*/

#include "../include/sudoku.h"

int		main(int ac, char **av)
{
  int		yes;
  int		beg;
  char		**map;

  yes = 0;
  beg = 0;
  clean_term();
  while (!yes)
    {
      map = recup_maps();
      if (!(map[0]))
        return (0);
      if (beg != 0)
        aff_delim();
      bt_check_grids(map, 0);
      aff_grids(map);
      beg++;
    }
  return (0);
}
