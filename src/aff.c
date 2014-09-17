/*
** aff.c for aff in /home/delafo_c/rendu/sudoki-bi/src
** 
** Made by delafo_c
** Login   <delafo_c@epitech.net>
** 
** Started on  Fri Feb 28 23:43:47 2014 delafo_c
** Last update Sun Mar  2 20:14:38 2014 delafo_c
*/

#include <term.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include "../include/my.h"
#include "../include/sudoku.h"

int		my_putcap(int cap)
{
  write(1, &cap, 1);
  return (0);
}

int		clean_term(void)
{
  char		*str;

  if (tgetent(NULL, "xterm") == -1)
    {
      my_printf("error: tgetent failed\n");
      return (-1);
    }
  if ((str = tgetstr("cl", NULL)) == NULL)
    {
      my_printf("error: tgetstr failed\n");
      return (-1);
    }
  if (tputs(str, 1, my_putcap) == -1)
    {
      my_printf("error: tputs failed\n");
      return (-1);
    }
  return (0);
}

void            aff_grids(char **grids)
{
  int           i;
  int           j;

  i = 0;
  aff_tab();
  while (i < 9)
    {
      my_printf("\033[1;31m|\033[0;m");
      j = 0;
      while (j < 9)
	{
	  my_printf("\033[1;33m %c\033[0;m", grids[i][j]);
          j++;
	}
      my_printf("\033[1;31m|\n\033[0;m");
      i++;
    }
  aff_tab();
}

void		aff_tab(void)
{
  my_printf("\033[1;31m|------------------|\n\033[0;m");
}

void		aff_delim(void)
{
  my_printf("\033[1;32m####################\n\033[0;m");
}
