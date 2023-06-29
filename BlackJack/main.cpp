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

void whatHave(std::vector<int> hand, int amount)
{
	int timesRun = 0;
	if (amount == 0 || amount > hand.size() || amount < 0)
		amount = hand.size();

	for (int card : hand)
	{

		switch (card)
		{
		case 1:
			std::cout << "Ace";
			break;
		case 11:
			std::cout << "Ace";
			break;
		case 12:
			std::cout << "Jack";
			break;
		case 13:
			std::cout << "Queen";
			break;
		case 14:
			std::cout << "King";
			break;
		default:
			std::cout << card;
			break;
		}
		timesRun++;

		if (timesRun == (amount - 1))
		{
			std::cout << " and ";
		}
		else if (timesRun == amount)
		{
			std::cout << "." << std::endl;
			break;
		}
		else
		{
			std::cout << ", ";
		}
	}
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
	std::cout << "Dealer has:" << std::endl;
	whatHave(dHand, 1);

	// moves player
	while (true)
	{
		std::cout << "You have: " << std::endl;
		whatHave(hand, 0);

		// No code before this. This line fixes the aces to ones or 11s.
		if (isBust(hand))
		{
			std::cout << "Bust!" << std::endl;
			break;
		}
		 
		std::string answer;
		std::cout << "Would you like to draw a card? y/n" << std::endl;
		std::cin >> answer;

		if (answer == "y")
		{
			draw(hand, 1);
			std::cout << "You drew: " << hand.at(hand.size() - 1) << "." << std::endl;
		}
		else if (answer == "n")
		{
			break;
		}
	}

	// moves dealer

	// results
}