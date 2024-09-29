/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/29 17:25:49 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define WINDOW_HEIGHT 1024
#define WINDOW_WIDTH  1024
#define CUB_SIZE 24
#define PLAYER_SIZE 24

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	arguments_validation(argc, argv[1]);
	check_and_get_file(&map, argv[1]);
	map_validation(&map);
	get_map_matrix(&map);
	get_player_position(&map);
	set_textures_path(&map);
	set_rgb_color(&map);
	if (is_all_textures_ok(&map) == 0)
		error("Error\nWrong texture path\n");
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
	
	free_matrix(map.matrix);
	mlx_delete_texture(map.textures[NO]);
	mlx_delete_texture(map.textures[SO]);
	mlx_delete_texture(map.textures[EA]);
	mlx_delete_texture(map.textures[WE]);

	return (0);
}
