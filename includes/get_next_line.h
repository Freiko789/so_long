/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:14:18 by dtassel           #+#    #+#             */
/*   Updated: 2022/05/24 13:47:18 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include "so_long.h"

size_t			f_strlen(const char *str);

//void			*ft_memmove(void *dest, const void *src, size_t n);

char			*f_strchr(const char *s, int c);
char			*f_strjoin(const char *s1, const char *s2);
char			*get_next_line(int fd);
char			*ft_line(char *reader);
char			*ft_save(char *reader);
char			*ft_read(int fd, char *reader);

#endif
