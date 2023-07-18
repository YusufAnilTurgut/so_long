/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:56:35 by yturgut           #+#    #+#             */
/*   Updated: 2023/07/15 14:56:35 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_len(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_int_to_asci(long nb, size_t count, int flag)
{
	int		s;
	int		i;
	char	*str;

	i = 0;
	s = 1;
	str = malloc(count * sizeof(char));
	if (!str)
		return (0);
	if (flag == -1)
	{
		str[i] = '-';
		i++;
	}
	while (s <= nb / 10)
		s *= 10;
	while (s != 0)
	{
		str[i] = (nb / s % 10 + '0');
		s /= 10;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa2(long n)
{
	char	*str;
	size_t	len;

	len = ft_int_len(n) + 1;
	if (n < 0)
	{
		len++;
		n *= -1;
		return (ft_int_to_asci(n, len, -1));
	}
	else if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		str[0] = 48;
		str[1] = 0;
		return (str);
	}
	return (ft_int_to_asci(n, len, 1));
}
