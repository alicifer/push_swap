/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:30:01 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/14 09:55:30 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free (mat[i]);
		i++;
	}
	free (mat);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	print_error(char *msg)
{
	//FT_FREE LIBERAR los stacks
	//ft_printf("Error:\n");
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit (0);
}

int	*check_all_args(int argc, char **argv)
{
	int *array;

	if (argc != 2)
		print_error("");
	if (check_num(argv) == 0)
		print_error("Invalid arguments");
	array = args_to_intarray(argv[1]);
	if(check_dup(array) == 1)
	{	
		free (array);
		print_error("Duplicated numbers.\n");
	}
	if(check_order(array) == 1)
	{	
		free (array);
		exit (0);
	}
	return (array);
}

