/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:26:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/03 12:25:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_move(t_map *map, int x, int y)
{
	static int	move;

	if (map->tab[y][x].elem == '1')
		return (1);
	else if (map->tab[y][x].elem == 'C')
	{
		map->tab[y][x].elem = '0';
		map->count_c--;
	}
	else if (map->tab[y][x].elem == 'E')
	{
		if (map->count_c == 0)
		{
			ft_printf("WELL DONE !!!\n");
			quit(map);
		}
		else
			return (1);
	}
	put_image("./sprites/grass.xpm", *map, map->perso_x * 14, map->perso_y*14);
	map->tab[map->perso_y][map->perso_x].elem = '0';
	map->tab[y][x].elem = 'P';
	map->perso_y = y;
	map->perso_x = x;
	put_image("./sprites/player.xpm", *map, map->perso_x * 14, map->perso_y*14);
	return (move++, ft_printf("move = %d\n", move), 0);
}

int	quit(t_map *map)
{
	int j;

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
		check_move(map, map->perso_x - 1, map->perso_y);
	else if (keycode == k_d || keycode == k_ri)
		check_move(map, map->perso_x + 1, map->perso_y);
	else if (keycode == k_s || keycode == k_do)
		check_move(map, map->perso_x, map->perso_y + 1);
	else if (keycode == k_w || keycode == k_up)
		check_move(map, map->perso_x, map->perso_y - 1);
}
