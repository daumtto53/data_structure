/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     TRIANGLEPATH.cpp                                   ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/18 21:07:20 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstring>

int		memo[100][100];
int		arr[100][100];

int		sub_path(int x, int y, int size)
{
	int		max_path;
	int		path1;
	int		path2;

	if (y == size - 1)
		return (arr[y][x]);
	if (memo[y][x] != 0)
		return (memo[y][x]);
	else
	{
		path1 = arr[y][x] + sub_path(x, y + 1, size);
		path2 = arr[y][x] + sub_path(x + 1, y + 1, size);
		max_path = std::max(path1, path2);
		memo[y][x] = max_path;
		return (max_path);
	}
}

using namespace std;

int		main()
{
	int		tc;
	int		n;
	int		i,j;

	cin >> tc;
	while (tc--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			for (j = 0; j <= i; j++)
				memo[i][j] = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
				cin >> arr[i][j];
		}
		cout << sub_path(0, 0, n) << endl;
	}
	return (0);
}
