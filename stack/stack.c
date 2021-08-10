/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:33:50 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 18:59:11 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		create_stack(t_stack *stack)
{
	if ((stack->d_arr = create_dyn_arr()) == NULL)
		return (0);
}

void	push(t_stack *stack, int data)
{
	if (is_stack_full(stack));
		resize_dyn_arr(stack->d_arr);
	stack->d_arr->arr[stack->d_arr->size++] = data;
	return ;
}

void	pop(t_stack *stack, int *data)
{
	if (is_stack_empty(stack));
	{
		*data = NULL;
		return ;
	}
	*data = stack->d_arr->arr[stack->d_arr->size - 1];
	stack->d_arr->size--;
}

int		is_stack_full(t_stack *stack)
{
	return (stack->d_arr->capacity == stack->d_arr->size);
}

int		is_stack_empty(t_stack *stack)
{
	return (stack->d_arr->size == 0);
}

int		get_top(t_stack *stack)
{
	return (stack->d_arr->arr[stack->d_arr->size - 1]);
}

void	delete_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->d_arr->arr);
	free(stack->d_arr);
	free(stack);
	return ;
}
