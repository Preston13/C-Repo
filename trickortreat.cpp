#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>

double X[65536], Y[65536];
int n;

double calc(double val)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result = std::max(result, (X[i] - val) * (X[i] - val) + Y[i] * Y[i]);
	}
	return result;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &X[i], &Y[i]);
		}
		double left, right, mid, midmid, md, mmd;


#define INF 200000
#define eps 1e-10

		left = -INF, right = INF;
		while (fabs(left - right) > eps)
		{
			mid = (left + right) / 2;
			midmid = (mid + right) / 2;
			md = calc(mid);
			mmd = calc(midmid);
			if (md < mmd) {
				right = midmid;
			}
			else
			{
				left = mid;
			}
		}

		printf("%.9lf %.9lf\n", mid, sqrt(md));
	}
}