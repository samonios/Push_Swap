/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:49:05 by svalero           #+#    #+#             */
/*   Updated: 2026/10/20 10:39:00 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_r_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*next;

	if (*stack && (*stack)->next)
	{
		node = *stack;
		next = node->next;
		while (next->next)
		{
			node = next;
			next = next->next;
		}
		node->next = NULL;
		next->next = *stack;
		*stack = next;
	}
}
