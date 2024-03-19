/*
BlackJack V1.1
By Dominykas Jucys

The previous GitHub repository has been deleted, due to it being made when I knew little about GitHub
meaning that the file structure and such was an absolute mess. Nonetheless, the code from there will be 
copied over here, in the hopes of showing off the very first version of my BlackJack game.
*/
#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>
#include <numeric>

class Card
{
public:
	Card()
	{
		switch (int i = rand() % 13 + 2)
		{
		case 11:
			value = 11;
			rank = "Ace";
			break;
		case 12:
			value = 10;
			rank = "Jack";
			break;
		case 13:
			value = 10;
			rank = "Queen";
			break;
		case 14:
			value = 10;
			rank = "King";
			break;
		default:
			value = i;
			rank = std::to_string(i);
		}
	}
private:

public:
	short value;
	std::string suit;
	std::string rank;
};


class User
{
private:
	std::vector<Card> hand;
	bool bust = false;

public:
	void drawCard(short amount)
	{
		for (short i = 0; i < amount; i++)
		{
		}
	}

	bool isBust()
	{
		/*
		int sumOfHand = std::accumulate(hand.begin(), hand.end(), 0);

		if (sumOfHand < 21)
			return false;

		int numOfAces = std::count(hand.begin(), hand.end(), 11);
		*/
		return false;
	}
	std::string displayCards()
	{
		std::string cards;

		return cards;
	}
	
};

int main()
{
	// The game has 4 phases:
	//	Main Menu - Menu, buttons, stats, etc.
	//	Pre-Game - Bet money, draw cards
	//	Main Game - Game loop of drawing and standing
	//	Post Game - Comparison, dealer drawing, result

	std::srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		Card card;
		std::cout << card.value << ", ";
		std::cout << card.rank << std::endl;
	}

	// Main Menu


	// Pre-Game



	// Main Game



	// Post Game



	return 0;
}






/*
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Player
{

};

void result(int res, int bet, int& money)
{
	if (res == 1)
	{
		std::cout << "You win!" << std::endl;
		money += (bet * 2);
		std::cout << "You now have: " << money << " credits." << std::endl;
	}
	else if (res == 2)
	{
		std::cout << "You lose!" << std::endl;
		std::cout << "You now have: " << money << " credits." << std::endl;
	}
	else if (res == 3)
	{
		std::cout << "You draw!" << std::endl;
		money += bet;
		std::cout << "You have: " << money << " credits." << std::endl;
	}
}

void draw(std::vector<int>& hand, int amount)
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

void whatHave(std::vector<int> hand, int which)
{
	if (!(which < 0) || !(which >= hand.size()))
	{
		switch (hand.at(which))
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
			std::cout << hand.at(which);
			break;
		}
		std::cout << "." << std::endl;
		return;
	}

	int timesRun = 0;

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

		if (timesRun == (hand.size() - 1))
		{
			std::cout << " and ";
		}
		else if (timesRun == hand.size())
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

int money = 250;

int main()
{
	while (true)
	{
		std::srand(time(0));

		// Variables created
		std::vector<int> hand;
		std::vector<int> dHand;

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
		whatHave(dHand, 0);

		// moves player
		while (true)
		{
			std::cout << "\nYou have: " << std::endl;
			whatHave(hand, -1);

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
				std::cout << "You drew: " << std::endl;
				whatHave(hand, hand.size() - 1);
			}
			else if (answer == "n")
			{
				break;
			}
		}

		// moves dealer

		while (!isBust(dHand) && !isBust(hand))
		{
			std::cout << "\nDealer has:" << std::endl;
			whatHave(dHand, -1);

			if (handTotal(dHand) >= handTotal(hand) || handTotal(dHand) > 17)
				break;

			draw(dHand, 1);
			std::cout << "Dealer drew: " << std::endl;
			whatHave(dHand, dHand.size() - 1);
		}

		if (isBust(dHand) || handTotal(hand) > handTotal(dHand) && !isBust(hand))
		{
			result(1, bet, money);
		}
		else if (isBust(hand) || handTotal(dHand) > handTotal(hand))
		{
			result(2, bet, money);
		}
		else if (handTotal(dHand) == handTotal(hand))
		{
			result(3, bet, money);
		}
		std::cout << std::endl;
		// results
	}
}

*/