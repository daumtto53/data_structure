/* *********************************************************************************************************************** */
/*  UTC Header                                                                                                             */
/*                                                        ::::::::::::::::::::       :::    ::: :::::::::::  ::::::::      */
/*     boj_2491.cpp                                       ::::::::::::::::::::       :+:    :+:     :+:     :+:    :+:     */
/*                                                        ::::::::::::::+++#####+++  +:+    +:+     +:+     +:+            */
/*     By: chemicat53 <daumtto53@gmail.com>               ::+++##############+++     +:+    +:+     +:+     +:+            */
/*     daumtto53@gmail.com                            +++##############+++::::       +#+    +:+     +#+     +#+            */
/*                                                      +++##+++::::::::::::::       +#+    +:+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       +#+    +#+     +#+     +#+            */
/*                                                        ::::::::::::::::::::       #+#    #+#     #+#     #+#    #+#     */
/*     Update: 2021/08/20 22:10:21 by chemicat53          ::::::::::::::::::::        ########      ###      ######## .fr  */
/*                                                                                                                         */
/* *********************************************************************************************************************** */

#include <iostream>
#include <algorithm>


/*
	https://www.acmicpc.net/problem/2491
	아직 안풀림
*/

using namespace std;

int		main()
{
	int		asc_max = 0;
	int		dsc_max = 0;
	int		arr[100000];
	int		n;
	int		i, j, k;
	int		count = 0;

	std::cin >> n;
	for (i = 0; i < n; i++)
		std::cin >> arr[i];

	count = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] >= arr[i + 1])
			count++;
		asc_max = asc_max > count ? asc_max : count;
		if (arr[i] < arr[i + 1])
			count = 0;
	}

	count = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] <= arr[i + 1])
			count++;
		dsc_max = dsc_max > count ? dsc_max : count;
		if (arr[i] > arr[i + 1])
			count = 0;

	}
	cout << max(asc_max, dsc_max);

	std::cin >> n;
	return (0);
}
