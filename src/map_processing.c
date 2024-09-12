/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:03 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/12 19:54:29 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"  

void    get_map_matrix(t_map *map)
{
	map->map_matrix = &map->matrix[6];
}

// 1 - player position

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

// 2 - rgb value

uint32_t    get_rgb_value(int r, int g, int b, int a)
{
    uint32_t    color;
    
    color = (uint32_t)(r << 24 | g << 16 | b << 8 | a);
    return (color);
    
}

void    get_color_from_str(char *rgb_str, uint32_t *rgb_array) 
{
    char **split;
    char **rgb_split;

    // Divide a string para separar o identificador e a parte RGB
    split = ft_split(rgb_str, ' ');
    if (split == NULL || split[1] == NULL)
        return ;

    // Divide a parte RGB usando vírgula
    rgb_split = ft_split(split[1], ',');
    if (rgb_split == NULL || rgb_split[0] == NULL || rgb_split[1] == NULL || rgb_split[2] == NULL)
    {
        free_matrix(split);
        return ;
    }

    // Converte os valores RGB para inteiros
    *rgb_array = get_rgb_value(ft_atoi(rgb_split[0]), ft_atoi(rgb_split[1]), ft_atoi(rgb_split[2]), 255);

    // Libera a memória alocada
    free_matrix(split);
    free_matrix(rgb_split);
}

void set_rgb_color(t_map *map)
{
    get_color_from_str(map->f_rgb_str, &map->f_rgb_int);
    get_color_from_str(map->c_rgb_str, &map->c_rgb_int);
}

// 3 - get texture paths and file:

char *skip_spaces(char *str)
{
    int i;

    i = 0;
    while(str[i] == 32)
        i++;
    return (&str[i]);
}

void set_textures_path(t_map *map) //colocar as texturas nos indices correto
{
    int i;
    
    i = 0;
    while (i < 7)
    {
        if (ft_strncmp(map->matrix[i], "NO", 2) == 0)
            map->text_path[NO] = skip_spaces(map->matrix[i] + 2); // pula os char de direção
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

int load_textures_paths(t_map *map)
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
int is_all_textures_ok(t_map *map)
{
    if (load_textures_paths(map) == 0)
        return (0);
    else
        return (1);
}