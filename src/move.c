/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:56:15 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/17 18:36:00 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	movement(double move_x, double move_y)
{
	int	x_pos;
	int	y_pos;
	int	new_x;
	int	new_y;

	new_x = roundf(get_player()->p_x + move_x);
	new_y = roundf(get_player()->p_y + move_y);
	x_pos = (new_x / CUB_SIZE);
	y_pos = (new_y / CUB_SIZE);
	if (get_map()->map_matrix[y_pos][x_pos] != '1' \
	&& get_map()->map_matrix[y_pos][get_player()->p_x / CUB_SIZE])
	{
		get_player()->p_x = new_x;
		get_player()->p_y = new_y;
	}
}

void	release(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		get_player()->l_r = 0;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		get_player()->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		get_player()->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		get_player()->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		get_player()->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		get_player()->rot = 0;
}

void	mlx_key(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		finalize_and_cleanup(get_map());
		mlx_delete_image(get_mlx()->mlx_ptr, get_mlx()->image);
		mlx_terminate(get_mlx()->mlx_ptr);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		get_player()->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		get_player()->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		get_player()->u_d = -1;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS))
		get_player()->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		get_player()->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		get_player()->rot = 1;
	release(keydata);
}

void	rotate_player(int i)
{
	if (i == 1)
	{
		get_player()->angle += ROTATION_SPEED;
		if (get_player()->angle > 2 * M_PI)
			get_player()->angle -= 2 * M_PI;
	}
	else
	{
		get_player()->angle -= ROTATION_SPEED;
		if (get_player()->angle < 0)
			get_player()->angle += 2 * M_PI;
	}
}

void	hook(double move_x, double move_y)
{
	if (get_player()->rot == 1)
		rotate_player(1);
	if (get_player()->rot == -1)
		rotate_player(0);
	if (get_player()->l_r == 1)
	{
		move_x = -sin(get_player()->angle) * PLAYER_SPEED;
		move_y = cos(get_player()->angle) * PLAYER_SPEED;
	}
	if (get_player()->l_r == -1)
	{
		move_x = sin(get_player()->angle) * PLAYER_SPEED;
		move_y = -cos(get_player()->angle) * PLAYER_SPEED;
	}
	if (get_player()->u_d == 1)
	{
		move_x = cos(get_player()->angle) * PLAYER_SPEED;
		move_y = sin(get_player()->angle) * PLAYER_SPEED;
	}
	if (get_player()->u_d == -1)
	{
		move_x = -cos(get_player()->angle) * PLAYER_SPEED;
		move_y = -sin(get_player()->angle) * PLAYER_SPEED;
	}
	movement(move_x, move_y);
}
