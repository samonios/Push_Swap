/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 16:50:34 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 16:33:16 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordln(const char *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static void	*ft_free_matrix(char **res, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static	int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i])
	{
		if (!is_word && s[i] != c)
		{
			count++;
			is_word = 1;
		}
		if (is_word && (s[i] == c))
			is_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_words;
	int		filled;
	int		ln;
	char	**res;

	num_words = ft_count_words(s, c);
	res = (char **) malloc((num_words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	filled = 0;
	i = 0;
	while (filled < num_words)
	{
		while (s[i] == c && s[i])
			i++;
		ln = ft_wordln(s, i, c);
		res[filled] = ft_substr(s, i, ln);
		if (!res[filled])
			return (ft_free_matrix(res, filled));
		filled++;
		i += ln;
	}
	res[filled] = NULL;
	return (res);
}
