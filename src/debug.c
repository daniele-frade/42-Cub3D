/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:54:02 by csilva-m          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:21 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
