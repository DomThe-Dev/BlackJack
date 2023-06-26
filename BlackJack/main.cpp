#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void draw(std::vector<int> &hand, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		hand.push_back(rand() % 13 + 1);
	}
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

std::string whatHave(std::vector<int> hand)
{
	for (int card : hand)
	{
		switch (card)
		{
		case 1:
			return " You have an Ace";
			break;
		case 11:
			return "You have a Jack";
			break;
		case 12:
			return "You have a Queen";
			break;
		case 13:
			return "You have a King";
			break;
		default:
			return std::to_string(card);
			break;
		}
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

	draw(hand, 2);

	for (int i : hand)
	{
		std::cout << cardType(i) << std::endl;
	}
	

	// moves

	// results
}