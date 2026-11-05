/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:37:51 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 20:13:11 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cut_start(char const *s1, char const *set)
{
	int		i;
	int		limit;

	limit = 0;
	while (s1[limit])
	{
		i = 0;
		while (set[i] && s1[limit] != set[i])
			i++;
		if (!set[i])
			break ;
		limit++;
	}
	return (limit);
}

static	int	cut_end(char const *s1, char const *set)
{
	int	i;
	int	limit;

	limit = ft_strlen(s1) - 1;
	while (limit >= 0)
	{
		i = 0;
		while (set[i] && s1[limit] != set[i])
			i++;
		if (!set[i])
			break ;
		limit--;
	}
	return (limit);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = cut_start(s1, set);
	end = cut_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
/*
#include <stdio.h>
int	main(void)
{
	char h[] = "  hola   ";
	printf("%s", ft_strtrim(h, " "));
}*/