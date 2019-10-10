/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_coord_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:47:55 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 12:12:53 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coord	have_coord_1(t_plat plat)
{
	int		i;
	int		j;
	t_coord	coord;
	int		count;

	count = 10000000;
	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (ft_is_putable(i, j, plat, i) == 1
					&& count > ft_count_nb(plat, i, j))
			{
				count = ft_count_nb(plat, i, j);
				coord.y = i;
				coord.x = j;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

int		ft_count_nb(t_plat plat, int i, int j)
{
	int	a;
	int	b;
	int	count;

	count = 0;
	a = 0;
	while (a < plat.ligne_p)
	{
		b = 0;
		while (b < plat.cols_p)
		{
			if (plat.piece[a][b] == '*')
				count = count + (int)plat.map[a + i][b + j];
			b++;
		}
		a++;
	}
	return (count);
}
