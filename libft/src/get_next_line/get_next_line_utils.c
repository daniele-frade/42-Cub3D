/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:00:46 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/18 14:09:31 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	if (dest == NULL || src == NULL)
		return (NULL);
	index = 0;
	while ((src[index] != '\0') && (index < n))
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i_result;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	i_result = 0;
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
		result[i_result++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		result[i_result++] = s2[i++];
	result[i_result] = '\0';
	return (result);
}
