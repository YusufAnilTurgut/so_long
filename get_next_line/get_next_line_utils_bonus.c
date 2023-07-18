/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:50:05 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/17 13:31:43 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin2(char *lft_str, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!lft_str)
	{
		lft_str = malloc(1);
		lft_str[0] = '\0';
	}
	if (!buffer)
		return (0);
	str = malloc(ft_strlen2(lft_str) + ft_strlen2(buffer) + 1);
	if (!str)
		return (0);
	while (lft_str[++i])
		str[j++] = lft_str[i];
	i = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free (lft_str);
	return (str);
}

char	*ft_get_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *line)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	str = malloc(ft_strlen2(line) - i + 1);
	i++;
	while (line[i])
	{
		str[j++] = line[i++];
	}
	str[j] = '\0';
	free(line);
	return (str);
}
