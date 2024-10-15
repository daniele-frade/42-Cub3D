/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/15 16:11:55 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/15 16:11:55 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void release(mlx_key_data_t keydata)
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
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
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
