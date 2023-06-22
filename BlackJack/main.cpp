#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void draw(std::vector<int> &hand)
{
	hand.push_back(rand() % 13 + 1);
}

bool checkInt(std::string input)
{
	for (char i : input)
	{
		if (!isdigit(i))
			return false;
	}
	return true;
}

std::string cardType(int card)
{
	switch (card)
	{
	case 1:
		return "Ace";
		break;
	case 11:
		return "Jack";
		break;
	case 12:
		return "Queen";
		break;
	case 13:
		return "King";
		break;
	default:
		return std::to_string(card);
		break;
	}
}

int main()
{
	std::srand(time(0));

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
	std::vector<int> hand;

	for (int i = 0; i < 200; i++)
	{
		draw(hand);
	}

	for (int i : hand)
	{
		std::cout << i << std::endl;
	}
	

	// moves

	// results
}