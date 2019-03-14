//
// Ala'alddin Al-Migdad
// ID#2891368
// aa186@zips
//
#ifndef __WAR_H_
#define __WAR_H_

#include "Hand.h"
#include <iostream>
#include <string>

using namespace std;

class War
{
public:
	static void Start();
	// Starts the game
private:
	War();
	//Default constructor
	static void battle();
    // compares both players cards and determines which player gets the cards.
	static int war();
    // case when both players have the same rank and makes each player place three cards and determines winner of that battle
	static void winner();
    // checks if one of the players hand is empty or the max number of rounds have been played and declares the result
	static void checkSkip();
	// check if user wants to skip to the end

	static Hand P1, P2;
	static bool Skip;
	static int rounds;
	static const int roundsMax;
};

#endif
