/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     disjoint_set.h                                     ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/14 20:22:24 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

#ifndef DISJOINT_SET_H
# define DISJOINT_SET_H

# include <stddef.h>

int		*create_disjoint_set(int size);
int		disjoint_set_find(int *parent, int src);
void	disjoint_set_union(int *parent, int x, int y);

#endif
