/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/25 17:31:53 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_matrix(t_map *map)
{
	int i = 0;
	char **matrix = map->matrix;
	
	while(matrix[i])
		ft_printf("%s\n", matrix[i++]);
}

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	puts("Entrei aqui");

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int main(int argc, char **argv)
{
	t_map	map;
	mlx_t	*mlx;

	ft_bzero(&map, sizeof(t_map));
	
	if (argc != 2)
		error("Error\nInvalid arguments\n");
	
	if (file_is_cub(argv[1]) == 0)
		error("Error\nInvalid map file\n");
	
	check_and_get_file(&map, argv[1]);
	
	if (file_has_all_directions(&map) == 0)
		error("Error\nInvalid map file (wrong directions)\n");

	if (file_has_all_paths(&map) == 0)
		error("Error\nInvalid map file (wrong paths)\n");

	if (map_has_empty_line(&map) == 0)
		error("Error\nInvalid map (empty line)\n");
	
	if (map_has_only_valid_chars(&map) == 0)
		error("Error\nInvalid map characteres\n");
	
	if(map_has_valid_nb_of_players(&map) == 0)
		error("Error\nInvalid number of player\n");

	if (map_is_closed_by_walls(&map) == 0)
		error("Error\nMap is not closed by walls\n");
	
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	image = mlx_new_image(mlx, 128, 128);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	
	//print_matrix(&map);
	//ft_printf("Compilou\n");
	return (0);
}
