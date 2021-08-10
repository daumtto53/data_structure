/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:27:08 by mchun             #+#    #+#             */
/*   Updated: 2021/08/10 09:17:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include <stddef.h>

typedef int		data_type;

typedef struct	s_lnode
{
	data_type			*data;
	struct s_lnode	*next;
}				t_lnode;

typedef struct s_llist
{
	struct s_lnode	*head;
	int				size;
	struct s_lnode	*tail;
}				t_llist;

t_llist			*create_llist(void);
int				insert_data_tail(t_llist *list, data_type *data);
int				insert_data_head(t_llist *list, data_type *data);
void			delete_llist(t_llist *list);

#endif
