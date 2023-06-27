#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

bool isBust(std::vector<int> &hand)
{
	int aces = 0;
	int total = 0;
	for (int i : hand)
	{
		if (i == 12 || i == 13 || i == 14)
		{
			total += 10;
		}
		else if (i == 11)
		{
			total += 11;
			aces++;
		}
		else
		{
			total += i;
		}
	}
	if (total < 22)
		return false;

	if (aces > 0)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand.at(i) == 11)
			{
				hand.at(i) = 1;
				break;
			} 
		}
	}
}

void draw(std::vector<int> &hand, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		hand.push_back(rand() % 13 + 2);
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
	std::string cards = "";

	for (int card : hand)
	{
		switch (card)
		{
		case 1:
			cards.append("You have an Ace, ");
			break;
		case 11:
			cards.append("You have an Ace, ");
			break;
		case 12:
			cards.append("You have a Jack, ");
			break;
		case 13:
			cards.append("You have a Queen, ");
			break;
		case 14:
			cards.append("You have a King, ");
			break;
		default:
			cards.append("You have a " + std::to_string(card) + ", ");
			break;
		}
	}
	return cards;
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
	std::cout << whatHave(hand) << std::endl;

	// moves player
	while (true)
	{
		draw(hand, 1);
		
		std::string answer;
		std::cout << "Would you like to draw a card? y/n" << std::endl;
		std::cin >> answer;

		if (answer == "y")
		{
			draw(hand, 1);
			std::cout << whatHave(hand) << std::endl;
		}
		else if (answer == "n")
		{
			break;
		}
	}

	// moves dealer

	// results
}