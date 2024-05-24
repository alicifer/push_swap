/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:19:46 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 10:00:48 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		size;

	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
