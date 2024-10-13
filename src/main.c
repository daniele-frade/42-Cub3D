/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/13 09:40:10 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	arguments_validation(argc, argv[1]);
	check_and_get_file(&map, argv[1]);
	data_validation(&map);
	get_map_matrix(&map);
	get_player_position(&map);
	set_textures_path(&map);
	set_rgb_color(&map);
	if (is_all_textures_ok(&map) == 0)
		free_texture(&map);
	print_info(&map); // to delete
	finalize_and_cleanup(&map);
	return (0);
}

// to delete
void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		ft_printf("%s\n", matrix[i++]);
}

void	print_info(t_map *map)
{
	ft_printf("\nCompiled successfully\n\n");
	ft_printf("Map matrix:\n");
	print_matrix(map->map_matrix);
	ft_printf("\n");
	ft_printf("Player position x: %d\n", map->p_position_line);
	ft_printf("Player position y: %d\n\n", map->p_position_col);
	ft_printf("Ceiling RGB value: %u\n", map->c_rgb_int);
	ft_printf("Floor RGB value: %u\n\n", map->f_rgb_int);
	ft_printf("Texture paths:\n");
	print_matrix(map->text_path);
	ft_printf("\n");
}
