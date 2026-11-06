/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:21:09 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/05 11:26:12 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	get_end_line(char *s, ssize_t nread)
{
	ssize_t	i;

	i = 0;
	if (nread == -1)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	else
	{
		while (i < nread && s[i] != '\n')
			i++;
	}
	if ((nread != -1 && i == nread) || !s[i])
		return (-1);
	return (i);
}

char	*add_to_line(char **s1, char *s2, ssize_t nread)
{
	size_t		len_s1;
	char		*res;

	if (!*s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(*s1);
	res = malloc((len_s1 + nread + 1) * sizeof(char));
	if (!res)
	{
		free(*s1);
		return (*s1 = NULL, NULL);
	}
	if (*s1)
		ft_strlcpy(res, *s1, len_s1 + 1);
	ft_strlcpy(res + len_s1, s2, nread + 1);
	free(*s1);
	*s1 = res;
	return (res);
}
