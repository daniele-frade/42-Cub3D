/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:13:18 by danielefrad       #+#    #+#             */
/*   Updated: 2024/09/29 17:04:31 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	return (&str[i]);
}

void	set_textures_path(t_map *map)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(map->matrix[i], "NO", 2) == 0)
			map->text_path[NO] = skip_spaces(map->matrix[i] + 2);
		if (ft_strncmp(map->matrix[i], "SO", 2) == 0)
			map->text_path[SO] = skip_spaces(map->matrix[i] + 2);
		if (ft_strncmp(map->matrix[i], "EA", 2) == 0)
			map->text_path[EA] = skip_spaces(map->matrix[i] + 2);
		if (ft_strncmp(map->matrix[i], "WE", 2) == 0)
			map->text_path[WE] = skip_spaces(map->matrix[i] + 2);
		if (ft_strncmp(map->matrix[i], "F", 1) == 0)
			map->f_rgb_str = map->matrix[i];
		if (ft_strncmp(map->matrix[i], "C", 1) == 0)
			map->c_rgb_str = map->matrix[i];
		i++;
	}
}

int	load_textures_paths(t_map *map)
{
	set_textures_path(map);
	map->textures[NO] = mlx_load_png(map->text_path[NO]);
	map->textures[SO] = mlx_load_png(map->text_path[SO]);
	map->textures[EA] = mlx_load_png(map->text_path[WE]);
	map->textures[WE] = mlx_load_png(map->text_path[EA]);
	if (map->textures[NO] == NULL
		|| map->textures[SO] == NULL
		|| map->textures[WE] == NULL
		|| map->textures[EA] == NULL)
		return (0);
	return (1);
}

int	is_all_textures_ok(t_map *map)
{
	if (load_textures_paths(map) == 0)
		return (0);
	else
		return (1);
}
