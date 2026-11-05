/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:02:04 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/26 11:35:42 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_error(t_ab *store)
{
	if (store)
	{
		if (store->stack[0])
			ft_lstclear(&store->stack[0], &free);
		if (store->stack[1])
			ft_lstclear(&store->stack[1], &free);
		free(store);
	}
	write(2, "Error\n", 6);
	exit(-1);
}
