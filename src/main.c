/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:57 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/12 16:30:57 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	jorge(void)
{
	printf("aqui\n");
}

void	init_player(void)
{
	t_player *player;
	player = get_player();
	
	player->p_x = get_map()->p_position_col * CUB_SIZE + CUB_SIZE / 2;
	player->p_y = get_map()->p_position_line * CUB_SIZE + CUB_SIZE / 2;
	player->fov_rd = (FOV * M_PI) / 180; // calculo de campo de visão em radiandos
	if(get_map()->map_matrix[get_map()->p_position_line][get_map()->p_position_col] == 'W')
		player->angle = M_PI;
	else if(get_map()->map_matrix[get_map()->p_position_line][get_map()->p_position_col]  == 'E')
		player->angle = M_PI * 2;
	else if(get_map()->map_matrix[get_map()->p_position_line][get_map()->p_position_col]  == 'S')
		player->angle = M_PI / 2;
	else if(get_map()->map_matrix[get_map()->p_position_line][get_map()->p_position_col]  == 'N')
		player->angle = (3 * M_PI) / 2;

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

int unit_circle(float angle, char c)
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

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}


int	wall_hit(float x, float y)
{
	int x_pos;
	int y_pos;

	if(x < 0 || y < 0)
		return(0);
	x_pos = floor(x / CUB_SIZE);
	y_pos = floor(y / CUB_SIZE);
	if ((y_pos >= 8|| x_pos >= 27))
		return (0);
	if(get_map()->map_matrix[y_pos] && x_pos <= (int)ft_strlen(get_map()->map_matrix[y_pos]))
		if(get_map()->map_matrix[y_pos][x_pos] == '1')
			return(0);
	return(1);
}

float	get_h_inter(float angl)
{
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int  pixel;

	y_step = CUB_SIZE;
	x_step = CUB_SIZE / tan(angl);
	h_y = floor(get_player()->p_y / CUB_SIZE) * CUB_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = get_player()->p_x + (h_y - get_player()->p_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while(wall_hit(h_x, h_y - pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return(sqrt(pow(h_x - get_player()->p_x, 2) + pow(h_y - get_player()->p_y, 2)));
}


float	get_v_inter(float angl)
{
	float v_x;
	float v_y;
	float x_step;
	float y_step;
	int  pixel;

	x_step = CUB_SIZE;
	y_step = CUB_SIZE * tan(angl);
	v_x = floor(get_player()->p_x / CUB_SIZE) * CUB_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = get_player()->p_y + (v_x - get_player()->p_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while(wall_hit(v_x - pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return(sqrt(pow(v_x - get_player()->p_x, 2) + pow(v_y - get_player()->p_y, 2)));
}

int get_color(int flag) // get the color of the wall
{
	get_ray()->ray_ngl = nor_angle(get_ray()->ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (get_ray()->ray_ngl > M_PI / 2 && get_ray()->ray_ngl < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (get_ray()->ray_ngl > 0 && get_ray()->ray_ngl < M_PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(int ray, int top, int bot)
{
	int color;
	color = get_color(get_ray()->flag);
	while(top < bot)
		my_mlx_pixel_put(get_mlx()->image, ray, top++, color);
}

void render_wall(int ray)
{
	double bot_pixel;
	double top_pixel;
	double wall_height;
	get_ray()->distance *= cos(nor_angle(get_ray()->ray_ngl - get_player()->angle));
	wall_height = (CUB_SIZE / get_ray()->distance) * ((WINDOW_WIDTH / 2) / tan(get_player()->fov_rd / 2));
	bot_pixel = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	top_pixel = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	if(bot_pixel > WINDOW_HEIGHT)
		bot_pixel = WINDOW_HEIGHT;
	if(top_pixel < 0)
		top_pixel = 0;
	// printf("Ray: %d, Top: %f, Bot: %f, Wall Height: %f, Distance: %f\n", ray, top_pixel, bot_pixel, wall_height, get_ray()->distance);
	fill_top_bottom(get_mlx() , get_map()->c_rgb_int, get_map()->f_rgb_int);
	draw_wall(ray, top_pixel, bot_pixel);

}


void raycaster(void)
{
	double v_inter;	
	double h_inter;
	int		ray;
	ray = 0;
	get_ray()->ray_ngl = get_player()->angle - (get_player()->fov_rd / 2); // primeiro angulo
	while (ray <= WINDOW_WIDTH * 2)
	{
		get_ray()->flag = 0;
		h_inter = get_h_inter(nor_angle(get_ray()->ray_ngl));
		v_inter = get_v_inter(nor_angle(get_ray()->ray_ngl));
		if(v_inter <= h_inter)
			get_ray()->distance = v_inter;
		else
		{
			get_ray()->distance = h_inter;
			get_ray()->flag = 1;
		}
		render_wall(ray);
		get_ray()->ray_ngl += (get_player()->fov_rd / WINDOW_WIDTH); // acrescenta o angulo
		ray++;
	}
	
}

void draw_square(uint32_t color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < CUB_SIZE)
	{
		j = 0;
		while (j < CUB_SIZE)
		{
			my_mlx_pixel_put(get_mlx()->image_map, x + i, y + j, color);
			++j;
		}
		++i;
	}
}

void minimap(void)
{
	char **map_p = get_map()->map_matrix;

	int x = 0;
	int y = 0;
	while(map_p[y])
	{
		x = 0;
		jorge();

		while(map_p[y][x])
		{
			if(map_p[y][x] == '1')
				draw_square(0x00FF00FF, x * CUB_SIZE, y * CUB_SIZE);
			else
				draw_square(0x000000FF, x * CUB_SIZE, y * CUB_SIZE);
			++x;
		}
		++y;
	}

}

//void	hook(double move_x, double move_y)
//{
	
//}

void game_loop(void *param)
{
	(void)param;
	t_mlx *mlx = get_mlx();
	// t_map *map;
	// map = get_map();
	mlx_delete_image(mlx->mlx_ptr, mlx->image);
	mlx->image = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx->mlx_ptr, mlx->image, 0, 0);
	mlx->image_map = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(mlx->mlx_ptr, mlx->image_map, 0, 0);
	mlx->image->instances[0].z = -1;
	raycaster();
	minimap();
	//draw_player();
	//hook(0, 0);

}

void	init(void)
{
	t_mlx	*mlx;
	mlx = get_mlx();
	mlx->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d", 1);
	init_player();
	mlx_loop_hook(mlx->mlx_ptr, &game_loop, NULL);
	mlx_loop(mlx->mlx_ptr);
	mlx_terminate(mlx->mlx_ptr);
	
}

int	main(int argc, char **argv)
{
	t_map	*map;
	map = get_map();
	// inicializa struct map
	ft_bzero(map, sizeof(t_map));
	// file validation
	arguments_validation(argc, argv[1]);
	check_and_get_file(map, argv[1]);
	map_validation(map);
	// pós file validation, get just map matrix
	get_map_matrix(map);
	get_player_position(map);
	set_textures_path(map);
	set_rgb_color(map);
	if (is_all_textures_ok(map) == 0)
		error("Error\nWrong texture path\n");
	// print map_matrix
	print_map(*map);
	init();
	// parte de free da validação do mapa
	free_matrix(map->matrix);
	mlx_delete_texture(map->textures[NO]);
	mlx_delete_texture(map->textures[SO]);
	mlx_delete_texture(map->textures[EA]);
	mlx_delete_texture(map->textures[WE]);
	return (0);
}