//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//
#include <iostream>
#include "Card.h"

int main()
{
    Standard stdCard(king, hearts);
    std::cout << "The Rank of an example card is: ";
    std::cout << stdCard.getValue() << std::endl;
    std::cout << "The Suit of the example card is: ";
    std::cout << stdCard.getSuit() << std::endl;
    std::cout << "The Card is: ";
    std::cout << stdCard << std::endl << std::endl;
    //Return the color of joker cards
    std::cout << "Joker cards Testing: ";
    Joker jkCardB(Black), jkCardR(Red);
    std::cout << jkCardB.getColor() << " and " << jkCardR.getColor() << std::endl << std::endl;
    //Query if the card is a standard card or a joker card
    std::cout << "Test both kinds of cards and check if the correct kind is given: ";
    PlayingCard stdExample(StandardKind), jkExample(JokerKind);
    std::cout << stdExample.getKind() << "   " << jkExample.getKind() << std::endl;

	return 0;
}
