/*
** sudoku.h for sudoku header file in /home/loisel_k/Taff/C/C-Prog-Elem/B2/Rush2/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Mar  1 20:07:42 2014 Kevin LOISELEUR
** Last update Sun Mar  2 20:17:25 2014 delafo_c
*/

#ifndef _SUDOKU_H_
# define _SUDOKU_H_

# define TRUE		0
# define FALSE		1
# define NB_LINE	10
# define NB_GRID	10

/*
** PARSING
*/

char			**recup_maps(void);
int			recup_read(char **tab_map);
char			*analyse_line(char *s);
void			tab_copy(char *tmp, char **tab_map, int i);

/*
** DISPLAY
*/

void			aff_grids(char **grids);
void			aff_tab(void);
void			aff_delim(void);
int			my_putcap(int cap);
int			clean_term(void);

/*
** BACKTRACKING
*/

int			bt_check_grids(char **grids, int pos);
int			is_valid_number(char **grids, char c, int i, int j);
int			is_nb_in_line(char **grids, char c, int i);
int			is_nb_in_column(char **grids, char c, int j);
int			is_nb_in_square(char **grids, char c, int i, int j);

#endif /* _SUDOKU_H_ */
