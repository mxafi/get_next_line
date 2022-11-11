/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:08:34 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/11 20:24:15 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				*buffer;
	static ssize_t		n_bytes_read;
	char				*line;
	static char			*stash;
	static size_t		stash_size;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = malloc(BUFFER_SIZE);
	else
		stash = 
	while (1)
	{
		n_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes_read == 0)
		{
			handle_zero_bytes_read();
			empty_stash();
			free(buffer);
			return (NULL);
		}
		else if (n_bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		
	}
}
