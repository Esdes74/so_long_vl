/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:01:34 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/07 18:05:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_format(char *s, t_list *lst)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' && s[i + 1] == 'b' && s[i + 2] == 'e' \
		&& s[i + 3] == 'r' && s[i + 4] == '\0')
			return (0);
		i++;
	}
	ft_printf("Error\nWrong file format\n");
	free(lst);
	return (1);
}

static void	delete_map(t_map map)
{
	int	j;

	j = 0;
	while (j < map.y)
		free(map.tab[j++]);
	free(map.tab);
}

static void	destroy_mlx(t_map map)
{
	mlx_destroy_window(map.mlx, map.win);
	mlx_destroy_display(map.mlx);
	free(map.mlx);
}

static void	init_data_so_long(t_list *lst, t_map *map)
{
	lst = init_list(lst);
	map->x = 0;
	map->y = 0;
	map->count_c = 0;
	map->perso_x = -1;
	map->perso_y = -1;
	map->mlx = 0;
	map->win = 0;
	map->tab = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	*lst;
	int		graph;

	lst = (t_list *) malloc(sizeof(t_list));
	if (lst == 0)
		return (ft_printf("Error\n"), 1);
	init_data_so_long(lst, &map);
	if (argc != 2)
		return (free(lst), ft_printf("Error\nNot 1 argument\n"), 1);
	if (verif_format(argv[1], lst) == 1 || parsing(argv[1], &map, lst) == 1)
		return (1);
	if (creat_map(&map, lst) == 1)
		return (1);
	if (verif_map(&map) == 1)
		return (delete_map(map), 1);
	graph = graphics(&map);
	if (graph == 2)
		return (delete_map(map), destroy_mlx(map), ft_printf("Error\n"), 1);
	if (graph == 1)
		return (delete_map(map), ft_printf("Error\n"), 1);
	return (delete_map(map), 0);
}
