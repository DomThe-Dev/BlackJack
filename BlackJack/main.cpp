#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int handTotal(std::vector<int> hand)
{
	int total = 0;
	for (int i : hand)
	{
		if (i != 12 && i != 13 && i != 14)
		{
			total += i;
			continue;
		}
		total += 10;
	}
	return total;
}

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

	if (aces == 0)
		return true;

	for (int i = 0; i < hand.size(); i++)
	{
		if (hand.at(i) == 11)
		{
			hand.at(i) = 1;
			return isBust(hand);
			break;
		} 
	}
	return true;
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

std::string whatHave(std::vector<int> hand, bool amount)
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

	if (!amount)
		return cards.begin();
	return cards;
}

int main()
{
	std::srand(time(0));

	// Variables created
	std::vector<int> hand;
	std::vector<int> dHand;

	int money = 250;

	// Betting
	// Need to make this prompt string dissapear afterwards. Currently
	// it's just floating there for the rest of the game.
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

	// Draw cards
	draw(hand, 2);
	draw(dHand, 2);

	// What does dealer have

	std::cout << whatHave(hand, true) << std::endl;

	// moves player
	while (true)
	{
		// No code before this. This line fixes the aces to ones or 11s.
		if (isBust(hand))
		{
			std::cout << "Bust!" << std::endl;
			break;
		}
		std::cout << handTotal(hand) << std::endl;
		 
		std::string answer;
		std::cout << "Would you like to draw a card? y/n" << std::endl;
		std::cin >> answer;

		if (answer == "y")
		{
			draw(hand, 1);
			std::cout << whatHave(hand, false) << std::endl;
		}
		else if (answer == "n")
		{
			break;
		}
	}

	// moves dealer

	// results
}