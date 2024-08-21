/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:22:41 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/21 11:57:38 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "../libft/headers/libft.h"
# include "../libft/headers/printf.h"
# include "../libft/headers/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_map {
	char **map;
	char **matrix;
	char *backup_content;
}	t_map;

typedef struct s_flags
{
	int no_flag;
	int so_flag;
	int ea_flag;
	int we_flag;
	int c_flag;
	int f_flag;
}	t_flags;

// map validation
int file_is_cub(char *file_name);
int check_and_get_file(t_map *map, char *file_name);
int file_has_all_directions(t_map *map);
int	file_has_all_paths(t_map *map);
int	file_has_valid_rgb(char *rgb);
int	rgb_has_valid_value(char *rgb);
int	map_has_empty_line(t_map *map);
int map_has_only_valid_chars(t_map *map);
int	map_has_valid_nb_of_players(t_map *map);
int	map_is_closed_by_walls(t_map *map);

// error
int error(char *msg);

#endif