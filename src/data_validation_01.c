/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:18:00 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/05 15:31:50 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arguments_validation(int argc, char *map_file)
{
	if (argc != 2)
		error("Error\nInvalid arguments\n");
	if (file_is_cub(map_file) == 0)
		error("Error\nInvalid map file\n");
}

int	file_is_cub(char *file_name)
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

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid map file\n");
		exit(1);
	}
	return (fd);
}

char	*read_file_content(int fd)
{
	ssize_t	i;
	char	buffer[5];
	char	*file_content;
	char	*temp;

	file_content = NULL;
	i = 1;
	while (i != 0)
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
	return (file_content);
}

int	check_and_get_file(t_map *map, char *file_name)
{
	int		fd;
	char	*file_content;
	char	*old_line;
	int		i;

	fd = open_file(file_name);
	file_content = read_file_content(fd);
	close(fd);
	map->backup_content = file_content;
	map->matrix = ft_split(file_content, '\n');
	if (!map->matrix)
	{
		ft_printf("Error\nFailed to split file content into lines\n");
		free(file_content);
		exit(1);
	}
	i = 0;
	while (i < 6 && map->matrix[i] != NULL)
	{
		old_line = map->matrix[i];
		map->matrix[i] = ft_strtrim(map->matrix[i], " \t");
		free(old_line);
		i++;
	}
	return (1);
}
