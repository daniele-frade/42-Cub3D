#include "../includes/cub3d.h"

void	fill_top_bottom(t_mlx *mlx, int color_top, int color_bottom)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	half_height;

	half_height = mlx->image->height / 2;
	y = 0;
	while (y < mlx->image->height)
	{
		x = 0;
		while (x < mlx->image->width)
		{
			if (y < half_height)
				mlx_put_pixel(mlx->image, x, y, color_top);
			else
				mlx_put_pixel(mlx->image, x, y, color_bottom);
			x++;
		}
		y++;
	}
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
