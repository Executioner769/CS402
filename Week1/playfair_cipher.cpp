#include <bits/stdc++.h>
using namespace std;

int main()
{
	char grid[5][5];
	string s;
	cin >> s;
	string key;
	cin >> key;

	int n = 0;

	unordered_map<char, int> umap;
	unordered_map<char, pair<int, int>> u;
	
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < 5; i++)
	{

		for (j = 0; j < 5; j++)
		{
			if (n >= key.size())
			{
				flag = 1;
				break;
			}
			grid[i][j] = key[n];
			umap[key[n]]++;
			u[key[n]] = make_pair(i, j);
			n++;
		}
		if (flag)
			break;
	}
	int k = i;
	int z = j;

	for (char x = 'a'; x <= 'z'; x++)
	{
		if (x != 'j')
		{
			if (umap[x])
			{
			}
			else
			{
				grid[k][z] = x;
				u[x] = make_pair(k, z);
				if (k == 4 and z == 4)
					break;
				if (z == 4)
				{
					z = 0;
					k++;
				}
				else
				{
					z++;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	string ans = "";

	if (s.size() % 2 != 0)
	{
		s += 'z';
	}
	for (int i = 0; i < s.length(); i++)
	{
		string ss;
		ss += s[i];
		if (s[i] != s[i + 1] && i != s.length() - 1)
		{

			ss += s[i + 1];
			i++;
			cout << ss << endl;
		}

		else
		{
			if (ss[0] != 'x')
				ss += 'x';
			else
				ss += 'y';
			cout << ss << endl;
		}

		int x = u[ss[0]].first;

		int y = u[ss[0]].second;
		int x1 = u[ss[1]].first;
		int y1 = u[ss[1]].second;

		if (y == y1)
		{

			if (x == 4)
			{
				x = -1;
			}
			if (x1 == 4)
			{
				x1 = -1;
			}
			ans += grid[x + 1][y];
			ans += grid[x1 + 1][y];
		}
		else if (x == x1)
		{

			if (y == 4)
			{
				y = -1;
			}
			if (y1 == 4)
			{
				y1 = -1;
			}

			ans += grid[x][y + 1];
			ans += grid[x1][y + 1];
		}
		else
		{
			ans += grid[x][y1];
			ans += grid[x1][y];
		}
	}
	cout << ans << endl;
}
