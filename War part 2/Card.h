//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#ifndef ___CARD_H
#define ___CARD_H

#include <string>
using std::string;

enum Suit
 {
     clubs,
     diamonds,
     hearts,
     spades
 };

enum Rank
 {
     two,
     three,
     four,
     five,
     six,
     seven,
     eight,
     nine,
     ten,
     jack,
     queen,
     king,
     ace
 };

class Card {
public:
    Card (Rank r = two, Suit s = clubs) : bits((unsigned)s << 4 | (unsigned)r) { }
    Rank getValue() const { return(Rank) (0b00001111 & bits); }
    Suit getSuit() const { return(Suit) ((0b11110000 & bits) >> 4); }
    bool operator==(Card c) { return bits == c.bits; }
    bool operator!=(Card c) { return !(bits == c.bits); }
    friend bool operator<(Card a, Card b) { return a.getValue() < b.getValue(); }
    friend bool operator>(Card a, Card b) { return b.getValue() < a.getValue(); }
    friend bool operator<=(Card a, Card b) { return !(b.getValue() < a.getValue()); }
    friend bool operator>=(Card a, Card b) { return !(a.getValue() < b.getValue()); }

private:
		Rank rank;
		Suit suit;
		unsigned char bits;
};

//Overloading ostream operators
std::ostream& operator<<(std::ostream& out, Suit s);
std::ostream& operator<<(std::ostream& out, Rank r);
std::ostream& operator<<(std::ostream& out, Card c);

#endif
