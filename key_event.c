/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:26:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/08 14:46:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	following_check(t_map *map, int x, int y)
{
	if (put_image("./sprites/grass.xpm", *map, map->perso_x * 28,\
	 map->perso_y * 28) == 1)
		return (1);
	map->tab[map->perso_y][map->perso_x] = '0';
	map->tab[y][x] = 'P';
	map->perso_y = y;
	map->perso_x = x;
	if (put_image("./sprites/player.xpm", *map, map->perso_x * 28, \
	map->perso_y * 28) == 1)
		return (1);
	return (0);
}

static int	check_move(t_map *map, int x, int y)
{
	static int	move;

	if (map->tab[y][x] == '1')
		return (2);
	else if (map->tab[y][x] == 'C')
	{
		map->tab[y][x] = '0';
		map->count_c--;
	}
	else if (map->tab[y][x] == 'E')
	{
		if (map->count_c == 0)
		{
			ft_printf("WELL DONE !!!\n");
			quit(map);
		}
		else
			return (2);
	}
	if (following_check(map, x, y) == 1)
		return (ft_printf("Error\n"), 1);
	return (move++, ft_printf("move = %d\n", move), 0);
}

int	quit(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->y)
		free(map->tab[j++]);
	free(map->tab);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(1);
	return (0);
}

int	init_key_events(int keycode, t_map *map)
{
	if (keycode == k_esc)
		quit(map);
	else if (keycode == k_a || keycode == k_le)
	{
		if (check_move(map, map->perso_x - 1, map->perso_y) == 1)
			quit(map);
	}
	else if (keycode == k_d || keycode == k_ri)
	{
		if (check_move(map, map->perso_x + 1, map->perso_y) == 1)
			quit(map);
	}
	else if (keycode == k_s || keycode == k_do)
	{
		if (check_move(map, map->perso_x, map->perso_y + 1) == 1)
			quit(map);
	}
	else if (keycode == k_w || keycode == k_up)
		if (check_move(map, map->perso_x, map->perso_y - 1) == 1)
			quit(map);
	return (0);
}
