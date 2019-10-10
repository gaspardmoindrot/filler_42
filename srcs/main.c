/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:48:00 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/18 14:17:10 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		print_coord(t_coord coord)
{
	ft_putnbr(coord.y);
	ft_putchar(' ');
	ft_putnbr(coord.x);
	ft_putchar('\n');
}

static t_plat	free_var(t_plat plat)
{
	int		i;

	i = 0;
	while (i < plat.ligne)
	{
		free(plat.map[i]);
		i++;
	}
	free(plat.map);
	i = 0;
	while (i < plat.ligne_p)
	{
		free(plat.piece[i]);
		i++;
	}
	free(plat.piece);
	return (plat);
}

int				main(void)
{
	char	*line;
	t_plat	plat;
	t_coord	coord;

	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$ exec p", 10) == 0)
			plat.player = (line[10] == '1') ? 'O' : 'X';
		else if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			plat = get_map(line, plat);
			plat.map = change_map(plat);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			plat = get_piece(line, plat);
			coord = have_coord(plat, coord);
			print_coord(coord);
			plat = free_var(plat);
		}
		free(line);
	}
	line = NULL;
	return (0);
}
