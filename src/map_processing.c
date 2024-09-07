/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:03 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/07 15:47:22 by dfrade           ###   ########.fr       */
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

int get_color_from_str(t_map *map, char *rgb_str) 
{
    char **split;
    char **rgb_split;
    uint32_t color;
    int r, g, b;

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

    // Configura a cor em formato RGB (alfa 255)
    color = (uint32_t)(r << 16 | g << 8 | b | 0xFF000000);

    // Libera a memória alocada
    ft_free_matrix((void **)split);
    ft_free_matrix((void **)rgb_split);

    return (color);
}

void set_rgb_color(t_map *map)
{
    map->f_rgb_int = get_color_from_str(map, map->f_rgb_str);
    map->c_rgb_int = get_color_from_str(map, map->c_rgb_str);
}

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