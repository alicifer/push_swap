
#include "../push_swap.h"

t_stack	*find_lowest_cost(t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*lowest;

	b = *stack_b;
	lowest = b;
	if (!stack_b || !*stack_b)
		return (NULL);
	while (b)
	{
		if (b->cost_total < lowest->cost_total)
			lowest = b;
		b = b->next;
	}
	printf("\nLowest cost value: %d\n", lowest->value);
	return (lowest);
}

t_stack	*find_target_node(t_stack **a, t_stack *b_node)
{
    t_stack	*target;
    int		pos;

    pos = b_node->target_pos;
    target = *a;
    while(pos-- > 0)
    	target = target->next;
    return (target);
}

void	do_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*lowest_node;
	t_stack 	*target_node;


	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	lowest_node = find_lowest_cost(stack_b);
	target_node = find_target_node(stack_a, lowest_node);
	if(lowest_node->cost > 0 && target_node->cost > 0)
		move_rr(stack_a, stack_b, target_node, lowest_node);
	else if (lowest_node->cost < 0 && target_node->cost < 0)
		move_rrr(stack_a, stack_b, target_node, lowest_node);
	else if (lowest_node->cost < 0 && target_node->cost > 0)
		move_rrb(stack_b, lowest_node);
	else if (lowest_node->cost > 0 && target_node->cost < 0)
		move_rb(stack_b, lowest_node);
	if (lowest_node->cost == 0 && target_node->cost > 0)
		move_ra(stack_a, target_node);
	if (lowest_node->cost == 0 && target_node->cost < 0)
		move_rra(stack_a, target_node);
	if (target_node->cost == 0 &&  lowest_node->cost > 0)
		move_rb(stack_b, lowest_node);
	if (target_node->cost == 0 &&  lowest_node->cost < 0)
		move_rrb(stack_b, lowest_node);
	printf("estoy atrapado en este bucle");


	if (target_node->cost == 0 &&  lowest_node->cost == 0)
		move_pa(stack_a, stack_b);
	printf("DO_MOVE TARGET POS: %d	target pos cost:%d LOWEST VALUE: %d 	lowest cost: %d", target_node->pos, target_node->cost, lowest_node->value, lowest_node->cost);
	return ;
}

void do_sorting(t_stack **stack_a, t_stack **stack_b)
{
	//int i;

	//i = 60;
	if (!stack_b || !stack_a ||!*stack_a ||!*stack_b)
		return ;
	while(*stack_b )
	{
		put_position(*stack_a);
		put_position(*stack_b);
		put_target_pos(*stack_a, *stack_b);
		put_cost(stack_a);
		put_cost(stack_b);
		put_total_cost(stack_a, stack_b);
		do_move(stack_a, stack_b);
	}
    printf("///////////////////////////////////////////////////////\n");
	print_stack(*stack_a,"********* stack A - DO SORTING ******************");
	print_stack(*stack_b,"********* stack B - DO SORTING ******************");
}