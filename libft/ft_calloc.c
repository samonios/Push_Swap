/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:56:42 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 14:47:20 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	int				n;

	n = nmemb * size;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return (ptr);
}
