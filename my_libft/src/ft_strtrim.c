/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:16:51 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:26 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len > i && ft_strchr(set, s1[len -1]))
		len--;
	aux = (char *) malloc((len - i + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	j = 0;
	while (i < len)
	{
		aux[j] = s1[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	return (aux);
}
/* static int	ft_check_char(char const *set, char c)
{	
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	char	*aux;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (s1[i] && ft_check_char(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len > i && ft_check_char(set, s1[len -1]))
		len--;
	aux = (char *) malloc((len - i + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	j = 0;
	while (i < len)
	{
		aux[j] = s1[i];
		i++;
		j++;
	}
	aux[i] = '\0';
	return (aux);
}	 */
/* 
int main ()
{
	char const s[] = "-+-+-*HOLA AMIGOS111110111";
	char const set[] = "+-*10";
	printf("\nEl string original: %s \n", s);
	printf("\nLos char a eliminar: %s \n", set);
	printf("\nLa string recotada: %s \n", ft_strtrim(s, set));
	free(ft_strtrim(s, set));
	return (0);
}  */
