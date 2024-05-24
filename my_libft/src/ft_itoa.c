/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:35:47 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/08 12:39:50 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_sizeint(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size ++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		size;

	nbr = (long)n;
	size = ft_sizeint(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 9)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr > 0)
		str[--size] = nbr + '0';
	return (str);
}
