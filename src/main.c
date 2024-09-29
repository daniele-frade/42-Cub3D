/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/29 18:19:57 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init(void)
{
	t_mlx	*mlx;
	mlx = get_mlx();
	mlx->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", 0);
}

int	main(int argc, char **argv)
{
	t_map	map;

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
	init();
	// parte de free da validação do mapa
	free_matrix(map.matrix);
	mlx_delete_texture(map.textures[NO]);
	mlx_delete_texture(map.textures[SO]);
	mlx_delete_texture(map.textures[EA]);
	mlx_delete_texture(map.textures[WE]);
	return (0);
}
