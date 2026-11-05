/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:36:16 by svalero           #+#    #+#             */
/*   Updated: 2026/10/20 10:38:30 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*node;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		node = head->next;
		*stack = node;
		while (node->next)
			node = node->next;
		node->next = head;
		head->next = NULL;
	}
}
