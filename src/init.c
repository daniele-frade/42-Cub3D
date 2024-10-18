/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:16:33 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:32:46 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(void)
{
	t_player	*player;
	int			position_line;
	int			position_col;

	position_line = get_map()->p_position_line;
	position_col = get_map()->p_position_col;
	player = get_player();
	player->p_x = position_col * CUB_SIZE + CUB_SIZE / 2;
	player->p_y = position_line * CUB_SIZE + CUB_SIZE / 2;
	player->fov_rd = (FOV * M_PI) / 180;
	if (get_map()->map_matrix[position_line][position_col] == 'W')
		player->angle = M_PI;
	else if (get_map()->map_matrix[position_line][position_col] == 'E')
		player->angle = M_PI * 2;
	else if (get_map()->map_matrix[position_line][position_col] == 'S')
		player->angle = M_PI / 2;
	else if (get_map()->map_matrix[position_line][position_col] == 'N')
		player->angle = (3 * M_PI) / 2;
}

void	game_loop(void *param)
{
	(void)param;
	hook(0, 0);
	raycaster();
}

void	init(void)
{
	t_mlx	*mlx;

	mlx = get_mlx();
	mlx->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", 1);
	init_player();
	mlx->image = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx->mlx_ptr, mlx->image, 0, 0);
	mlx_loop_hook(mlx->mlx_ptr, game_loop, NULL);
	mlx_key_hook(mlx->mlx_ptr, mlx_key, NULL);
	mlx_loop(mlx->mlx_ptr);
	mlx_delete_image(mlx->mlx_ptr, mlx->image);
	mlx_terminate(mlx->mlx_ptr);
}
