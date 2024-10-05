/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_05.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:43:01 by danielefrad       #+#    #+#             */
/*   Updated: 2024/10/05 15:01:39 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_has_empty_line(t_map *map)
{
	int	i;
	int	counter;
	int	has_empty_line;

	i = 0;
	counter = 0;
	while (map->backup_content[i] != '\0')
	{
		while (map->backup_content[i] == '\n')
			i++;
		counter++;
		while (map->backup_content[i] != '\n')
			i++;
		if (counter == 6)
			break ;
	}
	has_empty_line = check_empty_line(map, i);
	free(map->backup_content);
	map->backup_content = NULL;
	return (has_empty_line);
}

int	check_empty_line(t_map *map, int i)
{
	while (map->backup_content[i] == '\n')
		i++;
	while (map->backup_content[i] != '\0')
	{
		if (map->backup_content[i] == '\n'
			&& map->backup_content[i + 1] == '\n')
		{
			while (map->backup_content[i] == '\n')
				i++;
			if (map->backup_content[i] != '\0')
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	map_is_closed_by_walls(t_map *map)
{
	size_t	line;
	size_t	col;

	line = 6;
	while (map->matrix[line] != NULL)
	{
		col = 0;
		while (map->matrix[line][col] != '\0')
		{
			if (check_walls(map, line, col) == 0)
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

int	check_walls(t_map *map, size_t l, size_t c)
{
	char	**mtx;

	mtx = map->matrix;
	if (mtx[l][c] == '0' || ft_strchr("NSWE", mtx[l][c]))
	{
		if (mtx[l][c + 1] != '\0' && mtx[l][c + 1] == ' ')
			return (0);
		if (c != 0 && mtx[l][c - 1] == ' ')
			return (0);
		if (mtx[l + 1] != NULL && ft_strlen(mtx[l + 1]) > c
			&& mtx[l + 1][c] == ' ')
			return (0);
		if (l != 6 && ft_strlen(mtx[l - 1]) > c && mtx[l - 1][c] == ' ')
			return (0);
		if (mtx[l][c + 1] == '\0' || c == 0
			|| mtx[l + 1] == NULL
			|| ft_strlen(mtx[l + 1]) <= c
			|| l == 6 || ft_strlen(mtx[l - 1]) <= c)
			return (0);
	}
	return (1);
}
