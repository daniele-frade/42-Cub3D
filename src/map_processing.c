/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:03 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/01 17:23:11 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"  

void	get_map_matrix(t_map *map)
{
	map->map_matrix = &map->matrix[6];
}

void get_player_position(t_map *map)
{
    int line;
    int col;
 
    line = 0;    
    puts("Aqui");
    while (map->map_matrix[line])
    {
        col = 0;
        while (map->map_matrix[line][col])
        {
            if (map->map_matrix[line][col] == 'N' || map->map_matrix[line][col] == 'S' || map->map_matrix[line][col] == 'W' || map->map_matrix[line][col] == 'E')
            {
                map->p_position_line = line;
                map->p_position_col = col;
                return ;           
            }
            col++;
        }
        line++;
    }
    puts("Fim");
}

// void load_textures_paths(t_map *map)
// {
//     // Implementação
// }

// void set_floor_and_ceiling_color(t_map *map)
// {
//     // Implementação
// }
