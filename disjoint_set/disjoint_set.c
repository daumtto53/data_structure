/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     disjoint_set.c                                     ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/14 20:22:36 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

#include "disjoint_set.h"

int		*create_disjoint_set(int size)
{
	int		*ds;

	ds = (int *)malloc(sizeof(int) * size);
	if (!ds)
		return (NULL);
	for (int i = 0; i < size; i++)
		ds[i] = -1;
	return ds;
}

int		disjoint_set_find(int *parent, int src)
{
	if (parent == NULL)
	if (parent[src] < 0)
		return (src);
	parent[src] = disjoint_set_find(parent, parent[src]);
	return (parent[src]);
}

void	disjoint_set_union(int *parent, int x, int y)
{
	int		parent_x;
	int		parent_y;

	if (!parent)
		return ;
	if ((parent_x = disjoint_set_find(parent, x)) == (parent_y = disjoint_set_find(parent, y)))
		return ;
	if (-1 * parent[parent_x] < -1 * parent[parent_y])
		parent[parent_x] = parent_y;
	else if (-1 * parent[parent_y] < -1 * parent[parent_x])
		parent[parent_y] = parent_x;
	else
	{
		parent[parent_y] = parent_x;
		parent[parent_y]--;
	}
}
