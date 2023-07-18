/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:31:21 by yturgut           #+#    #+#             */
/*   Updated: 2022/10/28 16:32:22 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	f;
	size_t	c;

	f = 0;
	c = start;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (f < len && s[start + f] != '\0')
		f++;
	s2 = malloc((f + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = 0;
	while (i < len && s[c] != '\0')
		s2[i++] = s[c++];
	s2[i] = '\0';
	return (s2);
}
