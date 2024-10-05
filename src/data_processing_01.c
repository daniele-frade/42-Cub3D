/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:03 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/29 17:15:36 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"  

void	get_map_matrix(t_map *map)
{
	map->map_matrix = &map->matrix[6];
}

void	get_player_position(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (map->map_matrix[line])
	{
		col = 0;
		while (map->map_matrix[line][col])
		{
			if (map->map_matrix[line][col] == 'N'
				|| map->map_matrix[line][col] == 'S'
				|| map->map_matrix[line][col] == 'W'
				|| map->map_matrix[line][col] == 'E')
			{
				map->p_position_line = line;
				map->p_position_col = col;
				return ;
			}
			col++;
		}
		line++;
	}
}

uint32_t	get_rgb_value(int r, int g, int b, int a)
{
	uint32_t	color;

	color = (uint32_t)(r << 24 | g << 16 | b << 8 | a);
	return (color);
}

void	get_color_from_str(char *rgb_str, uint32_t *rgb_array)
{
	char	**split;
	char	**rgb_split;

	split = ft_split(rgb_str, ' ');
	if (split == NULL || split[1] == NULL)
		return ;
	rgb_split = ft_split(split[1], ',');
	if (rgb_split == NULL
		|| rgb_split[0] == NULL
		|| rgb_split[1] == NULL
		|| rgb_split[2] == NULL)
	{
		free_matrix(split);
		return ;
	}
	*rgb_array = get_rgb_value(ft_atoi(rgb_split[0]), ft_atoi(rgb_split[1]), ft_atoi(rgb_split[2]), 255);
	free_matrix(split);
	free_matrix(rgb_split);
}

void	set_rgb_color(t_map *map)
{
	get_color_from_str(map->f_rgb_str, &map->f_rgb_int);
	get_color_from_str(map->c_rgb_str, &map->c_rgb_int);
}
