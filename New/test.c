#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	count_blocs(t_all *inp)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < inp->size_piece[1])
	{
		i = 0;
		while (i < inp->size_piece[0])
		{
			if (inp->piece[j][i] == '*')
				count++;
			i++;
		}
		j++;
	}
	inp->nb_sqr = count;
}

void	adj_cm(t_all *all)
{
	all->cm_self[0] /= all->cm_self[2];
	all->cm_self[1] /= all->cm_self[2];
	all->cm_ene[0] /= all->cm_ene[2];
	all->cm_ene[1] /= all->cm_ene[2];
}

void	center_mass(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	while (j < all->size_map[1])
	{
		i = 0;
		while (all->map[j][i])
		{
			if (all->map[j][i] == all->letter[0])
			{
				all->cm_self[1] += j;
				all->cm_self[0] += i;
				all->cm_self[2]++;
			}
			else if (all->map[j][i] != '.')
			{
				all->cm_ene[1] += j;
				all->cm_ene[0] += i;
				all->cm_ene[2]++;
			}
			i++;
		}
		j++;
	}
	adj_cm(all);
}
