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
		// === Rank and Value ===
		// Ge a random number between 2 and 14, including 2 and 14.
		// Don't need 1, as ace is usually 11, unless person has gone bust.
		short i = rand() % 13 + 2;

		// Value is almost the same as the card, but the 11 from an ace can change
		// to a 1, and Jacks, Queens, and Kings all equal 10. For this reason, 
		// if the random number is equal to or less than 11, the value is 11. Otherwise, it's 10.
		if (i <= 11)
			value = i;
		else if (i > 11)
			value = 10;

		// Rank is the thing that is displayed, while value is what is used
		// Rank will show if card is an Ace, Jack, Queen or King.
		if (i == 11)
			rank = 'A';
		else if (i == 12)
			rank = 'J';
		else if (i == 13)
			rank = 'Q';
		else if (i == 14)
			rank = 'K';
		else
			rank = std::to_string(value);
		
		// When trying to display the rank in the card, a 10 screws up the art, as it's 2 characters
		// rather than the usual 1. This code replaces the replacement characters in the display art
		// with the card's rank
		if (i == 10)
		{
			cardDisplay.replace(cardDisplay.find('#'), 2, rank);
			cardDisplay.replace(cardDisplay.find('@') - 1, 2, rank);
		}
		else
		{
			cardDisplay.replace(cardDisplay.find('#'), 1, rank);
			cardDisplay.replace(cardDisplay.find('@'), 1, rank);
		}
		
		// This code reuses the i and generates a number between 1 and 4.
		// Depending on the number, a different suit is generated.
		i = rand() % 4 + 1;
		if (i == 1)
			suit = '\3';
		if (i == 2)
			suit = '\4';
		if (i == 3)
			suit = '\5';
		if (i == 4)
			suit = '\6';
		
		// The suit replaces the ! in the card display string.
		cardDisplay.replace(cardDisplay.find('!'), 1, suit);
	}
private:

public:
	short value;
	std::string suit;
	std::string rank;
	bool hidden = false;
	std::string cardDisplay =
		"+---------+\n"
		"|#........|\n"
		"|.........|\n"
		"|.........|\n"
		"|....!....|\n"
		"|.........|\n"
		"|.........|\n"
		"|........@|\n"
		"+---------+\n";
};

class User
{
private:
	bool bust = false;

public:
	std::vector<Card> hand;
	void drawCard(short amount)
	{
		for (short i = 0; i < amount; i++)
		{
			Card card;
			hand.push_back(card);
		}
	}

	bool isBust()
	{
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
	User player;

	for (int i = 0; i < 15; i++)
	{
		player.drawCard(1);
	}
	for (auto i : player.hand)
	{
		std::cout << i.cardDisplay << std::endl;
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