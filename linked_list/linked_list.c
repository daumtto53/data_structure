/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:49:52 by mchun             #+#    #+#             */
/*   Updated: 2021/08/10 09:38:45 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_llist		*create_llist(void)
{
	t_llist		*ret_llist;
	t_lnode		*node;

	ret_llist = (t_llist *)malloc(sizeof(t_llist ));
	if (!ret_llist)
		return (NULL);
	node = (t_lnode *)malloc(sizeof(t_lnode));
	if (!node)
	{
		free(ret_llist);
		return (NULL);
	}
	ret_llist->head = node;
	ret_llist->tail = node;
	ret_llist->size = 0;
	return (ret_llist);
}

int			insert_data_tail(t_llist *list, data_type *data)
{
	t_lnode	*node;

	node = (t_lnode *)malloc(sizeof(t_lnode));
	if (!node)
		return (0);
	node->data = data;
	node->next = NULL;
	list->tail->next = node;
	list->tail = node;
	list->size++;
	return (1);
}

int			insert_data_head(t_llist *list, data_type *data)
{
	t_lnode	*node;

	node = (t_lnode *)malloc(sizeof(t_lnode));
	if (!node)
		return (0);
	node->data = data;
	node->next = list->head->next;
	list->head->next = node;
	list->size++;
	return (1);
}

data_type	*delete_data_tail(t_llist *list)
{
	t_lnode		*temp;
	data_type	*data;

	temp = list->head;
	while (temp->next != list->tail)
		temp = temp->next;
	if (!temp->next)
		data = NULL;
	else
		data = temp->next->data;
	free(temp->next);
	list->size--;
	return (data);
}

data_type	*delete_data_head(t_llist *list)
{
	t_lnode		*temp;
	data_type	*data;

	if (list->size == 0)
		return (NULL);
	temp = list->head;
	while (temp->next != list->tail)
		temp = temp->next;
	data = temp->next->data;
	free(temp->next);
	list->size--;
	return (data);
}

data_type	*delete_data_tail(t_llist *list)
{
	t_lnode		*temp;
	data_type	*data;

	if (list->size == 0)
		return (NULL);
	temp = list->head->next;
	list->head->next = temp->next;
	free(temp);
	list->size--;
	return (data);
}

void		delete_llist(t_llist *list)
{
	t_lnode		*curr;
	t_lnode		*temp;

	curr = list->head;
	while (curr)
	{
		temp = curr;
		curr = temp->next;
		free(temp);
	}
}
