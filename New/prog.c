#include "filler.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void	put_map(t_all *all)
{
	int	fd;
	int	i;

	fd = open("map", O_WRONLY | O_APPEND);
	i = 0;
	while (all->map[i] != NULL)
		ft_putendl_fd(all->map[i++], fd);
	ft_putendl_fd("", fd);
	close(fd);
}

void	put_piece(t_all *all)
{
	int	fd;
	int	i;

	fd = open("piece", O_WRONLY | O_APPEND);
	i = 0;
	while (all->piece[i] != NULL)
		ft_putendl_fd(all->piece[i++], fd);
	ft_putendl_fd("", fd);
	close(fd);
}


void	reader(t_all *all)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("t", O_RDONLY);
	begin_prog(all, fd);
	while (i++ < 4)
	{
	get_size(all, fd);
	if (!all->map)
		init_map(all);
	if (!all->map)
		exit(0);
	skip_lines(1, fd);
	get_map(all, fd);
	put_map(all);
	get_size(all, fd);
	get_piece(all, fd);
	put_piece(all);
	pc_start(all);
	score_map(all);
	}
	close(fd);
}

int	main(void)
{
	t_all all;

	init_all(&all);
	reader(&all);
	return (0);
}
