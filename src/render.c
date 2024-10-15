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

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}


double get_xo(mlx_texture_t *texture)
{
	double	x_o;

	if (get_ray()->flag == 1)
		x_o = (int)fmodf((get_ray()->horiz_x * \
		(texture->width / CUB_SIZE)), texture->width);
	else
		x_o = (int)fmodf((get_ray()->vert_y * \
		(texture->width / CUB_SIZE)), texture->width);
	return (x_o);
}

mlx_texture_t *get_texture(int flag)
{
	get_ray()->ray_ngl = nor_angle(get_ray()->ray_ngl);
	if (flag == 0)
	{
		if (get_ray()->ray_ngl > M_PI / 2 && get_ray()->ray_ngl < 3 * (M_PI / 2))
			return (get_map()->textures[WE]); // west wall
		else
			return (get_map()->textures[EA]); // east wall
	}
	else
	{
		if (get_ray()->ray_ngl > 0 && get_ray()->ray_ngl < M_PI)
			return (get_map()->textures[SO]); // south wall
		else
			return (get_map()->textures[NO]); // north wall
	}
}

void	draw_wall_texture(int ray ,int t_pixel, int b_pixel, double wall_height)
{
	double x_o;
	double y_o;
	mlx_texture_t *texture;
	uint32_t *array;
	double factor;
	texture = get_texture(get_ray()->flag);
	array = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_height;
	x_o = get_xo(texture);
	y_o = (t_pixel - (WINDOW_HEIGHT / 2) + (wall_height / 2)) * factor;
	if(y_o < 0)
		y_o = 0;
	while(t_pixel < b_pixel)
	{
		my_mlx_pixel_put(get_mlx()->image, ray, t_pixel, reverse_bytes(array[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pixel++;
	}
}

