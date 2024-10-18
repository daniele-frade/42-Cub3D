/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:01:29 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/16 21:06:53 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_top_bottom(int t_pixel, int b_pixel, int ray)
{
	int	i;

	i = b_pixel;
	while (i < WINDOW_HEIGHT)
		my_mlx_pixel_put(get_mlx()->image, ray, i++, get_map()->f_rgb_int);
	i = 0;
	while (i < t_pixel)
		my_mlx_pixel_put(get_mlx()->image, ray, i++, get_map()->c_rgb_int);
}

mlx_texture_t	*get_texture(int flag)
{
	get_ray()->ray_ngl = nor_angle(get_ray()->ray_ngl);
	if (flag == 0)
	{
		if (get_ray()->ray_ngl > M_PI / 2 && get_ray()->ray_ngl < 3 * (M_PI
				/ 2))
			return (get_map()->textures[WE]);
		else
			return (get_map()->textures[EA]);
	}
	else
	{
		if (get_ray()->ray_ngl > 0 && get_ray()->ray_ngl < M_PI)
			return (get_map()->textures[SO]);
		else
			return (get_map()->textures[NO]);
	}
}

void	draw_wall_texture(int ray, int t_pixel, int b_pixel, double wall_h)
{
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*array;
	double			factor;

	texture = get_texture(get_ray()->flag);
	array = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = get_xo(texture);
	y_o = (t_pixel - (WINDOW_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	if (texture == get_map()->textures[SO]
		|| texture == get_map()->textures[WE])
		x_o = (texture->width - 1) - x_o;
	while (t_pixel < b_pixel)
	{
		my_mlx_pixel_put(get_mlx()->image, ray, t_pixel, \
		reverse_bytes(array[(int)y_o * texture->width + (int)x_o]));
		y_o += factor;
		t_pixel++;
	}
}

void	render_wall(int ray)
{
	double	bot_pixel;
	double	top_pixel;
	double	wall_height;

	get_ray()->distance *= cos(nor_angle(get_ray()->ray_ngl \
	- get_player()->angle));
	wall_height = (CUB_SIZE / get_ray()->distance) * ((WINDOW_WIDTH / 2)
			/ tan(get_player()->fov_rd / 2));
	bot_pixel = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	top_pixel = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if (bot_pixel > WINDOW_HEIGHT)
		bot_pixel = WINDOW_HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	fill_top_bottom(top_pixel, bot_pixel, ray);
	draw_wall_texture(ray, top_pixel, bot_pixel, wall_height);
}
