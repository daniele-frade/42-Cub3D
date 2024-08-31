/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/31 18:11:16 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WINDOW_HEIGHT 512
#define WINDOW_WIDTH  512
#define CUB_SIZE 64

int map[] = {
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
 	1,0,1,0,0,0,0,1,
 	1,0,1,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,1,0,1,
 	1,0,0,0,0,0,0,1,
 	1,1,1,1,1,1,1,1,
};

int	player_x;
int player_y;
static mlx_image_t*	image;

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

void	print_square(mlx_image_t *image, int size, int start_x, int start_y)
{
	int x;
	int y;

	reset_image(image);
	y = start_y;
	while (y < size + start_y)
	{
		x = start_x;
		while (x < size + start_x)
		{
			mlx_put_pixel(image, x, y, 0x00FF00FF);
			x++;
		}
		y++;
	}
}

void key_data(mlx_key_data_t data, void *params)
{
	(void)params;
	if (data.key == MLX_KEY_W && data.action == MLX_PRESS)
		player_y = player_y	- 10;
	print_square(image, CUB_SIZE, player_x, player_y);
	if (data.key == MLX_KEY_S && data.action == MLX_PRESS)
		player_y = player_y	+ 10;
	print_square(image, CUB_SIZE, player_x, player_y);
	if (data.key == MLX_KEY_A && data.action == MLX_PRESS)
		player_x = player_x	- 10;
	print_square(image, CUB_SIZE, player_x, player_y);
	if (data.key == MLX_KEY_D && data.action == MLX_PRESS)
		player_x = player_x	+ 10;
	print_square(image, CUB_SIZE, player_x, player_y);
}
int main(int argc, char **argv)
{
	t_map				map;
	mlx_t				*mlx;

	player_x = 50;
	player_y = 50;

	ft_bzero(&map, sizeof(t_map));
	arguments_validation(argc, argv[1]);
	check_and_get_file(&map, argv[1]);
	map_validation(&map);
	
	// abrindo a janela
	mlx = mlx_init(WINDOW_HEIGHT, WINDOW_WIDTH, "Cub3D", true);
	// definindo uma imagem na janela
	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// renderizando uma imagem na janela
	mlx_image_to_window(mlx, image, 0, 0);
	print_square(image, CUB_SIZE, player_x, player_y);
	mlx_key_hook(mlx, key_data, NULL);
	
	
	// mantendo a janela da MLX aberta
	mlx_loop(mlx);
	
	// fechando a janela da MLX
	mlx_terminate(mlx);
	
	
	// parte de free da validação do mapa
	free_matrix(map.matrix);
	
	//print_matrix(&map);
	//ft_printf("Compilou\n");
	return (0);
}
