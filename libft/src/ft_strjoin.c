/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:56:41 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/10 19:51:12 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i_result;
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i_result = 0;
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		result[i_result] = s1[i];
		i++;
		i_result++;
	}
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
	{
		result[i_result] = s2[i];
		i++;
		i_result++;
	}
	result[i_result] = '\0';
	return (result);
}
