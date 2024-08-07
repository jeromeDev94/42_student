/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:53:58 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/04 17:44:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errno = ENOENT;
		ft_exit_failure(NULL, ENOENT);
	}
	gc_fd_register(fd);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	return (count);
}
