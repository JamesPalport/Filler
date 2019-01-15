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

	fd = open("./lecture.txt", O_WRONLY);
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

	j = 0;
	while (j < inp->size_piece[1])
	{
		i = 0;
		while (i < inp->size_piece[0])
		{
			if (inp->piece[j][i] == '*')
				inp->nb++;
			i++;
		}
		j++;
	}
}

t_all	*lecture(t_all *inp, int fd)
{
	static int	turn;

	if (!turn)
		turn = first_line(inp, fd);
	get_size(inp->size_map, fd);
	init_2d(&(inp->map), (int const *)inp->size_map);
	get_map(inp, fd);
	get_size(inp->size_piece, fd);
	init_2d(&(inp->piece), (int const *)inp->size_piece);
	if (!get_piece(inp, fd))
		free_2d(&(inp->map));
	count_blocs(inp);
	print_struct(*inp);
	return (inp);
}

int main()
{
	int		fd;
	t_all	*inp;
	t_list	*pos;
	char	**score;

	if (!(inp = (t_all*)malloc(sizeof(t_all))))
		return (0);
	fd = open("./tst", O_RDONLY);
	lecture(inp, fd);
	close(fd);
	pos = pc_start(inp);
	score = score_map();
	end_map(score, inp, pos);
	pick_position(score, pos);
	put_piece(inp, pos);
	fd = open("map.txt", O_WRONLY);
	put_2d(inp->map, fd);
	close(fd);
	return 0;
}
