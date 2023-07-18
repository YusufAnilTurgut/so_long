/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:47:24 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/13 17:59:06 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin2(char *lft_str, char *buff);
char	*ft_read(int fd, char *buffer);
char	*ft_get_line(char *line);
char	*ft_clean(char *line);
int		ft_strlen2(char *s);
int		ft_strchr2(char *s);

#endif