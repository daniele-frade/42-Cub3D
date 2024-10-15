#include "../includes/cub3d.h"

void    mlx_key(mlx_key_data_t keydata, void *param)
{
    (void)param;
    if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		get_player()->l_r = -1;
    else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		get_player()->l_r = 1;
    else if(keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		get_player()->u_d = -1;
    else if(keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS))
        get_player()->u_d = 1;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		get_player()->rot = -1;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		get_player()->rot = 1;
}

void    rotate_player(int i)
{
    if(i == 1)
    {
        get_player()->angle += ROTATION_SPEED;
        if(get_player()->angle > 2 * M_PI)
            get_player()->angle -= 2 * M_PI;
    }
    else
    {
        get_player()->angle -= ROTATION_SPEED;
        if(get_player()->angle < 0)
            get_player()->angle += 2 * M_PI;
    }
}