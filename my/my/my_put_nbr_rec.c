/*
** my_put_nbr_rec.c for my_put_nbr_rec.c in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 09:56:41 2013 loisel_k
** Last update Wed Oct  9 10:02:18 2013 loisel_k
*/

int		my_put_nbr_rec(int nb)
{
  int		u;
  int		d;

  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  u = nb % 10;
  d = nb / 10;
  if (d)
    my_put_nbr_rec(d);
  my_putchar('0' + u);
}
