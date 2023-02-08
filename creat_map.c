/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:35:29 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/08 14:05:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_map(t_map *map, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(map->tab[i++]);
	free(map->tab);
}

static void	delete_lst(t_list *lst)
{
	t_cell	*cell;
	t_cell	*end;

	cell = lst->head;
	while (cell != 0)
	{
		end = cell->next;
		free(cell->data_cell->data);
		free(cell->data_cell);
		free(cell);
		cell = end;
	}
	free(lst);
}

int	creat_map(t_map *map, t_list *lst)
{
	int		i;
	int		j;
	t_cell	*cell;

	i = 0;
	map->tab = (char **) malloc(sizeof(char *) * (map->y));
	if (map->tab == 0)
		return (delete_lst(lst), ft_printf("Error\n"), 1);
	while (i < map->y)
	{
		j = 0;
		map->tab[i] = (char *) malloc(sizeof(char) * (map->x));
		if (map->tab[i] == 0)
			return (del_map(map, i), delete_lst(lst), ft_printf("Error\n"), 1);
		while (j < map->x)
		{
			cell = unstack_list(lst, 1);
			map->tab[i][j++] = *((char *)(cell->data_cell->data));
			free(cell->data_cell->data);
			free(cell->data_cell);
			free(cell);
		}
		i++;
	}
	return (free(lst), 0);
}
