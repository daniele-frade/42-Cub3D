/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/08/10 18:02:04 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		exit(1);
	}
	if (map_is_cub_file(argv[1]) == 0)
	{
		ft_printf("Error\nInvalid map file\n");
		exit(1);
	}
	
	return (0);
}