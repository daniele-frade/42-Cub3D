/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:30:37 by dfrade            #+#    #+#             */
/*   Updated: 2023/09/18 19:31:45 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substr_count(const char *s, int c)
{
	int	str_nb;
	int	i;

	str_nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
		}		
		else if (s[i] != c)
		{
			str_nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (str_nb);
}

static size_t	ft_substr_len(const char *s, int c)
{
	int	str_len;
	int	i;

	str_len = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str_len++;
		i++;
	}
	return (str_len);
}

char	**ft_split(char const *s, char c)
{
	char	**set_str;
	char	*sub_str;
	int		str_len;
	int		i;
	int		j;

	set_str = (char **) ft_calloc((ft_substr_count(s, c) + 1), sizeof(char *));
	i = 0;
	j = 0;
	if (!set_str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			str_len = ft_substr_len(&s[i], c);
			sub_str = malloc((ft_substr_len(&s[i], c) + 1) * sizeof(char));
			ft_strlcpy(sub_str, &s[i], str_len + 1);
			set_str[j++] = sub_str;
			i = i + str_len;
		}
	}
	return (set_str);
}
