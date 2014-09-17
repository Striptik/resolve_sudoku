/*
** my_alloc.c for allocation verifiee in /home/loisel_k/travail/Librairie/my
** 
** Made by kevin loiseleur
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Nov 14 16:51:53 2013 kevin loiseleur
** Last update Sun Nov 17 21:09:12 2013 kevin loiseleur
*/
#include <stdlib.h>
#include "my.h"

void			*alloc(int len)
{
  void			*obj;

  obj = malloc(len * sizeof(obj));
  if (obj == NULL)
    {
      write(2, "ERROR ON MALLOC !\n", my_strlen("ERROR ON MALLOC !\n"));
      return (NULL);
    }
  return (obj);
}
