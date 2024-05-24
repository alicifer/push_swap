/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:46 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/17 12:13:54 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			j;
	const char	*str;

	j = ft_strlen(s);
	str = s + j;
	if ((char)c == '\0')
		return ((char *)str);
	str--;
	while (str >= s && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
