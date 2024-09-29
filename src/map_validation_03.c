/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:43:01 by danielefrad       #+#    #+#             */
/*   Updated: 2024/09/29 13:46:23 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


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
		else
			i++;
	}
	free(map->backup_content);
	map->backup_content = NULL;
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

int	map_has_valid_nb_of_players(t_map *map)
{
	int	player_count;
	int	line;
	int	col;

	player_count = 0;
	line = 6;
	while (map->matrix[line])
	{
		col = 0;
		while (map->matrix[line][col])
		{
			if (ft_strchr("NSEW", map->matrix[line][col]) != NULL)
			{
				player_count++;
				if (player_count > 1)
					return (0);
			}
			col++;
		}
		line++;
	}
	if (player_count == 0)
		return (0);
	return (1);
}

int	map_is_closed_by_walls(t_map *map)
{
	int	line;
	int	col;

	line = 6;
	while (map->matrix[line] != NULL)
	{
		col = 0;
		while (map->matrix[line][col] != '\0')
		{
			if(map->matrix[line][col] == '0' || ft_strchr("NSWE", map->matrix[line][col]))
			{
				if (map->matrix[line][col + 1] != '\0' && map->matrix[line][col + 1] == ' ')
					return (0);
				if (col != 0 && map->matrix[line][col - 1] == ' ')
					return (0);
				if (map->matrix[line + 1] != NULL && ft_strlen(map->matrix[line + 1]) > (size_t)col && map->matrix[line + 1][col] == ' ')
					return (0);
				if (line != 6 && ft_strlen(map->matrix[line - 1]) > (size_t)col && map->matrix[line - 1][col] == ' ')
					return (0);
				if (map->matrix[line][col + 1] == '\0'
					|| col == 0
					|| map->matrix[line + 1] == NULL
					|| ft_strlen(map->matrix[line + 1]) <= (size_t)col
					|| line == 6
					|| ft_strlen(map->matrix[line - 1]) <= (size_t)col)
					return (0);
			}
			col++;
		}
		line++;
	}
	return (1);
}
