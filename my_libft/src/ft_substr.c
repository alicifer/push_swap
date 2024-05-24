/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:33:59 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:40 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!s || len <= 0 || start >= len_s)
		return (str = (char *)ft_calloc(1, 1));
	if ((len + start) > len_s)
		len = (len_s - start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
/*  int main()
{
	const char *original = "abcdefghijklmnopqrstuvw";
	unsigned int start = 3;
	size_t len = 5;
	char *substring = ft_substr(original, start, len);
	if (substring)
	{
		printf("Original: %s\n", original);
		printf("Substring: %s\n", substring);
		free(substring);
	}
	return 0;
} */
