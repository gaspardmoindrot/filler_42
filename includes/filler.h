/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:54:47 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/19 17:14:37 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_plat
{
	char		player;
	char		**map;
	int			ligne;
	int			cols;
	char		**piece;
	int			ligne_p;
	int			cols_p;
}				t_plat;

t_plat			get_map(char *line, t_plat plat);
char			**ft_end_map(t_plat plat, char *line, int i);
t_plat			get_piece(char *line, t_plat plat);
char			**ft_end_piece(t_plat plat, char *line, int cols, int ligne);
t_plat			alloc_map(char *line, t_plat map);

t_coord			have_coord(t_plat plat, t_coord coord);
int				ft_is_putable(int i, int j, t_plat plat, int k);
int				ft_is_putable_2(int touch);
t_coord			have_coord_4(t_plat plat, t_coord coord);
int				ft_liaison(int i, int j, t_plat plat);
int				ft_liaison_1(t_plat plat);
int				ft_touch_star(int i, int j, t_plat plat);
int				ft_z(t_plat plat);

char			**change_map(t_plat plat);
char			**change_map_1(t_plat plat);
int				ft_nb_ou_pas(t_plat plat);
char			**ft_change_w_nb(t_plat plat, char c);
char			**change_w_nb(t_plat plat, int i, int j, char c);
char			ft_check_w_nb(t_plat plat);
char			**change_nb(t_plat plat, int i, int j);

t_coord			have_coord_1(t_plat plat);
int				ft_count_nb(t_plat plat, int i, int j);

char			**ft_end_map2(t_plat plat);
int				ft_end_map3(t_plat plat, char *line);
t_plat			alloc_map_p(char *line, t_plat plat);
int				for_ligne(char *line, int i);

#endif
