/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:40:10 by danielefrad       #+#    #+#             */
/*   Updated: 2024/09/29 13:46:19 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int file_has_all_directions(t_map *map)
{
	int	line;
	char **str;
	t_flags flag;

	ft_bzero(&flag, sizeof(t_flags));
	str = map->matrix;
	line = 0;
	while(str[line] != NULL)
	{
		if (ft_strncmp(str[line], "NO ", 3) == 0)
		{
			if (flag.no_flag == 1)
				return (0);
			flag.no_flag = 1;
		}
		else if (ft_strncmp(str[line], "SO ", 3) == 0)
		{
			if (flag.so_flag == 1)
				return (0);
			flag.so_flag = 1;
		}
		else if (ft_strncmp(str[line], "EA ", 3) == 0)
		{
			if (flag.ea_flag == 1)
				return (0);
			flag.ea_flag = 1;	
		}
		else if (ft_strncmp(str[line], "WE ", 3) == 0)
		{
			if (flag.we_flag == 1)
				return (0);
			flag.we_flag = 1;
		}
		else if (ft_strncmp(str[line], "C ", 2) == 0)
		{
			if (flag.c_flag == 1)
				return (0);
			flag.c_flag = 1;
		}
		else if (ft_strncmp(str[line], "F ", 2) == 0)
		{
			if (flag.f_flag == 1)
				return (0);
			flag.f_flag = 1;
		}
		else
			return (0);
		if (flag.no_flag == 1 && flag.so_flag == 1 && flag.ea_flag == 1 && flag.we_flag == 1 && flag.c_flag == 1 && flag.f_flag == 1)
			return (1);
		line++;
	}
	return (0);
}

int	directions_has_all_paths(t_map *map)
{
	char **str;
	int line;
	int col;
	int	flag;

	str = map->matrix;
	line = 5;
	flag = 0;
	while(line >= 0)
	{
		col = 3;
		while(str[line][col] != '\0' && str[line][col] == ' ')
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

int file_has_valid_rgb(t_map *map)
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

int	rgb_has_valid_sintax(char *rgb)
{
	int		i;
	int		j;
	int		comma;
	int		digit;

	i = 1;
	comma = 0;
	digit = 0;
	while (rgb[i] && rgb[i] == ' ')
		i++;
	if (rgb[i] == '\0')
		return (0);
	j = i;	
	while (rgb[i] != '\0')
	{
		if (rgb[i] == ',')
		{
			digit = 0;
			comma++;
			if (comma > 2)
				return (0);
			i++;
		}
		if (ft_isdigit(rgb[i]) == 0)
			return (0);
		digit++;
		if (digit > 3)
			return (0);
		i++;
	}
	if (comma < 2)
		return (0);
	if (rgb_has_valid_value(&rgb[j]))
		return (1);
	return (0);
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
