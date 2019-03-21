#include<iostream>
#include<string>

int main() 
{
	std::string word;
	std::string beginning;
	std::string end;
	std::string newWord;

	while (std::cin >> word)
	{
		int i = 0;
		for (char c : word)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
			{
				if (i == 0)
				{
					newWord = word + "yay";
				}
				else
				{
					beginning = word.substr(0, i);
					end = word.substr(i + 1);

					newWord = c + end + beginning + "ay";
				}
				break;
			}
			i++;
		}
		std::cout << newWord << " ";
	}
}