/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/21 18:24:48 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WINDOW_HEIGHT 580
#define WINDOW_WIDTH  1024
#define CUB_SIZE 48
#define PLAYER_SIZE 24


t_core	*get_core(void)
{
	static t_core core;
	
	return(&core);
}



 void	print_map2D(t_map *map)
 {
 	int	line;
 	int col;
	
 	line = 0;
 	while (map->map_matrix[line] != NULL)
 	{
 		col = 0;
 		while (map->map_matrix[line][col] != '\0')
 		{
 			if (map->map_matrix[line][col] == '1')
 				print_square(get_core()->m_image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00000000);
 			else if (map->map_matrix[line][col] == '0')
 				print_square(get_core()->m_image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00FFFFFF);
 			else if (map->map_matrix[line][col] == 'S')
 				print_square(get_core()->m_image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00FF00FF);
 			col++;
 		}
 		line++;
 	}
 }

 void	reset_image(mlx_image_t *image)
 {
 	int x;
 	int y;

 	y = 0;
 	while( y < (int)image->height)
 	{
 		x = 0;
 		while (x < (int)image->width)
 		{
 			mlx_put_pixel(image, x, y, 0);
 			x++;
 		}
 		y++;
 	}
 }

 void	print_square(mlx_image_t *image, int size, int start_line, int start_col, int color)
 {
 	int x;
 	int y;

 	y = start_line;
 	while (y < size + start_line)
 	{
 		x = start_col;
 		while (x < size + start_col)
 		{
 			mlx_put_pixel(image, x, y, color);
 			x++;
 		}
 		y++;
 	}
 }


void	print_map(t_map map)
{
	ft_printf("\nCompiled successfully\n\n");
    ft_printf("Map matrix:\n");
    print_matrix(map.map_matrix);
    ft_printf("\n");
    ft_printf("Player position x: %d\n", map.p_position_line);
    ft_printf("Player position y: %d\n\n", map.p_position_col);
    ft_printf("Ceiling RGB value: %u\n", map.c_rgb_int);
    ft_printf("Floor RGB value: %u\n\n", map.f_rgb_int);
    
    ft_printf("Texture paths:\n");
	print_matrix(map.text_path);
	ft_printf("\n");
}
void draw_player(void *param)
{
	uint32_t color = *(uint32_t *)param; 

	for (uint32_t i = 0; i < get_core()->p_image->width; ++i)
	{
		for (uint32_t y = 0; y < get_core()->p_image->height; ++y)
		{
			mlx_put_pixel(get_core()->p_image, i, y, color);
		}
	}
}

void	move_player(void *param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		get_core()->p_image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		get_core()->p_image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		get_core()->p_image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		get_core()->p_image->instances[0].x += 5;
}


void	init(t_map *map)
{
	mlx_t				*mlx;
	uint32_t color = 0xFF00FF;
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", 1);
	get_core()->p_image = mlx_new_image(mlx, PLAYER_SIZE, PLAYER_SIZE);
	get_core()->m_image = mlx_new_image(mlx, CUB_SIZE, CUB_SIZE);
	mlx_image_to_window(mlx, get_core()->p_image, 0, 0);
	mlx_image_to_window(mlx, get_core()->m_image, 0, 0);
	//draw_player
	mlx_loop_hook(mlx, draw_player, &color);
	mlx_loop_hook(mlx, move_player, mlx);
	//print_map2D(map);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
}


int main(int argc, char **argv)
{
	t_map				map;
	// inicializa struct map
	ft_bzero(&map, sizeof(t_map));
	
	// file validation
	arguments_validation(argc, argv[1]);
	check_and_get_file(&map, argv[1]);
	map_validation(&map);
	
	// pós file validation, get just map matrix
	get_map_matrix(&map);
	get_player_position(&map);
	
	set_textures_path(&map);
	set_rgb_color(&map);
	if (is_all_textures_ok(&map) == 0)
		error("Error\nWrong texture path\n");
	
	// print map_matrix
	print_map(map);
	
	
	init(&map);
	
	// parte de free da validação do mapa
	free_matrix(map.matrix);
	mlx_delete_texture(map.textures[NO]);
	mlx_delete_texture(map.textures[SO]);
	mlx_delete_texture(map.textures[EA]);
	mlx_delete_texture(map.textures[WE]);

	return (0);
}
