/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:35:12 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/22 10:53:33 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_line(t_all *all, char *str, int dtp)
{
	int		len;
	int		i;

	i = 0;
	if (!dtp)
		len = all->size_map[0];
	else
		len = all->size_piece[0];
	while (str[i])
	{
		if (str[i] != '.' && ((dtp == 0 && (str[i] != 'O' && str[i] != 'o'
						&& str[i] != 'X' && str[i] != 'x')) ||
					(dtp == 1 && str[i] != '*')))
			return (0);
		i++;
	}
	if (i != len)
		return (0);
	return (1);
}
