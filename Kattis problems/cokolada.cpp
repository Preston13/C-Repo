#include<iostream>
#include<cmath>

int main() 
{
	long k, d;

	std::cin >> k;

	d = pow(2, ceil(log(k) / log(2)));

	std::cout << d;

	int sum = 0, breaks = 0;

	if (k == d)
	{
		breaks = 0;
		std::cout << " " << breaks;
		return 0;
	}

	while (true)
	{
		if (sum == k) 
		{
			break;
		}

		if (sum < k)
		{
			sum += d / 2;
			d = d / 2;
			breaks++;
		}

		if (sum > k)
		{
			sum -= d / 2;
			d = d / 2;
			breaks++;
		}

		

		
		
	}

	std::cout << " " << breaks;
}