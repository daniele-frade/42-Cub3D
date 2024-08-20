/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:18:00 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/20 19:24:57 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// valid char: 0, 1 and N, S, E or W for the playerś start, spaces are valid
// map closed/surrround by wall
// except the map(last):
	// each type of element can be separated by one or more empty line(s)
	// each type of element can be set in any order in the file
	// each type of information from an element can be separated by one or more space(s)
// each element firsts information is the type identifier (except the map):
	// NO ./path_to_the_north_texture
	// SO ./path_to_the_south_texture
	// WE ./path_to_the_west_texture
	// EA ./path_to_the_east_texture
	// F 220,100,0
	// C 225,30,0

#include "../includes/cub3d.h"


int file_is_cub(char *file_name)
{
	if (ft_strlen(file_name) < 5)
		return (0);
	if (file_name[ft_strlen(file_name) - 4] != '.')
		return (0);
	if (file_name[ft_strlen(file_name) - 3] != 'c')
		return (0);
	if (file_name[ft_strlen(file_name) - 2] != 'u')
		return (0);
	if (file_name[ft_strlen(file_name) - 1] != 'b')
		return (0);
	return (1);
}

int check_and_get_file(t_map *map, char *file_name)
{
	ssize_t i;
	int fd;
	char buffer[5];
	char *file_content;
	char *temp;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid map file\n");
		exit(1);
	}
	file_content = NULL;
	i = 1;
	while(i != 0)
	{
		i = read(fd, buffer, sizeof(buffer) - 1);
		if (i == -1)
		{
			ft_printf("Error\nInvalid map file\n");
			exit(1);
		}
		buffer[i] = '\0';
		temp = file_content;
		file_content = ft_strjoin(file_content, buffer);
		free(temp);
	}
	map->backup_content = file_content;
	
	map->matrix = ft_split(file_content, '\n');
	
	if (!map->matrix)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (1);
}

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

int	file_has_all_paths(t_map *map)
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
		if (str[line][0] == 'C' || str[line][0] == 'F')
		{
			if (file_has_valid_rgb(str[line]) == 1)	
				flag = 1;
			else
				flag = 0;	
		}
		else
		{
			col = 3;
			while(str[line][col] != '\0' && str[line][col] == ' ')
				col++;
			if (str[line][col] != '\0')	
				flag = 1;
			else
				flag = 0;
		}
		if (flag == 0)
			return (0);
		line--;
	}
	return (1);
}

int	file_has_valid_rgb(char *rgb)
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
		i++;
	}
	return (1);
}

int	map_has_empty_line(t_map *map)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while(map->backup_content[i] != '\0')
	{
		while (map->backup_content[i] == '\n')
			i++;
		counter++;
		while (map->backup_content[i] != '\n')
			i++;
		if (counter == 6)
			break ;
	}
	while (map->backup_content[i] == '\n')
		i++;
	while (map->backup_content[i] != '\0')
	{
		if (map->backup_content[i] == '\n' && map->backup_content[i + 1] == '\n')
		{
			while (map->backup_content[i] == '\n')
				i++;
			if (map->backup_content[i] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int map_has_only_valid_chars(t_map *map)
{
	int line;
	int col;
	
	line = 6;
	while(map->matrix[line] != NULL)
	{
		col = 0;
		while(map->matrix[line][col] != '\0')
		{
			if (map->matrix[line][col] != '0'
				&& map->matrix[line][col] != '1'
				&& map->matrix[line][col] != 'N'
				&& map->matrix[line][col] != 'S'
				&& map->matrix[line][col] != 'E'
				&& map->matrix[line][col] != 'W'
				&& map->matrix[line][col] != ' ')
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

int	map_is_closed_by_walls(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (map->map[line] != NULL)
	{
		col = 0;
		while (map->map[line][col] != '\0')
		{
			// if (something_is_wrong() == 1)
			// 	return (0);
			col++;
		}
		line++;
	}
	return (1);
}