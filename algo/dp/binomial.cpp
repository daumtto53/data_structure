#include <iostream>

int		memo[1001][1001];

void	init_memo(int memo[][1001])
{
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			memo[i][j] = -1;
}

int		binomial_topdown(int n, int k, int memo[][1001])
{
	if (memo[n][k] != -1)
		return (memo[n][k]);
	if (n == k || k == 1)
		memo[n][k] = 1;
	else
		memo[n][k] = binomial_topdown(n - 1, k - 1, memo) + binomial_topdown(n - 1, k, memo);
	return (memo[n][k]);
}

using namespace std;

int		main()
{
	int		N, K;
	int		bin;

	bin = 1;
	cin >> N >> K;
	init_memo(memo);
	bin = binomial_topdown(N + 1, K, memo);
	cout << bin;

	for (int i = 0 ; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			cout << memo[i][j] << ' ';
		cout << std::endl;
	}
	cout << std::endl;
}
