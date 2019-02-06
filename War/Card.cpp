//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#include "card.h"

string Card::suitName (Suit s)
{
	switch(s) {
		case clubs: return "Clubs";
		case diamonds: return "Diamonds";
		case hearts: return "Hearts";
		case spades: return "Spades";
	}
}
// sets values to each card
string Card::rankName (Rank r)
{
	switch(r)
	{
	case ace: return "Ace";
	case two: return "2";
	case three: return "3";
	case four: return "4";
	case five: return "5";
	case six:  return "6";
	case seven: return "7";
	case eight: return "8";
	case nine: return "9";
	case ten: return "10";
	case jack: return "Jack";
	case queen: return "Queen";
	case king: return "King";
	}
}

