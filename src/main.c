/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/18 17:43:32 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		exit(1);
	}
	
	if (file_is_cub(argv[1]) == 0)
	{
		ft_printf("Error\nInvalid map file\n");
		exit(1);
	}
	
	check_and_get_file(&map, argv[1]);
	
	if (file_has_all_directions(&map) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}

	if (file_has_all_paths(&map) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	
	if (map_has_only_valid_chars(&map) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}

	if (map_is_closed_by_walls(&map) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	
	return (0);
}