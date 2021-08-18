#include <iostream>
#include <algorithm>

/*
	이항계수와 DP
	1. 이항계수 식 nCr 을 이용한 이항계수 구하기 알고리즘
	2. 이항계수의 재귀적 정의를 이용한 알고리즘
	3.  DP를 이용한 알고리즘 ( Top-down, bottom-up)
	4. Bottom-up의 최적화
*/

int		memo[1001][1001];

using namespace std;

void	init_memo(int memo[][1001])
{
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			memo[i][j] = -1;
}

int		factorial(int n)
{
	if (n == 1)
		return (1);
	return (factorial(n - 1) * n);
}

int		binomial_factorial(int n, int k)
{
	return (factorial(n) / (factorial(n - k) * factorial(k)));
}

int		binomial_nondp(int n, int k)
{
	if (k == 0 || k == n)
		return (1);
	else
		return (binomial_nondp(n- 1, k - 1) + binomial_nondp(n - 1, k));
}

int		binomial_topdown(int n, int k, int memo[][1001])
{
	if (memo[n][k] != -1)
		return (memo[n][k]);
	if (n == k || k == 0)
		memo[n][k] = 1;
	else
		memo[n][k] = binomial_topdown(n - 1, k - 1, memo) + binomial_topdown(n - 1, k, memo);
	return (memo[n][k]);
}

int		binomial_bottomup(int n, int k)
{
	int		mem[101][101];
	int		i, j;

	if (k < n / 2)
		k = n - k;
	for (i = 0; i <= n; i++)
	{
		for (j = std::min(i,k); j >= 0; j--)
		{
			if (j == 0 || j == i)
				mem[i][j] = 1;
			else
				mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
		}
	}
	return (mem[n][k]);
}

int		binomial_bottomup_1darray(int n, int k)
{
	int mem[1001];
	int	i,j;

	if (k < n / 2)
		k = n - k;
	mem[0] = 1; mem[1] = 1;
	for (i = 0; i <= n; i++)
	{
		for (j = min(i, k); j >= 0; j--)
			if (j == 0 || j == i)
				mem[j] = 1;
			else
				mem[j] = mem[j - 1] + mem[j];
	}
	return (mem[k]);
}

int		main()
{
	int		N, K;
	int		bin;

	bin = 1;
	cin >> N >> K;
	init_memo(memo);
	bin = binomial_topdown(N, K, memo);
	cout << bin;
	cout << std::endl;

	bin = binomial_bottomup(N, K);
	cout << bin << std::endl;

	bin = binomial_bottomup_1darray(N, K);
	cout << bin << endl;

	bin = binomial_nondp(N, K);
	cout << bin << endl;

	bin = binomial_factorial(N, K);
	cout << bin << endl;
}
