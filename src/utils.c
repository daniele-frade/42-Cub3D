/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:14:23 by dfrade            #+#    #+#             */
/*   Updated: 2024/09/29 17:40:39 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_and_exit(char **matrix, char *msg)
{
	free_matrix(matrix);
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
