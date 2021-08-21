/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     1463.cpp                                           ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/21 10:54:21 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

/*
	https://www.acmicpc.net/problem/1463

	make_1_rec : Top-down
	make_1 : Bottom-up

	make_1_rec : 메모리 초과
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int		partial[1000001] = {0, };

int		make_1(int N)
{
	int		i;

	for (i = 4; i <= N; i++)
	{
		partial[i] = partial[i - 1] + 1;
		if (i % 3 == 0)
			partial[i] = min(partial[i], partial[i / 3] + 1);
		if (i % 2 == 0)
			partial[i] = min(partial[i], partial[i / 2] + 1);
	}
	return partial[N];
}

int		make_1_rec(int N)
{
	int		div_3;
	int		div_2;
	int		min_1;
	int		ret;

	div_3 = INT_MAX;
	div_2 = INT_MAX;
	min_1 = INT_MAX;
	if (N == 1)
		return partial[1];
	if (partial[N] != 0)
		return (partial[N]);
	if (N % 3 == 0)
		div_3 = make_1_rec(N / 3);
	if (N % 2 == 0)
		div_2 = make_1_rec(N / 2);
	min_1 = make_1_rec(N - 1);

	ret = min(min(div_3, div_2), min_1) + 1;
	partial[N] = ret;
	return (ret);
}

int main()
{
	int		N;
	cin >> N;

	partial[0] = 0;
	partial[1] = 0;
	partial[2] = 1;
	partial[3] = 1;
	cout << make_1(N);
}
