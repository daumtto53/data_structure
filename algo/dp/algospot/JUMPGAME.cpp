/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     JUMPGAME.cpp                                       ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/18 12:20:52 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

/*
	DP : https://www.algospot.com/judge/problem/read/JUMPGAME
	ground_fullsearch : 완전탐색
	ground_dp : memoization
*/
int		memo[100][100];
// -1 : 길이 있음 / 0 : 길이 없음
bool	ground_dp(int arr[][100], int size, int x, int y)
{
	if (x == size - 1 && y == size - 1)
		return (true);
	if (x > size - 1 || y > size - 1)
		return (false);
	if (!memo[x][y])
		return (false);

	memo[x][y] = ((ground_dp(arr, size, x + arr[x][y], y) || ground_dp(arr, size, x, y + arr[x][y])) ? -1 : 0);
	return (memo[x][y] == -1);
}

bool	ground_fullsearch(int arr[][100], int size, int x, int y)
{
	if (x == size - 1 && y == size - 1)
		return (true);
	if (x > size - 1 || y > size - 1)
		return (false);

	return (ground_fullsearch(arr, size, x + arr[x][y], y) || ground_fullsearch(arr, size, x, y + arr[x][y]));
}

int		main()
{
	int		tc;
	int		n;
	int		map[100][100];
	int i,j,k;
	int		ret;

	cin >> tc;

	while (tc--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			memo[i][j] = -1;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> map[i][j];
		ret = ground_dp(map, n, 0, 0);
		if (ret)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return (0);
}
