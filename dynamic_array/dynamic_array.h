/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:59:17 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 18:47:58 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_dyn_arr{
	int		*arr;
	int		size;
	int		capacity;
}				t_dyn_arr;

t_dyn_arr	*create_dyn_arr(void);
int			resize_dyn_arr(t_dyn_arr *d_arr);

#endif
