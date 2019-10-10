/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:39:41 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 12:12:33 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**change_map_1(t_plat plat)
{
	char	c;

	c = 91;
	if (ft_nb_ou_pas(plat) == 1)
	{
		while (c != ft_check_w_nb(plat))
		{
			c = ft_check_w_nb(plat);
			plat.map = ft_change_w_nb(plat, c);
		}
	}
	return (plat.map);
}

char	**change_map(t_plat plat)
{
	int		i;
	int		j;
	char	a;

	a = (plat.player == 'O') ? 'X' : 'O';
	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] == a || plat.map[i][j] == a + 32)
				plat.map = change_nb(plat, i, j);
			j++;
		}
		i++;
	}
	return (change_map_1(plat));
}
