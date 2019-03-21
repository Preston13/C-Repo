#include<iostream>
#include <vector>

int main()
{
	int d, r, t;

	std::vector<int> rVect;
	std::vector<int> tVect;

	rVect.resize(70, 0);
	tVect.resize(70, 0);

	std::cin >> d >> r >> t;

	for (int i = 0; i < rVect.size(); i++)
	{
		if (i >= 3)
		{
			tVect[i] = (i + tVect[i - 1]);
		}
		if (i >= 4)
		{
			rVect[i] = (i + rVect[i - 1]);
		}
	}

	int c = d;

	while (true)
	{
		
		if (tVect[c - d] + rVect[c] == r + t)
		{
			std::cout << r - rVect[c] << std::endl;
			break;
		}
		c++;
	}
}