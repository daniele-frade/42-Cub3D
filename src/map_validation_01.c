/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:18:00 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/29 13:45:13 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void arguments_validation(int argc, char *map_file)
{
	if (argc != 2)
		error("Error\nInvalid arguments\n");
	if (file_is_cub(map_file) == 0)
		error("Error\nInvalid map file\n");
}

void map_validation(t_map *map)
{
	if (file_has_all_directions(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid map file (wrong directions)\n");
	if (directions_has_all_paths(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid map file (wrong paths)\n");
	if (file_has_valid_rgb(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid map file (wrong rgb)\n");
	if (map_has_empty_line(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid map (empty line)\n");
	if (map_has_only_valid_chars(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid map characteres\n");
	if(map_has_valid_nb_of_players(map) == 0)
		free_and_exit(map->matrix, "Error\nInvalid number of player\n");
	if (map_is_closed_by_walls(map) == 0)
		free_and_exit(map->matrix, "Error\nMap is not closed by walls\n");
}

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
	close(fd);
	map->backup_content = file_content;
	map->matrix = ft_split(file_content, '\n');
	if (!map->matrix)
	{
		ft_printf("Error\nFailed to split file content into lines\n");
		free(file_content);
		exit(1);
	}
	return (1);
}
