/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:47:39 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 12:12:25 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_nb_ou_pas(t_plat plat)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] < 78)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_change_w_nb(t_plat plat, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] == c)
				plat.map = change_w_nb(plat, i, j, c);
			j++;
		}
		i++;
	}
	return (plat.map);
}

char	**change_w_nb(t_plat plat, int i, int j, char c)
{
	if (i > 0 && plat.map[i - 1][j] == 'Z')
		plat.map[i - 1][j] = c + 1;
	if (i > 0 && j < plat.cols - 1 && plat.map[i - 1][j + 1] == 'Z')
		plat.map[i - 1][j + 1] = c + 1;
	if (j < plat.cols - 1 && plat.map[i][j + 1] == 'Z')
		plat.map[i][j + 1] = c + 1;
	if (j < plat.cols - 1 && i < plat.ligne - 1
			&& plat.map[i + 1][j + 1] == 'Z')
		plat.map[i + 1][j + 1] = c + 1;
	if (i < plat.ligne - 1 && plat.map[i + 1][j] == 'Z')
		plat.map[i + 1][j] = c + 1;
	if (i < plat.ligne - 1 && j > 0 && plat.map[i + 1][j - 1] == 'Z')
		plat.map[i + 1][j - 1] = c + 1;
	if (j > 0 && plat.map[i][j - 1] == 'Z')
		plat.map[i][j - 1] = c + 1;
	if (j > 0 && i > 0 && plat.map[i - 1][j - 1] == 'Z')
		plat.map[i - 1][j - 1] = c + 1;
	return (plat.map);
}

char	ft_check_w_nb(t_plat plat)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] > c && plat.map[i][j] < 78)
				c = plat.map[i][j];
			j++;
		}
		i++;
	}
	return (c);
}

char	**change_nb(t_plat plat, int i, int j)
{
	if (i > 0 && plat.map[i - 1][j] == 'Z')
		plat.map[i - 1][j] = 0;
	if (i > 0 && j < plat.cols - 1 && plat.map[i - 1][j + 1] == 'Z')
		plat.map[i - 1][j + 1] = 0;
	if (j < plat.cols - 1 && plat.map[i][j + 1] == 'Z')
		plat.map[i][j + 1] = 0;
	if (j < plat.cols - 1 && i < plat.ligne - 1
			&& plat.map[i + 1][j + 1] == 'Z')
		plat.map[i + 1][j + 1] = 0;
	if (i < plat.ligne - 1 && plat.map[i + 1][j] == 'Z')
		plat.map[i + 1][j] = 0;
	if (i < plat.ligne - 1 && j > 0 && plat.map[i + 1][j - 1] == 'Z')
		plat.map[i + 1][j - 1] = 0;
	if (j > 0 && plat.map[i][j - 1] == 'Z')
		plat.map[i][j - 1] = 0;
	if (j > 0 && i > 0 && plat.map[i - 1][j - 1] == 'Z')
		plat.map[i - 1][j - 1] = 0;
	return (plat.map);
}
