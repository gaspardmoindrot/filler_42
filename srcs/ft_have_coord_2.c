/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_coord_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:44:41 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 12:13:03 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_coord	have_coord(t_plat plat, t_coord coord)
{
	char	a;

	a = (plat.player == 'O') ? 'X' : 'O';
	coord.x = -1;
	coord.y = -1;
	if (ft_z(plat) == 1)
		coord = have_coord_1(plat);
	else
		coord = have_coord_4(plat, coord);
	return (coord);
}

int		ft_z(t_plat plat)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] != 'O' && plat.map[i][j] != 'o'
					&& plat.map[i][j] != 'X'
					&& plat.map[i][j] != 'x'
					&& plat.map[i][j] != 'Z')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_is_putable_2(int touch)
{
	if (touch == 1)
		return (1);
	return (0);
}
