/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/22 18:58:48 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_matrix(t_map *map)
{
	int i;
	int j;
	char **matrix = map->matrix;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void print_matrix_2(t_map *map)
{
	int i = 0;
	char **matrix = map->matrix;
	
	while(matrix[i])
		ft_printf("%s\n", matrix[i++]);
}

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
		error("Error\nInvalid map file (wrong directions)\n");

	if (file_has_all_paths(&map) == 0)
		error("Error\nInvalid map file (wrong paths)\n");

	if (map_has_empty_line(&map) == 0)
		error("Error\nInvalid map (empty line)\n");
	
	if (map_has_only_valid_chars(&map) == 0)
		error("Error\nInvalid map characteres\n");
	
	if(map_has_valid_nb_of_players(&map) == 0)
		error("Error\nInvalid number of player\n");

	// if (map_is_closed_by_walls(&map) == 0)
	// {
	// 	ft_printf("Error\n");
	// 	exit(1);
	// }
	//print_matrix(&map);
	print_matrix_2(&map);
	ft_printf("Compilou\n");
	return (0);
}
