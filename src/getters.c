/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:44:11 by csilva-m          #+#    #+#             */
/*   Updated: 2024/10/16 20:11:56 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_mlx	*get_mlx(void)
{
	static t_mlx	core;

	return (&core);
}

t_player	*get_player(void)
{
	static t_player	core;

	return (&core);
}

t_map	*get_map(void)
{
	static t_map	core;

	return (&core);
}

t_ray	*get_ray(void)
{
	static t_ray	core;

	return (&core);
}
