/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:53:09 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/24 07:30:57 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*a;
	t_stack *b;

	array = check_all_args(argc, argv);
	a = fill_stack(array);
	if (stack_len(a) < 3)
	{
		if (stack_check_order(a) == 1)
		{
			free_stack(a);
			exit (0);
		}
		else if (stack_len(a) == 2)
		{
			move_sa(&a);
			free_stack(a);
			exit (0);
		}
	}
	b = NULL;
	put_index(a);
//	print_stack(a, "STACK A - principio");
//	print_stack(b, "STACK B - Principio");
	if (stack_len(a) >= 3)
		push_all_to_b(&a, &b);
	sort_three(&a);
	do_sorting(&a, &b);
	//print_stack(a, "STACK A - MEDIO");
	if (stack_check_order(a) == 1 && b == NULL)
	{	
		free_stack(a);
		free_stack(b);
		return (0);
	}	
	else if (b == NULL)
		final_sort(&a);

	
	/*if ((stack_check_order(a) == 1 && b == NULL))
		printf("//////////// ORDENADO \\\\\\\\\\\\\n");
	else
		printf("//////////// NO ORDENADO \\\\\\\\\\\\n");
*/
	//print_stack(a, "STACK A - FINAL");
	//print_stack(b, "STACK B - FINAL");
	free_stack(b);
	free_stack(a);
	return (0);	
}





/*int	main(int argc, char **argv)
{
	int		*array;
	t_stack *a;
	t_stack	*temp;
	
	array = check_all_args(argc, argv);
	printf("\n-----Imprimir el array-------------- ------\n");
	int j = 0;
	while(array[j])
		printf("value: %d\n", array[j++]);
	a = fill_stack(array);
	printf("\n-----------IMPRIMIR A AL PRINCIPIO SIN MOVIMIENTOS----\n");
	printf("\n-----------STACK A----------------------------------------\n");
	
	temp = a;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}
	put_index(a);
	if (stack_len(a) < 3)
	{
		if (stack_check_order(a) == 1)
		{
			free(a);
			exit(0);
		}
		else 
		{
			(move_sa(&a));
			free(a);
			exit(0);
		}
	}

	t_stack *b = NULL;
	push_all_to_b(&a, &b);
	
printf("\n-----------luego de PUSH ALL TO B----\n");
	printf("\n-----------STACK A----------------------------------------\n");
	
	temp = a;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}

printf("\n-----------STACK B----------------------------------------\n");
	
	temp = b;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}



	
	sort_three(&a);
	do_sorting(&a, &b);
	final_sort(&a);

	printf("\n-////////////////////////////////////////////\n");
	printf("\n-----------IMPRIMIR LUEGO DE FINAL SORT ----\n");
	printf("\n-////////////////////////////////////////////\n");
	printf("\n-----------STACK A----------------------------------------\n");
	temp = a;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}
	printf("\n-----------STACK B----------------------------------------\n");
	temp = b;
	while (temp)
	{
	printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;

	}
	free_stack(b);
	free_stack (a);	
	atexit(check_leaks);
	return (0);	
}*/

