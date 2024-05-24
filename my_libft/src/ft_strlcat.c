/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:35:45 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/08 09:26:49 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(dst);
	j = 0;
	if (dstsize > 0 && dstsize > len)
	{
		i = len;
		j = 0;
		while (src[j] && i < (dstsize - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
