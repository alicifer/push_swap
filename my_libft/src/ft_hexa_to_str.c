/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:03:23 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/13 10:57:26 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_hexa_to_str(unsigned long hex)
{
	char	*str;
	char	*str_hexa;
	int		i;

	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	str_hexa = "0123456789abcdef";
	i = 0;
	if (hex == 0)
	{
		str[0] = '0';
	}
	while (hex != 0)
	{
		str[i++] = str_hexa[hex % 16];
		hex = hex / 16;
	}
	str[i] = '\0';
	return (str);
}
