/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 08:46:41 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 19:52:35 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	fill_array_with_numbers(t_list *stack, int *array, int size)
{
	int		i;
	t_data	*node;

	i = 0;
	while (i < size)
	{
		node = (t_data *)stack->content;
		array[i] = node->num;
		stack = stack->next;
		i++;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	displaced;

	if (size < 2)
		return ;
	i = 1;
	while (i < size)
	{
		if (array[i - 1] > array[i])
		{
			displaced = array[i];
			j = i;
			while (j > 0 && array[j - 1] > displaced)
			{
				array[j] = array[j - 1];
				j--;
			}
			array[j] = displaced;
		}
		i++;
	}
}

static void	put_target_in_data_node(t_list *stack, int *array, int size)
{
	int		i;
	t_data	*node;

	while (stack)
	{
		node = (t_data *)stack->content;
		i = 0;
		while (i < size && array[i] != node->num)
			i++;
		node->target = i;
		stack = stack->next;
	}
}

int	set_target_position(t_ab *store)
{
	int	*array;

	store->input_size = store->list_size[0];
	if (!store->input_size)
		return (1);
	array = malloc(sizeof(int) * store->input_size);
	if (!array)
		return (0);
	fill_array_with_numbers(store->stack[0], array, store->input_size);
	sort_array(array, store->input_size);
	put_target_in_data_node(store->stack[0], array, store->input_size);
	free(array);
	return (1);
}
