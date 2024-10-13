/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_04.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:40:10 by danielefrad       #+#    #+#             */
/*   Updated: 2024/10/12 20:46:15 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	file_has_valid_rgb(t_map *map)
{
	char	**str;
	int		line;

	str = map->matrix;
	line = 5;
	while (line >= 0)
	{
		if (str[line][0] == 'C' || str[line][0] == 'F')
		{
			if (rgb_has_valid_sintax(str[line]) == 0)
				return (0);
		}
		line--;
	}
	return (1);
}

int	validate_commas(char *rgb, int i)
{
	int	comma;

	comma = 0;
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
		{
			comma++;
			if (comma > 2)
				return (0);
			i += 1;
		}
		i += 1;
	}
	if (comma == 2)
		return (1);
	else
		return (0);
}

int	validate_digits(char *rgb, int *i)
{
	int	digit;

	digit = 0;
	while (rgb[*i] != '\0' && rgb[*i] != ',')
	{
		if (!ft_isdigit(rgb[*i]))
			return (0);
		digit++;
		if (digit > 3)
			return (0);
		*i += 1;
	}
	if (digit > 0 && digit <= 3)
		return (1);
	else
		return (0);
}

int	rgb_has_valid_sintax(char *rgb)
{
	int	i;

	i = 1;
	while (rgb[i] && rgb[i] == ' ')
		i++;
	if (rgb[i] == '\0')
		return (0);
	if (!validate_commas(rgb, i))
		return (0);
	while (rgb[i] != '\0')
	{
		if (!validate_digits(rgb, &i))
			return (0);
		if (rgb[i] == ',')
			i++;
	}
	return (rgb_has_valid_value(&rgb[1]));
}

int	rgb_has_valid_value(char *rgb)
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		value = ft_atoi(rgb);
		if (!(value >= 0 && value <= 255))
			return (0);
		while (*rgb && *rgb != ',')
			rgb++;
		rgb++;
		i++;
	}
	return (1);
}
