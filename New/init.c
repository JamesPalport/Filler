#include "filler.h"

void	init_all(t_all *all)
{
	all->map = NULL;
	all->piece = NULL;
	all->score = NULL;
	all->size_map[0] = 0;
	all->size_map[1] = 0;
	all->size_piece[0] = 0;
	all->size_piece[1] = 0;
	all->letter = 0;
	all->nb_sqr = 0;
	all->extr_x[0] = -1;
	all->extr_x[1] = -1;
	all->extr_y[0] = -1;
	all->extr_y[1] = -1;
	all->cm_ene[0] = 0;
	all->cm_ene[1] = 0;
	all->cm_ene[2] = 0;
	all->pos[0] = -10;
	all->pos[1] = -10;
	all->end = 0;
}

void	begin_prog(t_all *all, int fd)
{
	char	*tmp;

	get_next_line(fd, &tmp);
	if (ft_strncmp(tmp, "$$$ exec p", 10))
		exit(0);
	if (tmp[10] == '1')
		all->letter = 'O';
	else if (tmp[10] == '2')
		all->letter = 'X';
	else
	exit(0);
}

void	init_map(t_all *all)
{
	int	j;

	j = 0;
	if (!(all->map = (char **)malloc(sizeof(char *) * (all->size_map[1] + 1))))
		exit(0);
	while (j < all->size_map[1])
		if (!(all->map[j++] = ft_strnew(all->size_map[0] + 1)))
			return ;//freedbchar(&(all->map));
	all->map[j] = NULL;
}

void	init_piece(t_all *all)
{
	int	j;

	j = 0;
	if (!(all->piece = (char **)malloc(sizeof(char *) * (all->size_piece[1] + 1))))
		exit(0);
	while (j < all->size_piece[1])
		if (!(all->piece[j++] = ft_strnew(all->size_piece[0] + 1)))
			return ;//freedbchar(&(all->piece));
	all->piece[j] = NULL;
}
