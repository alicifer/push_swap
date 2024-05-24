/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:30:47 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/17 12:01:28 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static int	ft_start_nextdel(const char *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_freematrix(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	size_t	i;
	size_t	j;
	size_t	cntwrd;

	cntwrd = ft_cntwrd(s, c);
	aux = (char **) malloc((cntwrd + 1) * sizeof(char *));
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	aux[cntwrd] = NULL;
	while (j < cntwrd && s[i])
	{
		if (s[i] != c)
		{
			aux[j++] = ft_substr(s, i, (ft_start_nextdel(s, c, i) - i));
			if (!aux[j - 1])
				return (ft_freematrix(aux));
			i = ft_start_nextdel(s, c, i);
		}
		else
			i++;
	}
	return (aux);
}
