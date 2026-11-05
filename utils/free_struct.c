/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:22:29 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 18:23:22 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_struct(t_ab **store)
{
	if (!store || !*store)
		return ;
	if ((*store)->stack[0])
		ft_lstclear(&(*store)->stack[0], &free);
	if ((*store)->stack[1])
		ft_lstclear(&(*store)->stack[1], &free);
	free(*store);
	*store = NULL;
}
