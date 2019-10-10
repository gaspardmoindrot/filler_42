/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:47:49 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 12:12:45 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_putable(int i, int j, t_plat plat, int k)
{
	int		l;
	int		touch;
	char	a;

	if (i + plat.ligne_p - 1 >= plat.ligne || j + plat.cols_p - 1 >= plat.cols)
		return (0);
	a = (plat.player == 'O') ? 'X' : 'O';
	touch = 0;
	while (k < i + plat.ligne_p)
	{
		l = j;
		while (l < j + plat.cols_p)
		{
			if (plat.piece[k - i][l - j] == '*' && (plat.map[k][l] == a
						|| plat.map[k][l] == a + 32))
				return (0);
			else if (plat.piece[k - i][l - j] == '*' &&
						(plat.map[k][l] == plat.player
							|| plat.map[k][l] == plat.player + 32))
				touch++;
			l++;
		}
		k++;
	}
	return (ft_is_putable_2(touch));
}

t_coord	have_coord_4(t_plat plat, t_coord coord)
{
	int	i;
	int	j;
	int	lia;

	lia = 0;
	i = plat.ligne - 1;
	while (i >= 0)
	{
		j = plat.cols - 1;
		while (j >= 0)
		{
			if (ft_is_putable(i, j, plat, i) == 1)
			{
				if (ft_liaison(i, j, plat) > lia)
				{
					lia = ft_liaison(i, j, plat);
					coord.x = j;
					coord.y = i;
				}
			}
			j--;
		}
		i--;
	}
	return (coord);
}

int		ft_liaison(int i, int j, t_plat plat)
{
	int	k;
	int	l;

	k = i;
	while (k < i + plat.ligne_p)
	{
		l = j;
		while (l < j + plat.cols_p)
		{
			if (plat.piece[k - i][l - j] == '*'
					&& plat.map[k][l] != plat.player
					&& plat.map[k][l] != plat.player + 32)
				plat.map[k][l] = plat.piece[k - i][l - j];
			l++;
		}
		k++;
	}
	return (ft_liaison_1(plat));
}

int		ft_liaison_1(t_plat plat)
{
	int	touch;
	int	k;
	int	l;

	touch = 0;
	k = 0;
	while (k < plat.ligne)
	{
		l = 0;
		while (l < plat.cols)
		{
			if (plat.map[k][l] == '*')
				touch = touch + ft_touch_star(k, l, plat);
			l++;
		}
		k++;
	}
	return (touch);
}

int		ft_touch_star(int i, int j, t_plat plat)
{
	int	touch;

	touch = 0;
	if (i == 0 || plat.map[i - 1][j] == 'O' || plat.map[i - 1][j] == 'o'
			|| plat.map[i - 1][j] == 'X'
			|| plat.map[i - 1][j] == 'x')
		touch++;
	if (i == plat.ligne - 1 || plat.map[i + 1][j] == 'O'
			|| plat.map[i + 1][j] == 'o'
			|| plat.map[i + 1][j] == 'X'
			|| plat.map[i + 1][j] == 'x')
		touch++;
	if (j == 0 || plat.map[i][j - 1] == 'O' || plat.map[i][j - 1] == 'o'
			|| plat.map[i][j - 1] == 'X'
			|| plat.map[i][j - 1] == 'x')
		touch++;
	if (j == plat.cols - 1 || plat.map[i][j + 1] == 'O'
			|| plat.map[i][j + 1] == 'o'
			|| plat.map[i][j + 1] == 'X'
			|| plat.map[i][j + 1] == 'x')
		touch++;
	return (touch);
}
