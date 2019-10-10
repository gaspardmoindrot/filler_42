/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:42:26 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/19 17:14:24 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		for_ligne(char *line, int i)
{
	int		mult;
	int		ligne;

	ligne = 0;
	mult = 1;
	while (line[i] > 47 && line[i] < 58)
		i++;
	i--;
	while (line[i] > 47 && line[i] < 58)
	{
		ligne = ligne + ((line[i] - '0') * mult);
		mult = mult * 10;
		i--;
	}
	return (ligne);
}

t_plat	alloc_map(char *line, t_plat plat)
{
	int		mult;
	int		i;

	mult = 1;
	i = 8;
	plat.ligne = for_ligne(line, i);
	plat.cols = 0;
	while (line[i] > 47 && line[i] < 58)
		i++;
	i++;
	while (line[i] > 47 && line[i] < 58)
		i++;
	i--;
	mult = 1;
	while (line[i] > 47 && line[i] < 58)
	{
		plat.cols = plat.cols + ((line[i] - '0') * mult);
		mult = mult * 10;
		i--;
	}
	if (!(plat.map = (char **)malloc(sizeof(char *) * (plat.ligne + 1))))
		plat.map = NULL;
	return (plat);
}

t_plat	get_map(char *line, t_plat plat)
{
	int	i;
	int	j;
	int	mult;

	plat = alloc_map(line, plat);
	i = 0;
	plat.map[plat.ligne] = NULL;
	while (i < plat.ligne)
	{
		j = 0;
		if (!(plat.map[i] = (char *)malloc(sizeof(char) * (plat.cols + 1))))
		{
			plat.map[i] = NULL;
			return (plat);
		}
		plat.map[i][plat.cols] = '\0';
		while (j < plat.cols)
		{
			plat.map[i][j] = '.';
			j++;
		}
		i++;
	}
	plat.map = ft_end_map(plat, line, 0);
	return (plat);
}

char	**ft_end_map2(t_plat plat)
{
	int		i;
	int		j;

	i = 0;
	while (i < plat.ligne)
	{
		j = 0;
		while (j < plat.cols)
		{
			if (plat.map[i][j] == '.')
				plat.map[i][j] = 'Z';
			j++;
		}
		i++;
	}
	return (plat.map);
}
