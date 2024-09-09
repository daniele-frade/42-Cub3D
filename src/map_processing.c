/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:03 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/09 18:27:54 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"  

void    get_map_matrix(t_map *map)
{
	map->map_matrix = &map->matrix[6];
}

void    get_player_position(t_map *map)
{
    int line;
    int col;
 
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

uint32_t    get_color_from_rgb(int r, int g, int b, int a)
{
    uint32_t    color;
    
    color = (uint32_t)(r << 24 | g << 16 | b << 8 | a);
    return (color);
    
}

void    get_color_from_str(t_map *map, char *rgb_str) 
{
    char **split;
    char **rgb_split;

    // Verifica se a string é válida
    if (rgb_str == NULL)
        return (NULL);

    // Divide a string para separar o identificador e a parte RGB
    split = ft_split(rgb_str, ' ');
    if (split == NULL || split[1] == NULL)
        return (NULL);

    // Divide a parte RGB usando vírgula
    rgb_split = ft_split(split[1], ',');
    if (rgb_split == NULL || rgb_split[0] == NULL || rgb_split[1] == NULL || rgb_split[2] == NULL)
        return (NULL);

    // Converte os valores RGB para inteiros
    map->r = ft_atoi(rgb_split[0]);
    map->g = ft_atoi(rgb_split[1]);
    map->b = ft_atoi(rgb_split[2]);

    // Libera a memória alocada
    ft_free_matrix((void **)split);
    ft_free_matrix((void **)rgb_split);
}

void set_rgb_color(t_map *map)
{
    get_color_from_rgb(map->r, map->g, map->b, 0xFF);
    get_color_from_str(map, map->f_rgb_str);
    get_color_from_str(map, map->c_rgb_str);
}

// antes tenho q verificar se consigo abrir o arquivo

int load_textures_paths(t_map *map)
{
	map->text_path[NO] = mlx_load_png(map->directions[NO]);
	map->text_path[SO] = mlx_load_png(map->directions[SO]);
	map->text_path[EA] = mlx_load_png(map->directions[WE]);
	map->text_path[WE] = mlx_load_png(map->directions[EA]);
	if (map->text_path[NO] == NULL || map->text_path[SO] == NULL || map->text_path[WE] == NULL
		|| map->text_path[EA] == NULL)
		return (0);
    return (1);
}
int is_all_textures_ok(t_map *map)
{
    if (load_textures_paths(map) == 0)
        error("Error\nWrong texture path\n");
    else
        return (1);
}