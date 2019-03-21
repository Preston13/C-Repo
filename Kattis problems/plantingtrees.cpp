#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, days = 2, latest = 0, tree;

	std::cin >> n;
	std::vector<int> treeVect;

	for (int i = 0; i < n; i++)
	{
		std::cin >> tree;
		treeVect.push_back(tree);		
	}

	std::sort(treeVect.begin(), treeVect.begin() + n);

	std::reverse(treeVect.begin(), treeVect.end());

	for (int seed : treeVect)
	{
		int treeTime = seed + days;
		if (treeTime > latest)
		{
			latest = treeTime;
		}
		days++;
	}

	std::cout << latest;
}