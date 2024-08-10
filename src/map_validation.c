/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:18:00 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/10 19:55:21 by dfrade           ###   ########.fr       */
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


int map_is_cub_file(char *file_name)
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

int check_and_get_map(t_map *map, char *file_name)
{
	ssize_t i;
	int fd;
	char buffer[5];
	char **matrix;
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
	
	matrix = ft_split(file_content, '\n');
	
	if (!matrix)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (1);
}




int map_has_only_valid_chars(t_map *map)
{
	int line;
	int col;
	
	line = 0;
	while(map->map[line] != NULL)
	{
		col = 0;
		while(map->map[line][col] != '\0')
		{
			if (map->map[line][col] != '0'
				&& map->map[line][col] != '1'
				&& map->map[line][col] != 'N'
				&& map->map[line][col] != 'S'
				&& map->map[line][col] != 'E'
				&& map->map[line][col] != 'W'
				&& map->map[line][col] != ' ')
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