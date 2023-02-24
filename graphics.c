/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:03:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/24 19:30:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	witch_sprite(t_map map, int j, int i)
{
	if (map.tab[i][j] == '1')
		return (put_image("./sprites/wall.xpm", map, j * 28, i * 28));
	else if (map.tab[i][j] == '0')
		return (put_image("./sprites/grass.xpm", map, j * 28, i * 28));
	else if (map.tab[i][j] == 'P')
		return (put_image("./sprites/player.xpm", map, j * 28, i * 28));
	else if (map.tab[i][j] == 'C')
		return (put_image("./sprites/chest.xpm", map, j * 28, i * 28));
	else if (map.tab[i][j] == 'E')
		return (put_image("./sprites/exit.xpm", map, j * 28, i * 28));
	return (1);
}

static int	creat_backgroud(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (witch_sprite(map, j, i) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	put_image(char *sp, t_map map, int x, int y)
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

int	graphics(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (ft_printf("Error\n"), 1);
	map->win = mlx_new_window(map->mlx, map->x * 28, map->y * 28, "So_long");
	if (map->win == NULL)
		return (mlx_destroy_display(map->mlx), free(map->mlx), \
		ft_printf("Error\n"), 1);
	if (creat_backgroud(*map) == 1)
		return (ft_printf("Error\n"), 2);
	mlx_hook(map->win, 2, 1L << 0, init_key_events, map);
	mlx_hook(map->win, 17, 1L << 2, quit, map);
	mlx_loop(map->mlx);
	return (0);
}
