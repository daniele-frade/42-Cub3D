/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/16 21:08:29 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	get_color(int flag)
{
	get_ray()->ray_ngl = nor_angle(get_ray()->ray_ngl);
	if (flag == 0)
	{
		if (get_ray()->ray_ngl > M_PI / 2 && get_ray()->ray_ngl < 3 * (M_PI
				/ 2))
			return (0xB5B5B5FF);
		else
			return (0xB5B5B5FF);
	}
	else
	{
		if (get_ray()->ray_ngl > 0 && get_ray()->ray_ngl < M_PI)
			return (0xF5F5F5FF);
		else
			return (0xF5F5F5FF);
	}
}

void	draw_wall(int ray, int top, int bot)
{
	int	color;

	color = get_color(get_ray()->flag);
	while (top < bot)
		my_mlx_pixel_put(get_mlx()->image, ray, top++, color);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = get_map();
	ft_bzero(map, sizeof(t_map));
	arguments_validation(argc, argv[1]);
	check_and_get_file(map, argv[1]);
	data_validation(map);
	get_map_matrix(map);
	get_player_position(map);
	get_map_size(map);
	set_textures_path(map);
	set_rgb_color(map);
	if (is_all_textures_ok(map) == 0)
		free_texture(map);
	init();
	finalize_and_cleanup(map);
	return (0);
}
