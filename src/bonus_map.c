/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:07:21 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/16 19:07:47 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(uint32_t color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < CUB_SIZE)
	{
		j = 0;
		while (j < CUB_SIZE)
		{
			my_mlx_pixel_put(get_mlx()->image_map, x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void	minimap(void)
{
	char	**map_p;
	int		x;
	int		y;

	map_p = get_map()->map_matrix;
	x = 0;
	y = 0;
	while (map_p[y])
	{
		x = 0;
		while (map_p[y][x])
		{
			if (map_p[y][x] == '1')
				draw_square(0x00FF00FF, x * CUB_SIZE, y * CUB_SIZE);
			else
				draw_square(0x000000FF, x * CUB_SIZE, y * CUB_SIZE);
			++x;
		}
		++y;
	}
}
