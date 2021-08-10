/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:24:59 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 19:18:29 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdio.h>
# include <stdlib.h>
# include "../dynamic_array/dynamic_array.h"

typedef struct	s_stack{
	t_dyn_arr	*d_arr;
}				t_stack;

int		create_stack(t_stack *stack);
void	push(t_stack *stack, int data);
void	pop(t_stack *stack, int *data);
int		is_stack_full(t_stack *stack);
int		is_stack_empty(t_stack *stack);
int		get_top(t_stack *stack);
void	delete_stack(t_stack *stack);

#endif
