//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#include "War.h"
#include "Card.h"

// cap the rounds at 5000 so game stops at a point.
const int War::roundsMax = 5000;
Hand War::P1;
Hand War::P2;
bool War::Skip = false;
int War::rounds = 1;

War::War() {}

void War::Start()
{
    cout << "This is a game of War... At any time in the game you may enter any letter to skip to the end, Enjoy!!" << endl << endl;
		rounds = 1;
		Skip = false;
		//initialize the deck and each players hands
		Hand deck = Hand::fullDeck();
		deck.shuffle();
		P1 = Hand();
		P2 = Hand();

		//Deal the cards out to the players
		//A full deck has an even number of cards
		while (!deck.empty())
		{
			P1.placeBottom(deck.drawTop());
			P2.placeBottom(deck.drawTop());
		}

		//Compare the cards until one player runs out of cards
		while (!P1.empty() && !P2.empty())
		{
			battle();

			if (++rounds > roundsMax)
			{
				cout << "This game of War has gone on for too long." << endl;
				break;
			}

			if (!Skip) checkSkip();
		}

		// print results
		winner();

}


void War::battle()
{
	Card p1Card = P1.drawTop();
	Card p2Card = P2.drawTop();

	printCards(p1Card.name(), p2Card.name());

	if (p1Card.getValue() == p2Card.getValue())
	{
		int winner = war();

		if (winner == 1)
		{
			P1.placeBottom(p1Card);
			P1.placeBottom(p2Card);

			cout << endl << "Player1";
		}
		else if (winner == 2)
		{
			P2.placeBottom(p1Card);
			P2.placeBottom(p2Card);

			cout << endl << "Player2";
		}
		cout << " won the battle!" << endl;
	}
	else if (p1Card.getValue() > p2Card.getValue())
	{
		P1.placeBottom(p1Card);
		P1.placeBottom(p2Card);
		cout << endl << "Player1 won this round." << endl;
	}
	else if (p2Card.getValue() > p1Card.getValue())
	{
		P2.placeBottom(p1Card);
		P2.placeBottom(p2Card);
		cout << endl << "Player2 won this round." << endl;
	}
}

int War::war()
{
	Hand warCards;
	Card p1Card, p2Card;
	int winner = 0;

	do
	{
		cout << "Get ready, WAR!!" << endl;

		if (!Skip) checkSkip();

		//If a player is out of cards, then the other player wins
		if (P1.empty())
		{
			cout << "Player1 is out of cards." << endl;
			winner = 2;
			break;
		}
		else if (P2.empty())
		{
			cout << "Player2 is out of cards." << endl;
			winner = 1;
			break;
		}

		//Put down three extra cards for each player
		for (int i = 0; i < 3; i++)
		{
			//Save one card for the comparison
			if (P1.size() > 1) warCards.placeBottom(P1.drawTop());
			if (P2.size() > 1) warCards.placeBottom(P2.drawTop());
		}

		//We'll compare the next two cards
		p1Card = P1.drawTop();
		p2Card = P2.drawTop();
		warCards.placeBottom(p1Card);
		warCards.placeBottom(p2Card);

		printCards(p1Card.name(), p2Card.name());
	} while (p1Card.getValue() == p2Card.getValue());

	//Give the spoils to the winner
	if (p1Card.getValue() > p2Card.getValue() || winner == 1)
	{
		int cardSize = warCards.size();
		for (int i = 0; i < cardSize; i++)
			P1.placeBottom(warCards.drawTop());

		winner = 1;
	}
	else if (p2Card.getValue() > p1Card.getValue() || winner == 2)
	{
		int cardSize = warCards.size();
		for (int i = 0; i < cardSize; i++)
			P2.placeBottom(warCards.drawTop());

		winner = 2;
	}

	return winner;
}

void War::winner()
{
	//Check if an infinite loop scenario has occurred.
	if (rounds > roundsMax)
	{
		cout << "The war ends in a DRAW." << endl << endl;
	}
	else
	{
		if (P1.empty())
		{
			cout << "Player2 won the war!" << endl << endl;;
		}
		else //If player2.empty()
		{
			cout << "Player1 won the war!" << endl << endl;;
		}
	}
}

void War::checkSkip()
{
	cin.sync();
	char ans;
	cin.get(ans);
	if (isalpha(ans))
        Skip = true;
	else
        Skip = false;
}

void War::printCards(string p1Card, string p2Card)
{
	//Print out the names, hand sizes, and card names
	cout << "Player1 " << "[" << P1.size()+1 << "]: " << p1Card << endl << "Player2 " << "[" << P2.size()+1 << "]: " << p2Card << endl;
}

int main()
{
	War::Start();

	return 0;
}
