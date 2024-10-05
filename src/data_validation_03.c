/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_03.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:18:25 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/05 14:27:07 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	map_has_only_valid_chars(t_map *map)
{
	int	line;
	int	col;

	line = 6;
	while (map->matrix[line] != NULL)
	{
		col = 0;
		while (map->matrix[line][col] != '\0')
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
