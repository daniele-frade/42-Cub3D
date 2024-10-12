/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:14:23 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/12 15:13:15 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error(char *msg)
{
	while (*msg)
		write(1, msg++, 1);
	exit(1);
}

void	free_and_exit(t_map *map, char *msg)
{
	free_matrix(map->matrix);
	free(map->backup_content);
	error(msg);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != NULL)
		free(matrix[i++]);
	free(matrix);
}

void free_texture(t_map *map)
{
	free_matrix(map->matrix);
	if (map->textures[NO] != NULL)
		mlx_delete_texture(map->textures[NO]);
	if (map->textures[SO] != NULL)
		mlx_delete_texture(map->textures[SO]);
	if (map->textures[EA] != NULL)
		mlx_delete_texture(map->textures[EA]);
	if (map->textures[WE] != NULL)
		mlx_delete_texture(map->textures[WE]);
	error("Error\nWrong texture path\n");
}

void finalize_and_cleanup(t_map *map)
{
	free_matrix(map->matrix);
	mlx_delete_texture(map->textures[NO]);
	mlx_delete_texture(map->textures[SO]);
	mlx_delete_texture(map->textures[EA]);
	mlx_delete_texture(map->textures[WE]);
}

