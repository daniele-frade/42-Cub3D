/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/21 11:58:02 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	
	if (argc != 2)
		error("Error\nInvalid arguments\n");
	
	if (file_is_cub(argv[1]) == 0)
		error("Error\nInvalid map file\n");
	
	check_and_get_file(&map, argv[1]);
	
	if (file_has_all_directions(&map) == 0)
		error("Error\n");

	if (file_has_all_paths(&map) == 0)
		error("Error\n");

	if (map_has_empty_line(&map) == 0)
		error("Error\n");
	
	if (map_has_only_valid_chars(&map) == 0)
		error("Error\n");
	
	if(map_has_valid_nb_of_players(&map) == 0)
		error("Error\n");

	// if (map_is_closed_by_walls(&map) == 0)
	// {
	// 	ft_printf("Error\n");
	// 	exit(1);
	// }
	
	ft_printf("Compilou\n");
	return (0);
}
