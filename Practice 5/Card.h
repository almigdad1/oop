//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//

#ifndef ___CARD_H
#define ___CARD_H
#include <assert.h>
#include <string>
using std::string;

// LSB
enum Suit
 {
     clubs,
     diamonds,
     hearts,
     spades
 };

// RSB
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

 enum Color
{
    Black,
    Red
};

enum Kind
{
    StandardKind,
    JokerKind
};

class Card {
public:
    Card (Rank r = two, Suit s = clubs) : bits((unsigned)s << 4 | (unsigned)r) { }
    Card(Color c) : bits((unsigned)(1) << 6 | (unsigned)c << 7) { }
    Rank getValue() const { return(Rank) (0b00001111 & bits); }
    Suit getSuit() const { return(Suit) ((0b11110000 & bits) >> 4); }
    friend bool operator==(Card a, Card b) {  return a.getValue() == b.getValue(); }
    friend bool operator!=(Card a, Card b) { return a.getValue() != b.getValue(); }
    friend bool operator<(Card a, Card b) { return a.getValue() < b.getValue(); }
    friend bool operator>(Card a, Card b) { return b.getValue() < a.getValue(); }
    friend bool operator<=(Card a, Card b) { return !(b.getValue() < a.getValue()); }
    friend bool operator>=(Card a, Card b) { return !(a.getValue() < b.getValue()); }

    Color getColor() const
    {
        if(((bits >> 6) & 0b1) == 1)
            return (Color) ((bits >> 7) & 0b1);
        else
            return (Color) - 1;
    }

private:
		Rank rank;
		Suit suit;
		unsigned char bits;
};




class PlayingCard
{
    Kind kind;

public:
   PlayingCard();
    PlayingCard(Kind k) : kind(k) { }
    Kind getKind() const;
};

class Joker : PlayingCard
{
    Color color;

public:
    Joker(Color c) : color(c) { }
    Color getColor() const;
};

class Standard : PlayingCard
{
    Rank rank;
    Suit suit;

public:
    Standard(Rank r, Suit s) : rank(r), suit(s) { }
    Rank getValue() const;
    Suit getSuit() const;
};

//Overloading ostream operators
std::ostream& operator<<(std::ostream& out, Suit s);
std::ostream& operator<<(std::ostream& out, Rank r);
std::ostream& operator<<(std::ostream& out, Card c);
std::ostream& operator<<(std::ostream& out, Standard c);
std::ostream& operator<<(std::ostream& out, Joker c);
std::ostream& operator<<(std::ostream& out, Color c);
std::ostream& operator<<(std::ostream& out, Kind k);
std::ostream& operator<<(std::ostream& out, PlayingCard c);

#endif
