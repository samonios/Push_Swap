/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:17:24 by svalero           #+#    #+#             */
/*   Updated: 2026/10/23 18:10:18 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push(t_list **src, t_list **dst, int *size_src, int *size_dst)
{
	t_list	*head;

	if (*src)
	{
		head = *src;
		*src = head->next;
		if (*dst)
			head->next = *dst;
		else
			head->next = NULL;
		*dst = head;
		(*size_src)--;
		(*size_dst)++;
	}
}
