//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#include "card.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Suit s)
{
	switch(s)
    {
		case clubs: return out << "Clubs";
		case diamonds: return out << "Diamonds";
		case hearts: return out << "Hearts";
		case spades: return out << "Spades";
	}
}
// sets values to each card
std::ostream& operator<<(std::ostream& out, Rank r)
{
	switch(r)
	{
	case ace: return out << "Ace";
	case two: return out << "2";
	case three: return out << "3";
	case four: return out << "4";
	case five: return out << "5";
	case six:  return out << "6";
	case seven: return out << "7";
	case eight: return out << "8";
	case nine: return out << "9";
	case ten: return out << "10";
	case jack: return out << "Jack";
	case queen: return out << "Queen";
	case king: return out << "King";
	}
}

// overload the out stream for card class
std::ostream& operator<<(std::ostream& out, Card c)
{
    return out << c.getValue() << " of " << c.getSuit();
}
// overload the out stream for the joker class
std::ostream& operator<<(std::ostream& out, Joker c)
{
    return out << c.getColor();
}
// overload the out stream for standard class
std::ostream& operator<<(std::ostream& out, Standard c)
{
    return out << c.getValue() << " of " << c.getSuit();
}
// overload the out steam for color c
std::ostream& operator<<(std::ostream& out, Color c)
{
    if(c == Black)
        return out << "Black Joker";
    else
        return out << "Red Joker";
}
// overload the out stream for kind
std::ostream& operator<<(std::ostream& out, Kind k)
{
    if(k == StandardKind)
        return out << "Standard Card";
    else
        return out << "Joker Card";
}
PlayingCard::PlayingCard() { }

//Get color
Color Joker::getColor() const
{
    return color;
}

//Get kind
Kind PlayingCard::getKind() const
{
    return kind;
}

//Get rank
Rank Standard::getValue() const
{
    return rank;
}

//Get suit
Suit Standard::getSuit() const
{
    return suit;
}


