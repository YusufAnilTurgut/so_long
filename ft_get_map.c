/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:07:38 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/18 14:56:27 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map(t_data *data, char *argv2)
{
	int		fd;
	char	*tmp;
	char	*buffer;
	char	*buff;

	ft_mlx_files_to_image(data);
	buff = NULL;
	fd = open(argv2, O_RDONLY);
	buffer = ft_calloc(sizeof(char), 1);
	tmp = get_next_line(fd);
	data->map_width = ft_strlen(tmp) - 1;
	while (tmp)
	{
		buff = ft_strjoin(buffer, tmp);
		free(buffer);
		free(tmp);
		buffer = buff;
		tmp = get_next_line(fd);
	}
	data->buffer = buffer;
	data->map = ft_split(buffer, '\n');
	data->map_check = ft_split(buffer, '\n');
	ft_get_map_height(data);
}

void	ft_get_map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data -> map[i])
	{
		i++;
		data -> map_height = i;
	}
}
