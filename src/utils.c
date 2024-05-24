/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:04:15 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/06 10:31:15 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10 + str[i] - '0');
		i++;
	}
	return (res * sign);
}

char	**args_to_string(char *s)
{
	char	**string;

	string = ft_split(s, ' ');
	return (string);
}

/**
 * @brief Splits an array of strings into an array of integers.
 * !Storing the int array length  as the first element of the array.
 * @param s The array of strings to convert.
 * @return int* A pointer to the array of integers.
 */
int	*split_to_intarray(char **s)
{
	int	y;
	int	*array;

	y = 0;

	while (s[y])
		y++;
	array = (int *)malloc(sizeof(int) * y + 1);
	if (!array)
		return (NULL);
	array[0] = y;
	y = 0;
	while (s[y])
	{
		array[y + 1] = ft_atoi_err(s, y);
		y++;
	}
	free_matrix(s);
	return (array);
}

int	*args_to_intarray(char *s)
{
	char	**split;
	int		*int_array;

	split = args_to_string(s);
	int_array = split_to_intarray(split);
	return (int_array);
}