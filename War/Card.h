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
	Card (Rank rank=two, Suit suit = clubs):
		suit (suit), rank(rank) {}
	Suit getSuit()
	 {
         return suit;
     }
	Rank getValue()
	 {
	     return rank;
     }
	static string suitName(Suit s);
	static string rankName(Rank r);
	string name() { return rankName(rank) + " of " + suitName(suit);}
private:
		Suit suit;
		Rank rank;
};


#endif
