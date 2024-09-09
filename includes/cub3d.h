/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:22:41 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/09 19:35:07 by dfrade           ###   ########.fr       */
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
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

enum e_directions
{
	NO = 0,
	SO,
	EA,
	WE
};

typedef struct s_map {
	char			**matrix;
	char			*backup_content;
	char			**map_matrix;
	int				p_position_line;
	int				p_position_col;
	char			*textures[4];
	char			*f_rgb_str;
	char			*c_rgb_str;
	uint32_t		f_rgb_int;
	uint32_t		c_rgb_int;
	char			**directions;
	mlx_texture_t	*text_path[4]; // para mlx
}	t_map;

typedef struct s_flags
{
	int				no_flag;
	int				so_flag;
	int				ea_flag;
	int				we_flag;
	int				c_flag;
	int				f_flag;
}	t_flags;

// map validation
void		arguments_validation(int argc, char *map_file);
void		map_validation(t_map *map);
int			file_is_cub(char *file_name);
int			check_and_get_file(t_map *map, char *file_name);
int			file_has_all_directions(t_map *map);
int			directions_has_all_paths(t_map *map);
int			file_has_valid_rgb(t_map *map);
int			rgb_has_valid_sintax(char *rgb);
int			rgb_has_valid_value(char *rgb);
int			map_has_empty_line(t_map *map);
int			map_has_only_valid_chars(t_map *map);
int			map_has_valid_nb_of_players(t_map *map);
int			map_is_closed_by_walls(t_map *map);

// map processing
void		get_map_matrix(t_map *map);

void		get_player_position(t_map *map);

uint32_t	get_color_from_rgb(int r, int g, int b, int a);
void		get_color_from_str(t_map *map, char *rgb_str, uint32_t *rgb_array);
void		set_rgb_color(t_map *map);

// error
void		free_and_exit(char **matrix, char *msg);
void		free_matrix(char **matrix);
int			error(char *msg);
void		print_matrix(char **matrix);


// MLX
void 		key_data(mlx_key_data_t data, void *map);
void		print_map2D(t_map *map);
void		print_square(mlx_image_t *image, int size, int start_line, int start_col, int color);

#endif