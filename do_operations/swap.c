/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:11:10 by svalero           #+#    #+#             */
/*   Updated: 2026/10/20 08:26:16 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_list **stack)
{
	t_list	*swap;

	if (*stack && (*stack)->next)
	{
		swap = *stack;
		*stack = (*stack)->next;
		swap->next = (*stack)->next;
		(*stack)->next = swap;
	}
}
