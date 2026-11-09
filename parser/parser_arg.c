/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:49:40 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 14:31:56 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

void	fill_arg(t_ab *store, char **arg)
{
	int		j;
	int		num;
	t_data	*data;
	t_list	*new;

	j = 0;
	while (arg[j])
	{
		num = atoi_and_valid(arg, j++, store);
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
			free_arg(arg);
		if (!data)
			is_error(store);
		data->num = num;
		new = ft_lstnew(data);
		if (!new)
		{
			free_arg(arg);
			free(data);
			is_error(store);
		}
		ft_lstadd_back(&(store->stack[0]), new);
		store->list_size[0] += 1;
	}
}

void	parser_arg(t_ab *store, int ac, char **av)
{
	int		i;
	char	**arg;

	i = 1;
	while (i < ac && check_flags(av[i], store))
		i++;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			is_error(store);
		if (!arg[0])
		{
			free(arg);
			is_error(store);
		}
		fill_arg(store, arg);
		free_arg(arg);
		i++;
	}
	if (store->list_size[0] == 0)
		return ;
}
