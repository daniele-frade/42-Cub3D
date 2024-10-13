/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielefrade <danielefrade@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:14:49 by dfrade            #+#    #+#             */
/*   Updated: 2024/10/13 09:45:48 by danielefrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	data_validation(t_map *map)
{
	if (file_has_all_directions(map) == 0)
		free_and_exit(map, "Error\nInvalid map file\n");
	if (directions_has_all_paths(map) == 0)
		free_and_exit(map, "Error\nInvalid map file\n");
	if (file_has_valid_rgb(map) == 0)
		free_and_exit(map, "Error\nInvalid map (invalid rgb)\n");
	if (map_has_only_valid_chars(map) == 0)
		free_and_exit(map, "Error\nInvalid map (wrong characteres)\n");
	if (map_has_empty_line(map) == 0)
		free_and_exit(map, "Error\nInvalid map (empty line)\n");
	if (map_has_valid_nb_of_players(map) == 0)
		free_and_exit(map, "Error\nInvalid map (wrong number of player)\n");
	if (map_is_closed_by_walls(map) == 0)
		free_and_exit(map, "Error\nInvalid map (not closed by walls)\n");
}

int	set_direction_flag(char *line, char *direct, int *flag_val)
{
	if (ft_strncmp(line, direct, ft_strlen(direct)) == 0)
	{
		if (*flag_val == 1)
			return (0);
		*flag_val = 1;
	}
	return (1);
}

int	check_line_direction(char *line, t_flags *flag)
{
	if (!set_direction_flag(line, "NO ", &flag->no_flag)
		|| !set_direction_flag(line, "SO ", &flag->so_flag)
		|| !set_direction_flag(line, "EA ", &flag->ea_flag)
		|| !set_direction_flag(line, "WE ", &flag->we_flag)
		|| !set_direction_flag(line, "C ", &flag->c_flag)
		|| !set_direction_flag(line, "F ", &flag->f_flag))
		return (0);
	return (1);
}

int	all_directions_set(t_flags *flag)
{
	return (flag->no_flag == 1 && flag->so_flag == 1
		&& flag->ea_flag == 1 && flag->we_flag == 1
		&& flag->c_flag == 1 && flag->f_flag == 1);
}

int	file_has_all_directions(t_map *map)
{
	int		line;
	t_flags	flag;

	ft_bzero(&flag, sizeof(t_flags));
	line = 0;
	while (map->matrix[line] != NULL)
	{
		if (!check_line_direction(map->matrix[line], &flag))
			return (0);
		if (all_directions_set(&flag))
			return (1);
		line++;
	}
	return (0);
}
