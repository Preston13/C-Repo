#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<algorithm>

int main()
{
	int n;
	int oldyear = 0;

	std::unordered_map<std::string, std::vector<int>> vacations;
	std::unordered_set<std::string> countries;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string name;
		std::cin >> name;

		int year;
		std::cin >> year;

		countries.insert(name);

		if (vacations.count(name) < 1) {
			std::vector<int> vect;
			vect.push_back(year);
			vacations.insert({ name, vect });
		}
		else {
			std::vector<int>& temp = vacations[name];
			temp.push_back(year);
		}
	}

	int m;
	std::cin >> m;

	for (std::string d : countries) {
		std::vector<int>& temp = vacations[d];
		sort(temp.begin(), temp.end());
	}

	for (int i = 0; i < m; i++) {
		std::string dest;
		std::cin >> dest;

		int trip;
		std::cin >> trip;

		std::vector<int>& temp = vacations[dest];

		std::cout << temp[trip - 1] << std::endl;
	}
}