/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:44:26 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/10 12:28:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.tab[i][j] == '1')
				write(1, "X", 1);
			else if (map.tab[i][j] == '0')
				write(1, " ", 1);
			else if (map.tab[i][j] == 'C')
				write(1, "C", 1);
			else if (map.tab[i][j] == 'P')
				write(1, "P", 1);
			else if (map.tab[i][j] == 'E')
				write(1, "E", 1);
			j++;
		}
		write(1, "|\n", 2);
		i++;
	}
}
