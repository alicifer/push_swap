/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:33:58 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/13 10:58:01 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2, int n_bytes_read)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	str = ft_calloc((ft_strlen(s1)) + n_bytes_read + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (i < n_bytes_read)
		str[j++] = s2[i++];
	str[j] = '\0';
	free (s1);
	return (str);
}
