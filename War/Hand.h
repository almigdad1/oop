//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#ifndef __HAND_H_
#define __HAND_H_

#include "Card.h"
#include <vector>
using std::vector;

class Hand
{
public:
	Hand();
	//Default constructor, empty hand.
	static Hand fullDeck();
	// Full deck of cards
	void shuffle();
	//Mixes up the cards
	Card drawTop();
	Card drawBottom();
	//Returns the card from the top or bottom of the hand, removes that card
	void placeTop(Card c);
	void placeBottom(Card c);
	//Places the card on the top or bottom of the hand
	bool empty();
	//true if hand is empty, false otherwise.
	int size();
	//Returns how many cards are in the hand
private:
	vector<Card> cards;
};

#endif

