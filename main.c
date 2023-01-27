/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:01:34 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/27 13:41:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_format(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' && s[i + 1] == 'b' && s[i + 2] == 'e' \
		&& s[i + 3] == 'r')
			return (0);
		i++;
	}
	ft_printf("Error\nWrong file format\n");
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

int	main(int argc, char **argv)
{
	t_map	map;
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (lst == 0)
		return (1);
	lst = init_list(lst);
	map.y = 0;
	map.tab = 0;
	if (argc != 2)
		return (ft_printf("Error\nToo much arguments\n"), 1);
	if (verif_format(argv[1]) == 1 || parsing(argv[1], &map, lst) == 1)
		return (1);
	if (creat_map(&map, lst) == 1)
		return (1);
	if (verif_map(&map) == 1)
		return (delete_map(map), 1);
	/* graphics(&map); */
	print_map(map);
	return (delete_map(map), 0);
}
