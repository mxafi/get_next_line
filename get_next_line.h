/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:08:53 by malaakso          #+#    #+#             */
/*   Updated: 2022/11/11 17:55:50 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GET_NEXT_LINE_H
# ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);

#endif
