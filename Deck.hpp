#ifndef DECK_H
#define DECK_H

// Internal
#include "Card.hpp"

// External
#include <iostream>
#include <vector>
#include <algorithm>

class Deck : public Card {

	Deck( );
	~Deck( );

	void setDeck( );
	void clear( );
	void shuffleDeck( );

	//void removeCards( std::vector<Card> toRemoved );

	// Vector of cards
	std::vector<Card> deck;

	


};

#endif