/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:40:10 by danielefrad       #+#    #+#             */
/*   Updated: 2024/10/05 12:08:47 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_direction_flag(t_flags *flag, char *line, char *direction, int *flag_val)
{
	if (ft_strncmp(line, direction, ft_strlen(direction)) == 0)
	{
		if (*flag_val == 1)
			return (0);
		*flag_val = 1;
	}
	return (1);
}

int	check_line_direction(char *line, t_flags *flag)
{
	if (!set_direction_flag(flag, line, "NO ", &flag->no_flag) ||
		!set_direction_flag(flag, line, "SO ", &flag->so_flag) ||
		!set_direction_flag(flag, line, "EA ", &flag->ea_flag) ||
		!set_direction_flag(flag, line, "WE ", &flag->we_flag) ||
		!set_direction_flag(flag, line, "C ", &flag->c_flag) ||
		!set_direction_flag(flag, line, "F ", &flag->f_flag))
	{
		return (0);
	}
	return (1);
}

int	all_directions_set(t_flags *flag)
{
	return (flag->no_flag == 1 && flag->so_flag == 1 &&
			flag->ea_flag == 1 && flag->we_flag == 1 &&
			flag->c_flag == 1 && flag->f_flag == 1);
}

int	file_has_all_directions(t_map *map)
{
	int		line;
	t_flags	flag;

	ft_bzero(&flag, sizeof(t_flags));
	line = 0;
	while (map->matrix[line] != NULL)
	{
		if (!check_line_direction(map->matrix[line], &flag))
			return (0);
		if (all_directions_set(&flag))
			return (1);
		line++;
	}
	return (0);
}

int	directions_has_all_paths(t_map *map)
{
	char	**str;
	int		line;
	int		col;
	int		flag;

	str = map->matrix;
	line = 5;
	flag = 0;
	while (line >= 0)
	{
		col = 3;
		while (str[line][col] != '\0' && str[line][col] == ' ')
			col++;
		if (str[line][col] != '\0')
			flag = 1;
		else
			flag = 0;
		if (flag == 0)
			return (0);
		line--;
	}
	return (1);
}

int	file_has_valid_rgb(t_map *map)
{
	char	**str;
	int		line;
	int		flag;

	str = map->matrix;
	flag = 0;
	line = 5;
	while (line >= 0)
	{
		if (str[line][0] == 'C' || str[line][0] == 'F')
		{
			if (rgb_has_valid_sintax(str[line]) == 1)
				flag = 1;
			else
				flag = 0;
			if (flag == 0)
				return (0);
		}
		line--;
	}
	return (1);
}

int	validate_commas(char *rgb, int *i)
{
	int comma = 0;

	while (rgb[*i] != '\0')
	{
		if (rgb[*i] == ',')
		{
			comma++;
			if (comma > 2)
				return (0);
			*i += 1;
		}
		*i += 1;
	}
	return (comma == 2);
}

int	validate_digits(char *rgb, int *i)
{
	int digit = 0;

	while (rgb[*i] != '\0' && rgb[*i] != ',')
	{
		if (!ft_isdigit(rgb[*i]))
			return (0);
		digit++;
		if (digit > 3)
			return (0);
		*i += 1;
	}
	return (digit > 0 && digit <= 3);
}

int	rgb_has_valid_sintax(char *rgb)
{
	int	i = 1;

	while (rgb[i] && rgb[i] == ' ')
		i++;
	if (rgb[i] == '\0')
		return (0);
	if (!validate_commas(rgb, &i))
		return (0);
	i = 1;
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
