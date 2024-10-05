/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:14:23 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/05 16:41:09 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	error(char *msg)
{
	while (*msg)
		write(1, msg++, 1);
	exit(1);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		ft_printf("%s\n", matrix[i++]);
}
