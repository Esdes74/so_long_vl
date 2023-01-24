/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:44:41 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "./libft/mlx_linux/mlx.h"

typedef struct s_elem
{
	char	elem;
	void	*img;
	char	*adr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_elem;

typedef struct s_map
{
	int		x;
	int		y;
	t_elem	**tab;
}	t_map;

typedef struct s_count
{
	int	count_e;
	int	count_p;
	int	count_c;
}	t_count;

// Print map in terminal
void	print_map(t_map map);

// Parse the txt file into a map int**
int		parsing(char *s, t_map *map, t_list *lst);

// Creat tab in map structure and delete list
int		creat_map(t_map *map, t_list *lst);

// Return 0 if map can be finished
int		verif_map(t_map *map);

// Main of graphic part
void	graphics(t_map *map);

#endif
