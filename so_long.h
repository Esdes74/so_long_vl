/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:44:41 by eslamber          #+#    #+#             */
/*   Updated: 2023/03/08 11:41:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "./libft/mlx_linux/mlx.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		count_c;
	int		perso_x;
	int		perso_y;
	int		exit;
	void	*mlx;
	void	*win;
	char	**tab;
}	t_map;

typedef struct s_count
{
	int	count_e;
	int	count_p;
	int	count_c;
}	t_count;

enum	e_key{
	k_esc = 65307,
	k_w = 119,
	k_s = 115,
	k_a = 97,
	k_d = 100,
	k_up = 65362,
	k_do = 65364,
	k_ri = 65363,
	k_le = 65361,
};

// Print map in terminal
void	print_map(t_map map);

// Parse the txt file into a map int**
int		parsing(char *s, t_map *map, t_list *lst);

// Creat tab in map structure and delete list
int		creat_map(t_map *map, t_list *lst);

// Return 0 if map can be finished
int		verif_map(t_map *map);

// Main of graphic part
int		graphics(t_map *map);

// Put image sp in window
int		put_image(char *sp, t_map map, int x, int y);

// close programme
int		quit(t_map *map);

// Initialisation of hook events
int		init_key_events(int key, t_map *map);

#endif
