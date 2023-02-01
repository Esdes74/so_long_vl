/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:03:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/01 17:40:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	closes(int keycode, t_map *map)
{
	int	j;

	if (keycode == k_esc)
	{
		j = 0;
		while (j < map->y)
			free(map->tab[j++]);
		free(map->tab);
		mlx_destroy_window(map->mlx, map->win);
		exit(1);
	}
	/* ft_printf("key = %d\n", keycode); */
	/* mlx_destroy_window(map->mlx, map->win); */
	/* exit(0); */
	return (0);
}

static int	put_image(char *sp, t_map map, int x, int y)
{
	int		h;
	int		l;
	void	*test;

	test = mlx_xpm_file_to_image(map.mlx, sp, &h, &l);
	if (test == NULL)
		return (1);
	mlx_put_image_to_window(map.mlx, map.win, test, x, y);
	mlx_destroy_image(map.mlx, test);
	return (0);
}

static int	creat_backgroud(t_map map)
{
	int	i;
	int	j;
	int	prb;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			/* witch_sprite(map->tab[i][j].elem, map, j * 14, i * 14); */
			if (map.tab[i][j].elem == '1')
				prb = put_image("./sprites/wall.xpm", map, j * 14, i * 14);
			else if (map.tab[i][j].elem == '0')
				prb = put_image("./sprites/grass.xpm", map, j * 14, i * 14);
			else if (map.tab[i][j].elem == 'P')
				prb = put_image("./sprites/player.xpm", map, j * 14, i * 14);
			else if (map.tab[i][j].elem == 'C')
				prb = put_image("./sprites/chest.xpm", map, j * 14, i * 14);
			else if (map.tab[i][j].elem == 'E')
				prb = put_image("./sprites/exit.xpm", map, j * 14, i * 14);
			if (prb == 1)
				return (mlx_destroy_window(map.mlx, map.win), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	graphics(t_map *map)
{
	/* map->mlx = mlx_init(); */
	/* map->win = mlx_new_window(map->mlx, 1920, 1080, "Hello world!"); */
	/* mlx_loop(map->mlx); */
	// TODO : faire la partie graphique sur mac
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (1);
	map->win = mlx_new_window(map->mlx, map->x * 14, map->y * 14, "So_long");
	if (map->win == NULL)
		return (1);
	if (creat_backgroud(*map) == 1)
		return (1);
	/* if (mlx_hook(map->win, 2, 1L<<0, closes, &map) == 1) */
	/* if (mlx_key_hook(map->win, closes, map) == 1) */
		/* return (1); */
	mlx_key_hook(map->win, closes, map);
	mlx_loop(map->mlx);
}
