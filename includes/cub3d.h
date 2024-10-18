/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:22:41 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/14 09:22:11 by danielefrad      ###   ########.fr       */
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

typedef struct s_map
{
	char			**matrix;
	char			*backup_content;
	char			**map_matrix;
	int				map_height;
	int				map_width;
	int				p_position_line;
	int				p_position_col;
	char			*text_path[5];
	char			*f_rgb_str;
	char			*c_rgb_str;
	uint32_t		f_rgb_int;
	uint32_t		c_rgb_int;
	mlx_texture_t	*textures[4];
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
int			file_is_cub(char *file_name);
int			open_file(char *file_name);
char		*read_file_content(int fd);
int			check_and_get_file(t_map *map, char *file_name);
void		data_validation(t_map *map);
int			set_direction_flag(char *line, char *direct, int *flag_val);
int			check_line_direction(char *line, t_flags *flag);
int			all_directions_set(t_flags *flag);
int			file_has_all_directions(t_map *map);
int			directions_has_all_paths(t_map *map);
int			file_has_valid_rgb(t_map *map);
int			file_has_valid_rgb(t_map *map);
int			validate_commas(char *rgb, int i);
int			validate_digits(char *rgb, int *i);
int			rgb_has_valid_sintax(char *rgb);
int			rgb_has_valid_value(char *rgb);
int			map_has_empty_line(t_map *map);
int			check_empty_line(t_map *map, int i);
int			map_has_only_valid_chars(t_map *map);
int			map_has_valid_nb_of_players(t_map *map);
int			map_is_closed_by_walls(t_map *map);
int			check_walls(t_map *map, size_t l, size_t c);

// map processing
void		get_map_matrix(t_map *map);
void		get_player_position(t_map *map);
uint32_t	get_rgb_value(int r, int g, int b, int a);
void		get_color_from_str(char *rgb_str, uint32_t *rgb_array);
void		set_rgb_color(t_map *map);
char		*skip_spaces(char *str);
void		set_textures_path(t_map *map);
int			load_textures_paths(t_map *map);
int			is_all_textures_ok(t_map *map);
void		get_map_size(t_map *map);

// error and free
int			error(char *msg);
void		free_and_exit(t_map *map, char *msg);
void		free_matrix(char **matrix);
void		free_texture(t_map *map);
void		finalize_and_cleanup(t_map *map);

// MLX
void		key_data(mlx_key_data_t data, void *map);

// print info (to delete)
void		print_matrix(char **matrix);
void		print_info(t_map *map);

#endif