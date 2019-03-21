#include<iostream>
#include<math.h>

#define PI 3.1415926535
#define PIOVERTWO 1.570796326


int main()
{
	int h, v;

	std::cin >> h >> v;

	if (v <= 180)
	{
		std::cout << "safe";
	}
	else
	{
		std::cout << (int)(h / cos(PI * v / 180.0 + PIOVERTWO));
	}

}