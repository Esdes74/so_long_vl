/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:08:07 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_copy(t_map *map)
{
	char	**new;
	int		i;
	int		j;

	new = (char **) malloc(sizeof(char *) * map->y);
	if (new == 0)
		return (0);
	i = 0;
	while (i < map->y)
	{
		new[i] = (char *) malloc(sizeof(char) * map->x);
		j = 0;
		if (new[i] == 0)
		{
			while (j <= i)
				free(new[j++]);
			return (free(new), NULL);
		}
		while (j < map->x)
			new[i][j++] = '#';
		i++;
	}
	return (new);
}

static void	diffusion(char **cpy, int x, int y, t_map *map)
{
	if (map->perso_x == -1 && map->perso_y == -1)
	{
		map->perso_x = x;
		map->perso_y = y;
	}
	if (x >= map->x || y >= map->y || x < 0 \
	|| y < 0 || cpy[y][x] == 'X' || cpy[y][x] == '*')
		return ;
	if (map->tab[y][x] == '1')
	{
		cpy[y][x] = 'X';
		return ;
	}
	else
		cpy[y][x] = '*';
	diffusion(cpy, x + 1, y, map);
	diffusion(cpy, x - 1, y, map);
	diffusion(cpy, x, y + 1, map);
	diffusion(cpy, x, y - 1, map);
}

static int	check_map(char **cpy, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if ((x == 0 || y == 0 || x == map->x - 1 || y == map->y - 1) \
			&& map->tab[y][x] != '1')
				return (ft_printf("Error\nMap not between wall\n"), 1);
			if (map->tab[y][x] == 'C' && cpy[y][x] != '*')
				return (ft_printf("Error\nCoins not reachable\n"), 1);
			if (map->tab[y][x] == 'E' && cpy[y][x] != '*')
				return (ft_printf("Error\nExit not reachable\n"), 1);
			if (map->tab[y][x] == 'E' && y != 1 && x != 1 \
			&& y != map->y - 2 && x != map->x - 2)
				return (ft_printf("Error\nExit in center of map\n"), 1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	delete_map(char **fr, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
		free(fr[i++]);
	free(fr);
}

int	verif_map(t_map *map)
{
	char	**cpy_map;
	int		x;
	int		y;
	int		pos_p;

	cpy_map = map_copy(map);
	if (cpy_map == 0)
		return (ft_printf("Error\n"), 1);
	y = 0;
	pos_p = 0;
	while (y < map->y && pos_p == 0)
	{
		x = 0;
		while (x < map->x && pos_p == 0)
		{
			if (map->tab[y][x] == 'P')
				pos_p = 1;
			x++;
		}
		y++;
	}
	diffusion(cpy_map, x - 1, y - 1, map);
	if (check_map(cpy_map, map) == 1)
		return (delete_map(cpy_map, map), 1);
	return (delete_map(cpy_map, map), 0);
}
