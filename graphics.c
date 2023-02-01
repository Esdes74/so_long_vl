/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:03:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/31 18:55:10 by eslamber         ###   ########.fr       */
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

static int	put_image(char *sp, t_vars *vr, int x, int y)
{
	int		h;
	int		l;
	void	*test;

	test = mlx_xpm_file_to_image(vr->mlx, sp, &h, &l);
	if (test == NULL)
		return (1);
	mlx_put_image_to_window(vr->mlx, vr->win, test, x, y);
	return (0);
}

static int	creat_backgroud(t_map *map, t_vars *vars)
{
	int	i;
	int	j;
	int	h;
	int	l;
	void	*test;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->tab[i][j].elem == '1') // TODO : gestion en cas de retour erreur dep put_image
				put_image("./sprites/wall.xpm", vars, j * 14, i * 14);
			if (map->tab[i][j].elem == '0') // TODO : gestion en cas de retour erreur dep put_image
				put_image("./sprites/grass.xpm", vars, j * 14, i * 14);
			if (map->tab[i][j].elem == 'P') // TODO : gestion en cas de retour erreur dep put_image
				put_image("./sprites/player.xpm", vars, j * 14, i * 14);
			if (map->tab[i][j].elem == 'C') // TODO : gestion en cas de retour erreur dep put_image
				put_image("./sprites/chest.xpm", vars, j * 14, i * 14);
			if (map->tab[i][j].elem == 'E') // TODO : gestion en cas de retour erreur dep put_image
				put_image("./sprites/exit.xpm", vars, j * 14, i * 14);
			j++;
		}
		i++;
	}
	return (0);
}

int	graphics(t_map *map)
{
	t_vars	vars;
	void	*test;
	int		img_hauteur = 2;
	int		img_largeur = 2;
	char	*file_empty = "./sprites/grass.xpm";
	char	*file = "./sprites/wall.xpm";
	int		win_largeur = 1920;
	int		win_hauteur = 1080;

	/* vars.mlx = mlx_init(); */
	/* vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!"); */
	/* mlx_hook(vars.win, 2, 1L<<0, closes, &vars); */
	/* mlx_loop(vars.mlx); */
	// TODO : faire la partie graphique sur mac
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.win = mlx_new_window(vars.mlx, map->x * 14, map->y * 14, "So_long");
	if (vars.win == NULL)
		return (1);
	creat_backgroud(map, &vars);
	
	test = mlx_xpm_file_to_image(vars.mlx, file, &img_hauteur, &img_largeur);
	mlx_put_image_to_window(vars.mlx, vars.win, test, 164, 150);
	/* init_graphics(map, mlx, window); */
	mlx_loop(vars.mlx);
}
