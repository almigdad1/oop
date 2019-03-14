//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#include "Hand.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>

Hand::Hand() {}

Hand Hand::fullDeck()
{
	Hand deck;

	const int suitNum = 4;
	const int rankNum = 13;
	Suit suit[suitNum] = {clubs, diamonds, hearts, spades};
	Rank face[rankNum] = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

	for (int i = 0; i < suitNum; i++)
	{
		for (int j = 0; j < rankNum; j++)
		{
			deck.placeBottom(Card(face[j], suit[i]));
		}
	}

	return deck;
}

// Shuffling the deck

void Hand::Shuffle()
{

	srand(time(0) + size());
	for (int i = 0; i < size(); i++)
	{
		int newIndex = rand()%size();
		cards.insert(cards.begin() + newIndex, cards.at(i));
		cards.erase(cards.begin() + i);
	}
}


Card Hand::drawTop()
{
	Card drawnCard=cards.at(0);
	cards.erase(cards.begin());
	return drawnCard;
}

Card Hand::drawBottom()
{
	Card card = cards.back();
	cards.erase(cards.end());
	return card;
}

void Hand::placeTop(Card c)
{
	cards.insert(cards.begin(), c);
}

void Hand::placeBottom(Card c)
{
	cards.push_back(c);
}

bool Hand::empty()
{
	return cards.empty();
}

int Hand::size()
{
	return cards.size();
}
