/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:01:32 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/28 13:26:55 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"	

static int	get_flag(char *arg)
{
	if (!ft_strncmp(arg, "--simple", 8))
		return (1);
	if (!ft_strncmp(arg, "--medium", 8))
		return (2);
	if (!ft_strncmp(arg, "--complex", 9))
		return (4);
	if (!ft_strncmp(arg, "--adaptative", 12))
		return (8);
	if (!ft_strncmp(arg, "--bench", 7))
		return (16);
	return (0);
}

int	check_flags(char *arg, t_ab *store)
{
	unsigned char	flag;

	flag = get_flag(arg);
	if (!flag)
		return (0);
	if (flag == 16 && store->flags >= 16)
		is_error(store);
	if (flag != 16 && store->flags % 16)
		is_error(store);
	store->flags += flag;
	return (flag);
}
