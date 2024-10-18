/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:26:44 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/16 21:03:05 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	wall_hit(float x, float y)
{
	int	x_pos;
	int	y_pos;

	if (x < 0 || y < 0)
		return (0);
	x_pos = floor(x / CUB_SIZE);
	y_pos = floor(y / CUB_SIZE);
	if ((y_pos >= get_map()->map_height || x_pos >= get_map()->map_width))
		return (0);
	if (get_map()->map_matrix[y_pos]
		&& x_pos <= (int)ft_strlen(get_map()->map_matrix[y_pos]))
		if (get_map()->map_matrix[y_pos][x_pos] == '1')
			return (0);
	return (1);
}

float	get_h_inter(float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = CUB_SIZE;
	x_step = CUB_SIZE / tan(angl);
	h_y = floor(get_player()->p_y / CUB_SIZE) * CUB_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = get_player()->p_x + (h_y - get_player()->p_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
	get_ray()->horiz_x = h_x;
	get_ray()->horiz_y = h_y;
	return (sqrt(pow(h_x - get_player()->p_x, 2) + pow(h_y - get_player()->p_y,
				2)));
}

float	get_v_inter(float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = CUB_SIZE;
	y_step = CUB_SIZE * tan(angl);
	v_x = floor(get_player()->p_x / CUB_SIZE) * CUB_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = get_player()->p_y + (v_x - get_player()->p_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	get_ray()->vert_x = v_x;
	get_ray()->vert_y = v_y;
	return (sqrt(pow(v_x - get_player()->p_x, 2) + pow(v_y - get_player()->p_y,
				2)));
}

void	calculate_inter(void)
{
	double	v_inter;
	double	h_inter;

	get_ray()->flag = 0;
	h_inter = get_h_inter(nor_angle(get_ray()->ray_ngl));
	v_inter = get_v_inter(nor_angle(get_ray()->ray_ngl));
	if (v_inter <= h_inter)
	{
		get_ray()->distance = v_inter;
		get_ray()->x = get_ray()->vert_x;
		get_ray()->y = get_ray()->vert_y;
	}
	else
	{
		get_ray()->x = get_ray()->horiz_x;
		get_ray()->y = get_ray()->horiz_y;
		get_ray()->distance = h_inter;
		get_ray()->flag = 1;
	}
}

void	raycaster(void)
{
	int	ray;

	ray = 0;
	get_ray()->ray_ngl = get_player()->angle - (get_player()->fov_rd / 2);
	while (ray <= WINDOW_WIDTH)
	{
		calculate_inter();
		render_wall(ray);
		get_ray()->ray_ngl += (get_player()->fov_rd / WINDOW_WIDTH);
		ray++;
	}
}
