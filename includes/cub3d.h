/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:22:41 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/17 18:34:26 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/headers/libft.h"
# include "../libft/headers/printf.h"
# include "../libft/headers/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define CUB_SIZE 16
# define PLAYER_SPEED 2
# define FOV 60
# define ROTATION_SPEED 0.045

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

typedef struct s_mlx
{
	mlx_image_t		*image;
	mlx_image_t		*image_map;
	mlx_t			*mlx_ptr;
}					t_mlx;

typedef struct s_player
{
	int				p_x;
	int				p_y;
	double			angle;
	float			fov_rd;
	int				rot;
	int				l_r;
	int				u_d;
}					t_player;

typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	double	x;
	double	y;
	int		flag;
}					t_ray;

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

// getters
t_mlx		*get_mlx(void);
t_player	*get_player(void);
t_map		*get_map(void);
t_ray		*get_ray(void);

// MLX
void		key_data(mlx_key_data_t data, void *map);
void		print_map2D(t_map *map);

// process map
void		fill_top_bottom(int t_pixel, int b_pixel, int ray);
void		my_mlx_pixel_put(mlx_image_t *image, int x, int y,
				int color);

// render
void		draw_wall_texture(int ray, int t_pixel, int b_pixel, \
				double wall_height);
float		nor_angle(float angle);
int			reverse_bytes(int c);
double		get_xo(mlx_texture_t *texture);
int			inter_check(float angle, float *inter, float *step, int is_horizon);

// raycaster
void		raycaster(void);
int			unit_circle(float angle, char c);
void		render_wall(int ray);

// init
void		init(void);

// move
void		mlx_key(mlx_key_data_t keydata, void *param);
void		hook(double move_x, double move_y);
void		rotate_player(int i);

#endif