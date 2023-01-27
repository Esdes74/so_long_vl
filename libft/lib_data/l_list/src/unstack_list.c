/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstack_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:17:06 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/06 20:30:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"
#include <stdio.h>

t_cell	*unstack_list(t_list *lst, int debug)
{
	t_cell	*rm;

	rm = lst->head;
	if (lst->type_lst != LIST || lst->len == 0)
	{
		if (debug == 1 && lst->type_lst != LIST)
		{
			write(1, "ERROR : fct unstack_list : Utilisation of fct list", 50);
			write(1, " on non list data structure\n", 28);
		}
		return (0);
	}
	if (lst->len > 0)
		lst->head = rm->next;
	if (lst->len > 1)
		lst->head->prev = 0;
	if (lst->len == 1)
		lst->tail = 0;
	lst->len--;
	return (rm);
}