#include "filler.h"

void	extr_size(t_all *all, char *line, int dst)
{
	int	i;
	int	prev[2];

	i = 0;
	if (dst == 0)
	{
		prev[0] = all->size_map[0];
		prev[1] = all->size_map[1];
		all->size_map[1] = ft_atoi(line);
		while (ft_isdigit(line[i]))
			i++;
		all->size_map[0] = ft_atoi(line + i);
		if (prev[0] && prev[1])
			if (prev[0] != all->size_map[0] || (prev[1] != all->size_map[1]))
				exit(0);
	}
	if (dst == 1)
	{
		all->size_piece[1] = ft_atoi(line);
		while (ft_isdigit(line[i]))
			i++;
		all->size_piece[0] = ft_atoi(line + i);
	}
}

void	get_size(t_all *all, int fd)
{
	char	*tmp;

	int	i;
	i = 0;
	while(all->read[i])
		i++;
	if (get_next_line(fd, &tmp) <= 0)
	{
		if (tmp)
			free(tmp);
		exit(0);
	}
	all->read[i] = ft_strdup(tmp);
	if (!ft_strncmp("Plateau", tmp, 7))
		extr_size(all, tmp + 8, 0);
	else if (!ft_strncmp("Piece", tmp, 5))
		extr_size(all, tmp + 6, 1);
	free(tmp);
}

void	get_map(t_all *all, int fd)
{
	int		i;
	char	*line;

	int	j;
	i = 0;
	j = 0;
	while(all->read[j])
		j++;
	while (i < all->size_map[1])
	{
		get_next_line(fd, &line);
		all->read[j++] = ft_strdup(line);
		ft_strncpy(all->map[i], line + 4, all->size_map[0]);
		i++;
	}
}

void	get_piece(t_all *all, int fd)
{
	int		i;
	char	*line;

	int	j;
	j = 0;
	while(all->read[j])
		j++;
	init_piece(all);
	i = 0;
	while (i < all->size_piece[1])
	{
		get_next_line(fd, &line);
		all->read[j++] = ft_strdup(line);
		ft_strncpy(all->piece[i], line, all->size_piece[0]);
		i++;
	}
}
