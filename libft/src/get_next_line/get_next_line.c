/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:00:49 by dfrade            #+#    #+#             */
/*   Updated: 2023/11/18 14:09:36 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer_accumulator(int fd, char *static_buffer);
char	*ft_get_current_line(char *static_buffer);
char	*ft_get_remaining_buffer(char *static_buffer);

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*current_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	static_buffer = ft_buffer_accumulator(fd, static_buffer);
	if (static_buffer == NULL)
		return (NULL);
	current_line = ft_get_current_line(static_buffer);
	static_buffer = ft_get_remaining_buffer(static_buffer);
	return (current_line);
}

char	*ft_buffer_accumulator(int fd, char *static_buf)
{
	char	*temp_buffer;
	int		bytes_read;
	char	*aux;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while ((ft_strchr(static_buf, '\n') == NULL) && (bytes_read != 0))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buffer);
			free(static_buf);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		aux = static_buf;
		static_buf = ft_strjoin(static_buf, temp_buffer);
		free(aux);
	}
	free(temp_buffer);
	return (static_buf);
}

char	*ft_get_current_line(char *static_buf)
{
	char	*current_line;
	char	*line_break;
	size_t	line_length;

	if (static_buf[0] == '\0')
		return (NULL);
	line_break = ft_strchr(static_buf, '\n');
	if (line_break != NULL)
	{
		line_length = 0;
		while (&static_buf[line_length] != line_break)
			line_length++;
	}
	else
		line_length = ft_strlen(static_buf);
	current_line = malloc((line_length + 2) * sizeof(char));
	if (current_line == NULL)
		return (NULL);
	current_line = ft_strncpy(current_line, static_buf, line_length);
	if (line_break != NULL)
		current_line[line_length++] = '\n';
	current_line[line_length] = '\0';
	return (current_line);
}

char	*ft_get_remaining_buffer(char *static_buf)
{
	char	*remaining_buffer;
	char	*line_break;

	remaining_buffer = NULL;
	line_break = ft_strchr(static_buf, '\n');
	if (line_break != NULL)
		remaining_buffer = ft_strdup(line_break + 1);
	free(static_buf);
	return (remaining_buffer);
}
