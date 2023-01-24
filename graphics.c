/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:03:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/24 19:57:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_mlx_pixel_put(t_elem *cell, int x, int y, int color)
{
	char	*dst;

	dst = cell->adr + (y * cell->line_len + x * (cell->bpp / 8));
	*(unsigned int *) dst = color;
}

static int	creat_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	init_graphics(t_map *map, void *mlx1, void *win)
{
	void	*mlx;
	void	*window;
	int		i;
	int		j;
	t_elem	cell;
	int		color;

	mlx = mlx_init();
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			cell = map->tab[i][j];
			cell.img = mlx_new_image(mlx, 1920, 1080);
			cell.adr = mlx_get_data_addr(cell.img, &cell.bpp, &cell.line_len, \
			&cell.endian);
			if (cell.elem == 'E')
				color = creat_trgb(4, 4, 4, 4);
			my_mlx_pixel_put(&cell, j, i, 0x00FF0000);
			mlx_put_image_to_window(mlx1, win, cell.img, 0, 0);
			j++;
		}
		i++;
	}
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

static int	closes(int keycode, t_vars *vars)
{
	if (keycode == 97)
		ft_printf("Je vous aimes\n");
	if (keycode >= 2 && keycode <= 100)
	{
		ft_printf("key = %x\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	graphics(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
	mlx_loop(vars.mlx);
	// TODO : faire la partie graphique sur mac
	/* mlx = mlx_init(); */
	/* window = mlx_new_window(mlx, 1920, 1080, "Hello World"); */
	/* test = mlx_xpm_file_to_image(window, "./sprites/tilesets/grass.xmp", &img_taille, &img_taille); */
	/* if (test == NULL) */
	/* 	ft_printf("BBBBBBBBBBBB\n"); */
	/* /1* ft_printf("%p\n", test); *1/ */
	/* /1* init_graphics(map, mlx, window); *1/ */
	/* /1* mlx_loop(mlx); *1/ */
}
