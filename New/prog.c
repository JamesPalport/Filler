#include "filler.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
void	put_map(t_all *all)
{
	int	fd;
	int	i;

	fd = open("map", O_WRONLY | O_APPEND);
	i = 0;
	while (all->map[i] != NULL)
		ft_putendl_fd(all->map[i++], fd);
	ft_putendl_fd("-----", fd);
	close(fd);
}

void	print_piece(t_all *all)
{
	int	fd;
	int	i;

	fd = open("piece", O_WRONLY | O_APPEND);
	i = 0;
	while (all->piece[i] != NULL)
		ft_putendl_fd(all->piece[i++], fd);
	ft_putendl_fd("-----", fd);
	close(fd);
}

void	put_read(t_all *all)
{
	int	fd;
	int	i;

	fd = open("read", O_WRONLY | O_APPEND);
	i = 0;
	while (all->read[i] != NULL)
		ft_putendl_fd(all->read[i++], fd);
	ft_putendl_fd("-----", fd);
	close(fd);
}

void	reader(t_all *all)
{
	int	fd;
	int	i;

	i = 0;
//	fd = open("t", O_RDONLY);
	fd = 0;
	sleep(1);
	begin_prog(all, fd);
	while (i++ < 4)
	{
	sleep(1);
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
	print_piece(all);
	put_read(all);
	count_blocs(all);
	pc_start(all);
	score_map(all);
	end_map(all);
	pick_position(all);
	ft_printf("%d %d\n", all->pos[1], all->pos[0]);
	}
//	close(fd);
}
int	main(void)
{
/*	char	*line;
	int		fd;

	fd = open("test", O_WRONLY);
	while(get_next_line(0, &line))
		ft_putendl_fd(line, fd);
	ft_printf("1000 10000\n");*/
	t_all all;

	init_all(&all);
	reader(&all);
	return (0);
}
