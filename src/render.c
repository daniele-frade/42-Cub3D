/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:43:26 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/15 17:43:26 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_top_bottom(int t_pixel, int b_pixel, int ray)
{
	int i;
	i = b_pixel;
	while(i < WINDOW_HEIGHT)
		my_mlx_pixel_put(get_mlx()->image, ray, i++, get_map()->f_rgb_int);
	i = 0;
	while (i < t_pixel)
		my_mlx_pixel_put(get_mlx()->image, ray, i++, get_map()->c_rgb_int);
	
}

void	my_mlx_pixel_put(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WINDOW_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= WINDOW_HEIGHT)
		return ;
	mlx_put_pixel(image, x, y, color);
}


