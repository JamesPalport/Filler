#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	put_2d(char **ch, int fd)
{
	int	i;

	i = 0;
	while (ch[i])
		ft_putendl_fd(ch[i++], fd);
}

void	print_struct(t_all inp)
{
	int	fd;

	fd = open("./lecture.txt", O_WRONLY | O_APPEND);
	ft_putendl_fd("map :", fd);
	put_2d(inp.map, fd);
	ft_putendl_fd("piece :", fd);
	put_2d(inp.piece, fd);
	ft_dprintf(fd, "y :%d\tx :%d\n", inp.size_map[1], inp.size_map[0]);
	ft_dprintf(fd, "c :%c\n", inp.c);
	close(fd);
}

int		get_map(t_all *inp, int fd)
{
	int		i;
	char	*line;
	char	**split;

	i = 0;
	get_next_line(fd, &line);
	while (i < inp->size_map[1])
	{
		get_next_line(fd, &line);
		split = ft_strsplit(line, ' ');
		if (check_line(inp, split[1], 0))
			ft_strcpy(*(inp->map + i), split[1]);
		else
		{
			free(line);
			return (free_2d(&(inp->map)));
		}
		free(line);
		free_2d(&split);
		i++;
	}
	return (1);
}

int		get_piece(t_all *inp, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < inp->size_piece[1])
	{
		get_next_line(fd, &line);
		if (check_line(inp, line, 1))
			inp->piece[i] = line;
		else
			return (free_2d(&(inp->piece)));
		i++;
	}
	return (1);
}

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
	inp->nb = count;
}

int	reading(t_all *inp, int fd)
{
	static int	turn;
	int	tmp;

	tmp = 0;
	if (!(turn = first_line(inp, fd, turn)))
		return (0);
	if (!get_size(inp->size_map, fd, &tmp))
		return (0);
	init_2d(&(inp->map), (int const *)inp->size_map, 0);
	get_map(inp, fd);
	if (!get_size(inp->size_piece, fd, &(inp->size_chd)))
		return (0);
	init_2d(&(inp->piece), (int const *)inp->size_piece, inp->size_chd);
	if (!get_piece(inp, fd))
		free_2d(&(inp->map));
	count_blocs(inp);
	print_struct(*inp);
	return (1);
}


