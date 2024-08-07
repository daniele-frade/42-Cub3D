/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:48:26 by dfrade            #+#    #+#             */
/*   Updated: 2023/09/18 19:32:29 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*last_occ;

	len = ft_strlen(s);
	last_occ = (char *)(s + len);
	while (*last_occ != (unsigned char)c && len)
	{
		last_occ--;
		len--;
	}
	if (*last_occ == (unsigned char)c)
		return (last_occ);
	return (0);
}
