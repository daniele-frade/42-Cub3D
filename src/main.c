/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/01 18:43:27 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	fill_top_bottom(t_mlx *mlx, int color_top, int color_bottom)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	half_height;

	half_height = mlx->image->height / 2;
	y = 0;
	while (y < mlx->image->height)
	{
		x = 0;
		while (x < mlx->image->width)
		{
			if (y < half_height)
				mlx_put_pixel(mlx->image, x, y, color_top);
			else
				mlx_put_pixel(mlx->image, x, y, color_bottom);
			x++;
		}
		y++;
	}
}

void	init_player(void)
{
	t_player *player;
	player = get_player();

	player->p_x = get_map()->p_position_col * CUB_SIZE + CUB_SIZE / 2;
	player->p_y = get_map()->p_position_line * CUB_SIZE + CUB_SIZE / 2;
	player->fov_rd = (FOV * PI) / 180; // calculo de campo de visão em radiandos
}

void game_loop(void *param)
{
	(void)param;
	t_mlx *mlx = get_mlx();
	t_map *map;
	map = get_map();
	mlx_delete_image(mlx->mlx_ptr, mlx->image);
	mlx->image = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx->mlx_ptr, mlx->image, 0, 0);
	uint32_t  ceil = map->c_rgb_int;
	uint32_t  floor = map->f_rgb_int;
	fill_top_bottom(mlx, ceil, floor);
}

void	init(void)
{
	t_mlx	*mlx;
	mlx = get_mlx();
	mlx->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", 0);
	mlx_loop_hook(mlx->mlx_ptr, &game_loop, NULL);
	init_player();
	mlx_loop(mlx->mlx_ptr);
	mlx_terminate(mlx->mlx_ptr);
	
}

int	main(int argc, char **argv)
{
	t_map	*map;
	map = get_map();
	// inicializa struct map
	ft_bzero(map, sizeof(t_map));
	// file validation
	arguments_validation(argc, argv[1]);
	check_and_get_file(map, argv[1]);
	map_validation(map);
	// pós file validation, get just map matrix
	get_map_matrix(map);
	get_player_position(map);
	set_textures_path(map);
	set_rgb_color(map);
	if (is_all_textures_ok(map) == 0)
		error("Error\nWrong texture path\n");
	// print map_matrix
	print_map(*map);
	init();
	// parte de free da validação do mapa
	free_matrix(map->matrix);
	mlx_delete_texture(map->textures[NO]);
	mlx_delete_texture(map->textures[SO]);
	mlx_delete_texture(map->textures[EA]);
	mlx_delete_texture(map->textures[WE]);
	return (0);
}
