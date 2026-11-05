/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 19:36:03 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/24 15:13:06 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanall(void *f_buffer, t_list *res_start, void (*del)(void *))
{
	del(f_buffer);
	ft_lstclear(&res_start, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_filler;
	t_list	*res_start;
	t_list	*newnode;
	void	*f_buffer;

	if (!lst || !f || !del)
		return (NULL);
	res_start = NULL;
	while (lst)
	{
		f_buffer = f(lst->content);
		newnode = ft_lstnew(f_buffer);
		if (!newnode)
		{
			cleanall(f_buffer, res_start, del);
			return (NULL);
		}
		if (!res_start)
			res_start = newnode;
		else
			res_filler->next = newnode;
		res_filler = newnode;
		lst = lst->next;
	}
	return (res_start);
}
