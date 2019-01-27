#include "filler.h"

int	skip_lines(int n, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < n && get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	if (i != n)
		return (0);
	return (1);
}

void	reset_dbchar(char ***map, int size)
{
	int	j;

	if (*map == NULL)
		free(*map);
	if (!(*map = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(0);
	j = 0;
	while (j <= size)
		(*map)[j++] = NULL;
}
