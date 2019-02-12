/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:50:48 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/07 14:50:56 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
