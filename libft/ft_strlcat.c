/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:08:10 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/27 22:21:12 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len == size)
	{
		while (src[i])
			i++;
		return (size + i);
	}
	while (src[i] && size > i + dest_len + 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	while (src[i])
		i++;
	return (dest_len + i);
}
