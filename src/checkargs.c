/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:34:56 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/23 12:15:06 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(int *array)
{
	int	len;
	int	i;
	int	j;

	i = 1;
	len = array[0];
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_err(char **s, int index)
{
	long	res;

	res = ft_atol(s[index]);
	if (res > INT_MAX || res < INT_MIN)
	{
		free_matrix(s);
		print_error("Check input INT_MAX INT_MIN.");
	}
	return (res);
}

int	check_num(char **argv)
{
	int	x;
	int	y;

	y = 1;
	x = 0;
	if (argv[y][0] == '\0')
		return (0);
	while (argv[y][x])
	{
		if (argv[y][x] != '-'
			&& argv[y][x] != ' ' && !ft_isdigit(argv[y][x]))
				return (0);
		if (argv[y][x] == '-' && !ft_isdigit(argv[y][x + 1]))
				return (0);
		x++;
	}
	x = 0;
	while (argv[y][x] == ' ')
		x++;
	if (!argv[y][x])
		return (0);
	return (1);
}

/**
 * @brief Check if the int array is sorted.
 * ! in array[0] is stored the array len.
 * @param array 
 * @return  int 1 -> sorted 0-> not sorted
 */
int	check_order(int *array)
{
	int	len;
	int	i;

	len = array[0];
	i = 1;
	while (i < len)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}


/**
 * @brief Check if the stack is sorted.
 * 
 * @param a pointer to the stack
 * @return int 1 -> sorted 0-> not sorted
 */
int	stack_check_order(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	if (!a)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
