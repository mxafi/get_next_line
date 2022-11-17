/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:08:34 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/17 19:16:28 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_str(char *input, char *original, size_t input_len)
{
	char	*final;
	size_t	original_len;
	size_t	final_len;

	if (!input_len)
	{
		while (input[input_len])
			input_len++;
	}
	original_len = 0;
	while (original[original_len])
		original_len++;
	final_len = input_len + original_len;
	final = ft_strndup(original, final_len);
	if (!final)
		return (NULL);
	(void)ft_strlcat(final, input, final_len + 1);
	free(original);
	return (final);
}

char	*ret_final_line(char *stash, ssize_t read_value)
{
	char	*line;

	if (read_value <= 0)
		return (NULL);
	line = ft_strndup(stash, read_value);
	return (line);
}

char	*ret_line(char *stash, ssize_t read_value)
{
	char	*line;
	char	*chr;
	size_t	i;

	chr = ft_strchr(stash, '\n');
	if (!chr)
		return (ret_final_line(stash, read_value));
	i = 0;
	while (stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	while (i > 0)
	{
		line[i] = stash[i];
		i--;
	}
	line[i] = stash[i];
	return (line);
}

char	*trim_stash_nl(char *stash)
{
	char	*new_stash;
	char	*chr;
	size_t	len;

	chr = ft_strchr(stash, '\n');
	if (!chr)
		return (NULL);
	chr++;
	len = 0;
	while (chr[len])
		len++;
	new_stash = ft_strndup(chr, len);
	free (stash);
	return (new_stash);
}

// Remember to double check everything is freed on malloc fail gracefully. ajkshlkajsdhlkajshdlkajsda

char	*get_next_line(int fd)
{
	char				*buffer;
	ssize_t				n_bytes_read;
	static char			*stash;
	char				*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1000)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!stash)
		stash = ft_calloc(1, 1);
	if (!buffer || !stash)
		return (NULL);
	n_bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(stash, '\n') && n_bytes_read > 0)
	{
		stash = append_str(buffer, stash, n_bytes_read);
		if (!stash)
			return (NULL);
		n_bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	line = ret_line(stash, n_bytes_read);
	stash = trim_stash_nl(stash);
	return (line);
}
