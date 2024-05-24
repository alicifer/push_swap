/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:33:25 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/04 09:42:35 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dst)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d >= s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
