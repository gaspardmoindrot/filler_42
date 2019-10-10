/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:47:44 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/19 17:13:36 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_end_map3(t_plat plat, char *line)
{
	int		count;
	int		multi;
	int		i;

	i = 0;
	multi = 1;
	count = 0;
	while (line[i] < 58 && line[i] > 47)
		i++;
	i--;
	while (i >= 0 && line[i] < 58 && line[i] > 47)
	{
		count = count + (line[i] - '0') * multi;
		multi = multi * 10;
		i--;
	}
	return (count);
}

char	**ft_end_map(t_plat plat, char *line, int i)
{
	int	j;
	int	count;

	count = 0;
	while (get_next_line(0, &line))
	{
		i = 0;
		if (line[0] < 58 && line[i] > 47)
		{
			count = ft_end_map3(plat, line);
			while (line[i] < 58 && line[i] > 47)
				i++;
			i++;
			j = 0;
			while (j < plat.cols)
			{
				plat.map[count][j] = line[i + j];
				j++;
			}
		}
		free(line);
		if (count == plat.ligne - 1)
			break ;
	}
	return (ft_end_map2(plat));
}

t_plat	alloc_map_p(char *line, t_plat plat)
{
	int		mult;
	int		i;

	mult = 1;
	i = 6;
	plat.ligne_p = for_ligne(line, i);
	plat.cols_p = 0;
	while (line[i] > 47 && line[i] < 58)
		i++;
	i++;
	while (line[i] > 47 && line[i] < 58)
		i++;
	i--;
	while (line[i] > 47 && line[i] < 58)
	{
		plat.cols_p = plat.cols_p + ((line[i] - '0') * mult);
		mult = mult * 10;
		i--;
	}
	if (!(plat.piece = (char **)malloc(sizeof(char *) * (plat.ligne_p + 1))))
		plat.piece = NULL;
	return (plat);
}

t_plat	get_piece(char *line, t_plat plat)
{
	int	i;
	int	j;

	plat = alloc_map_p(line, plat);
	i = 0;
	plat.piece[plat.ligne_p] = NULL;
	while (i < plat.ligne_p)
	{
		j = 0;
		if (!(plat.piece[i] = (char *)malloc(sizeof(char) * (plat.cols_p + 1))))
		{
			plat.piece[i] = NULL;
			return (plat);
		}
		plat.piece[i][plat.cols_p] = '\0';
		while (j < plat.cols_p)
		{
			plat.piece[i][j] = '.';
			j++;
		}
		i++;
	}
	plat.piece = ft_end_piece(plat, line, plat.cols_p, plat.ligne_p);
	return (plat);
}

char	**ft_end_piece(t_plat plat, char *line, int cols, int ligne)
{
	int	i;
	int	j;

	i = 0;
	while (i < ligne && get_next_line(0, &line))
	{
		j = 0;
		while (j < cols)
		{
			plat.piece[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
	}
	return (plat.piece);
}
