/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:06:25 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 18:25:21 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynamic_array.h"

t_dyn_arr	*create_dyn_arr(void)
{
	t_dyn_arr	*d_arr;
	int			*arr;

	d_arr = (t_dyn_arr *)malloc(sizeof(t_dyn_arr));
	if (!d_arr)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * 1);
	if (!arr)
	{
		free(d_arr);
		return (NULL);
	}
	d_arr->capacity = 1;
	d_arr->size = 0;
	d_arr->arr = arr;
	return (d_arr);
}

int			resize_dyn_arr(t_dyn_arr *d_arr)
{
	int		*new_arr;
	int		new_capacity;
	int		i;

	new_capacity = d_arr->capacity * 4;
	new_arr = (int *)malloc(sizeof(int) * new_capacity);
	if (!new_arr)
		return (0);
	for (i = 0; i < d_arr->capacity; i++)
		new_arr[i] = d_arr->arr[i];
	free(d_arr->arr);
	d_arr->arr = new_arr;
	return (1);
}
