/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:53:26 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 10:47:41 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_ab *store, int op)
{
	if (op == 0)
		do_swap(&store->stack[0]);
	else if (op == 1)
		do_swap(&store->stack[1]);
	else
	{
		do_swap(&store->stack[0]);
		do_swap(&store->stack[1]);
	}
}

static void	rotate(t_ab *store, int op)
{
	if (op == 0)
		do_rotate(&store->stack[0]);
	else if (op == 1)
		do_rotate(&store->stack[1]);
	else
	{
		do_rotate(&store->stack[0]);
		do_rotate(&store->stack[1]);
	}
}

static void	r_rotate(t_ab *store, int op)
{
	if (op == 0)
		do_r_rotate(&store->stack[0]);
	else if (op == 1)
		do_r_rotate(&store->stack[1]);
	else
	{
		do_r_rotate(&store->stack[0]);
		do_r_rotate(&store->stack[1]);
	}
}

static void	push(t_ab *store, int op)
{
	if (op == 0)
		do_push(&store->stack[0], &store->stack[1],
			&store->list_size[0], &store->list_size[1]);
	else
		do_push(&store->stack[1], &store->stack[0],
			&store->list_size[1], &store->list_size[0]);
}

void	do_op(t_ab *store, int op)
{
	if (op < 0 || op >= 11)
		return ;
	if (op / 3 == 0)
		swap(store, op % 3);
	else if (op / 3 == 1)
		rotate(store, op % 3);
	else if (op / 3 == 2)
		r_rotate(store, op % 3);
	else
		push(store, op % 3);
	store->op_counter[op]++;
	write(1, store->name[op], ft_strlen(store->name[op]));
}
