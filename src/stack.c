/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:33:43 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/18 10:17:49 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

t_stack	*ft_new_node(int value, int len)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index_max = len;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->target_pos = -1;
	new_node->cost_total = -27;
	return (new_node);
}

void	insert_back(t_stack *a, t_stack *newnode)
{
	t_stack	*temp;

	temp = get_tail(a);
	temp->next = newnode;
}
/**
 * @brief Fills a stack with integers from an integer array 
 * starting from the last element. 
 * !Excluding array[0] where is store len of array
 * Returns a pointer to the stack created.
 * @param array Pointer to the integer array.
 */
t_stack	*fill_stack(int *array)
{
	int		len;
	t_stack	*stack_a;
	int 	x;

	len = array[0];
	stack_a = ft_new_node(array[1], len);
	x = 2;
	while (len >= x)
	{
		insert_back(stack_a, ft_new_node(array[x++], len));
	}
	free (array);
	return (stack_a);
}

/**
 * @brief Asign a index starting from 1 to len to each element in the stack. 
 * In all the index_max is already store len
 * @param a Pointer to t_stack
 */
void	put_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*min_value;
	int		index;

	index = 1;
	tmp = a;
	//min_value = tmp;
	while (tmp)
	{
		while (tmp && tmp->index != -1)
			tmp = tmp->next;
		if (!tmp)
			return ;
		min_value = tmp;
		while (tmp)
		{
			if (tmp->value < min_value->value && tmp->index == -1)
				min_value = tmp;
			tmp = tmp->next;
		}
		min_value->index = index;
		index++;
		tmp = a;
	}
}

/**
 * @brief Sets de real position in the stack.
 * 
 * @param a 
 */
void	put_position(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp->pos = i++;
		tmp = tmp->next;
	}
}


void	put_cost(t_stack **stack)
{
	int		len;
	t_stack	*tmp;

	tmp = *stack;
	len = stack_len(tmp);
	while (tmp)
	{
		if (tmp->pos > len / 2)
			tmp->cost = - 1 * ((len - tmp->pos));
		else
			tmp->cost = tmp->pos;
		tmp = tmp->next;
	}
}

int ft_abs(int nbr)
{
	if(nbr < 0)
		nbr *= -1;
	return (nbr);
}

void	put_total_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*a;
	int		loop;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		loop = b->target_pos;
		while (loop-- > 0 && a)
			a = a->next;
		if((b->cost > 0 && a->cost > 0) || (b->cost < 0 && a->cost < 0))
			if (ft_abs(b->cost) > ft_abs(a->cost))
				b->cost_total = ft_abs(b->cost);
			else
				b->cost_total = ft_abs(a->cost);
		else 
			b->cost_total = ft_abs(b->cost) + ft_abs(a->cost);
		
		b = b->next;
	}
}
