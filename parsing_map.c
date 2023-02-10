/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:34:32 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/10 12:36:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	add_list(t_list *lst, char c, int *count)
{
	char	*let;

	let = (char *) malloc(sizeof(char));
	if (let == 0)
		return (ft_printf("Error\n"), 1);
	*let = c;
	if (*count == 0)
		(*count)++;
	if (addback_list(lst, let, CHAR, 1) == 0)
		return (free(let), ft_printf("Error\n"), 1);
	return (0);
}

static int	annalyse_char(t_list *lst, char c, t_count *count)
{
	int	mod;

	mod = 1;
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (ft_printf("Error\nCharactere not accepted\n", c), 1);
	if (c == '0' || c == '1' || c == 'C')
	{
		if (c == 'C')
			count->count_c++;
		if (add_list(lst, c, &mod) == 1)
			return (1);
	}
	else if (count->count_e != 0 && c == 'E')
		return (ft_printf("Error\nMultiple exits not accepted\n"), 1);
	else if (count->count_p != 0 && c == 'P')
		return (ft_printf("Error\nMulti-player not accepted\n"), 1);
	else if (c == 'E' && count->count_e == 0)
	{
		if (add_list(lst, 'E', &count->count_e) == 1)
			return (1);
	}
	else if (c == 'P' && count->count_p == 0)
		if (add_list(lst, 'P', &count->count_p) == 1)
			return (1);
	return (0);
}

static int	annalyse(t_list *lst, char *s, t_map *map)
{
	static t_count	count;
	int				i;

	i = 0;
	if (s == NULL)
	{
		if (map->x <= 3 && map->y <= 3)
			return (ft_printf("Error\nWrong dimensions for map\n"), 1);
		if (count.count_e == 0)
			return (ft_printf("Error\nNo exit in map\n"), 1);
		if (count.count_p == 0)
			return (ft_printf("Error\nNo perso in map\n"), 1);
		if (count.count_c == 0)
			return (ft_printf("Error\nNo coins in map\n"), 1);
		else
			map->count_c = count.count_c;
	}
	while (s != NULL && s[i])
	{
		if (s[i] != '\n' && annalyse_char(lst, s[i], &count) == 1)
			return (1);
		i++;
	}
	return (0);
}

static void	d_lst(t_list *lst, char *s, t_map *map)
{
	t_cell	*cell;
	int		i;

	cell = unstack_list(lst, 1);
	i = 0;
	while (cell != 0)
	{
		free(cell->data_cell->data);
		free(cell->data_cell);
		free(cell);
		cell = unstack_list(lst, 1);
	}
	while (i < map->y && map->tab)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	free(lst);
	free(s);
}

int	parsing(char *s, t_map *map, t_list *lst)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (free(lst), ft_printf("Error\nFile doesn't open\n"), 1);
	str = get_next_line(fd);
	map->x = ft_strlen(str) - 1;
	while (str)
	{
		len = ft_strlen(str) - 1;
		map->y++;
		if (map->x != len)
			return (d_lst(lst, str, map), ft_printf("Error\nNot oblong\n"), 1);
		if (annalyse(lst, str, map) == 1)
			return (d_lst(lst, str, map), close(fd), 1);
		free(str);
		str = get_next_line(fd);
	}
	if (close(fd) == -1 || annalyse(lst, str, map) == 1)
		return (d_lst(lst, str, map), 1);
	return (free(str), 0);
}
