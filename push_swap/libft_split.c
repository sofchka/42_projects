/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:00:05 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/16 22:00:49 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_malloc(char **result, int position, size_t len)
{
	result[position] = malloc(len + 1);
	if (!result[position])
	{
		while (position >= 0)
			free(result[position--]);
		free(result);
		return (1);
	}
	return (0);
}

static int	split(char **result, char const *s, char c, int i)
{
	size_t	len;
	char	*start;

	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			++s;
		start = (char *)s;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len > 0)
		{
			if (ft_malloc(result, i, len))
				return (1);
			ft_strlcpy(result[i], start, len + 1);
			i++;
		}
	}
	result[i] = NULL;
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	size_t	len;

	len = word_count(s, c);
	if (!s || len == 0)
	{
		free(s);
		return (NULL);
	}
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	if (split(res, s, c, 0))
	{
		free(res);
		free(s);
		return (NULL);
	}
	free(s);
	return (res);
}
