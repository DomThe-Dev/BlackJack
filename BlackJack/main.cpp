#include <iostream>
#include <sstream>

bool checkInt(std::string input)
{
	for (char i : input)
	{
		if (!isdigit(i))
			return false;
	}
	return true;
}

int main()
{
	// bet
	int money = 250;
	std::string prompt;
	while (true)
	{
		std::cout << "Please input a number!" << std::endl;
		std::cin >> prompt;
		if (checkInt(prompt))
			break;
	}
	int bet = std::stoi(prompt);
	money -= bet;


	// draw

	// moves

	// results
}