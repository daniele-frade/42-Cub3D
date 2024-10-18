/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:20:01 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/16 20:13:30 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

double	get_xo(mlx_texture_t *texture)
{
	double	x_o;

	if (get_ray()->flag == 1)
		x_o = (int)(get_ray()->x * CUB_SIZE / 4) % texture->width;
	else
		x_o = (int)(get_ray()->y * CUB_SIZE / 4) % texture->width;
	return (x_o);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += CUB_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += CUB_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}
