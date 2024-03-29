/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:45:12 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/06 20:04:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

static void	debuger_stacking(int debug, int mod)
{
	if (debug == 1)
	{
		if (mod == 0)
			write(1, "ERROR : fct stacking_list : Utilisation of fct list on \
					non list data structure\n", 80);
		if (mod == 1)
			write(1, "ERROR : fct stacking_list : Malloc not OK\n", 42);
	}
}

static void	init_cell(t_cell *cell, t_data *d_cell)
{
	cell->data_cell = d_cell;
	cell->next = 0;
	cell->prev = 0;
}

int	stacking_list(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;

	if (lst->type_lst != LIST && debug == 1)
		debuger_stacking(debug, 0);
	if (lst->type_lst != LIST)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	if (debug == 1 && (d_cell == 0 || cell == 0))
		debuger_stacking(debug, 1);
	if (d_cell == 0 || cell == 0)
		return (0);
	init_data(data, t, FALSE, d_cell);
	init_cell(cell, d_cell);
	if (lst->len == 0)
		lst->tail = cell;
	else
	{
		lst->head->prev = cell;
		cell->next = lst->head;
	}
	lst->len++;
	lst->head = cell;
	return (1);
}
