/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/10 14:28:20 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WINDOW_HEIGHT 1024
#define WINDOW_WIDTH  1024
#define CUB_SIZE 24
#define PLAYER_SIZE 24

// static mlx_image_t	*image;

// void	print_map2D(t_map *map)
// {
// 	int	line;
// 	int col;
	
// 	line = 0;
// 	while (map->map_matrix[line] != NULL)
// 	{
// 		col = 0;
// 		while (map->map_matrix[line][col] != '\0')
// 		{
// 			if (map->map_matrix[line][col] == '1')
// 				print_square(image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00000000);
// 			else if (map->map_matrix[line][col] == '0')
// 				print_square(image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00FFFFFF);
// 			else if (map->map_matrix[line][col] == 'S')
// 				print_square(image, CUB_SIZE, line * CUB_SIZE, col * CUB_SIZE, 0x00FF00FF);
// 			col++;
// 		}
// 		line++;
// 	}
// }

// void	reset_image(mlx_image_t *image)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while( y < (int)image->height)
// 	{
// 		x = 0;
// 		while (x < (int)image->width)
// 		{
// 			mlx_put_pixel(image, x, y, 0);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	print_square(mlx_image_t *image, int size, int start_line, int start_col, int color)
// {
// 	int x;
// 	int y;

// 	y = start_line;
// 	while (y < size + start_line)
// 	{
// 		x = start_col;
// 		while (x < size + start_col)
// 		{
// 			mlx_put_pixel(image, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void key_data(mlx_key_data_t data, void *map_struct)
// {
// 	t_map *map = (t_map*)map_struct;
	
// 	if (data.key == MLX_KEY_W && data.action == MLX_PRESS)
// 		map->p_position_line -= 1;
// 	if (data.key == MLX_KEY_S && data.action == MLX_PRESS)
// 		map->p_position_line += 1;
// 	if (data.key == MLX_KEY_A && data.action == MLX_PRESS)
// 		map->p_position_col -= 1;
// 	if (data.key == MLX_KEY_D && data.action == MLX_PRESS)
// 		map->p_position_col += 1;
// 	reset_image(image);
// 	print_map2D(map);
// 	print_square(image, PLAYER_SIZE, map->p_position_line * PLAYER_SIZE, map->p_position_col * PLAYER_SIZE, 0x00FF00FF);
// }

int main(int argc, char **argv)
{
	t_map				map;
	// mlx_t				*mlx;

	// inicializa struct map
	ft_bzero(&map, sizeof(t_map));
	
	// file validation
	arguments_validation(argc, argv[1]);
	check_and_get_file(&map, argv[1]);
	map_validation(&map);
	
	// pós file validation, get just map matrix
	get_map_matrix(&map);
	get_player_position(&map);
	

	set_rgb_color(&map);
	if (is_all_textures_ok(&map) == 0)
		error("Error\nWrong texture path\n");
	
	// print map_matrix
	ft_printf("\nCompiled successfully\n\n");
    ft_printf("Map matrix:\n");
    print_matrix(map.map_matrix);
    ft_printf("\n");
    ft_printf("Player position x: %d\n", map.p_position_line);
    ft_printf("Player position y: %d\n", map.p_position_col);
    ft_printf("Ceiling RGB value: %u\n", map.c_rgb_int);
    ft_printf("Floor RGB value: %u\n", map.f_rgb_int);
    
    ft_printf("Texture paths:\n");
	print_matrix(map.text_path);
	ft_printf("\n");
	
	// abrindo a janela
	// mlx = mlx_init(WINDOW_HEIGHT, WINDOW_WIDTH, "Cub3D", true);
	
	// definindo uma imagem na janela
	// image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	// print imagem na janela (fundo, primeiro player)
	// mlx_image_to_window(mlx, image, 0, 0);
	
	// print map
	// print_map2D(&map);
	
	// modificar onde esta o jogador no mapa
	
	// print player
	// print_square(image, PLAYER_SIZE, map.p_position_line * PLAYER_SIZE, map.p_position_col * PLAYER_SIZE, 0x00FF00FF);
	
	// print movimentos chamando key_data
	// mlx_key_hook(mlx, key_data, &map);
		
	// mantendo a janela da MLX aberta
	// mlx_loop(mlx);
	
	// fechando a janela da MLX
	// mlx_terminate(mlx);
	
	
	// parte de free da validação do mapa
	free_matrix(map.matrix);

	//ft_printf("Compilou\n");
	return (0);
}
