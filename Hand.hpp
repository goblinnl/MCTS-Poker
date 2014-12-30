#ifndef HAND_H
#define HAND_H

// External
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

// Internal
#include "stdafx.h"
#include "Type.hpp"
#include "Card.hpp"
#include "Croupier.hpp"


class Hand : public Croupier {
	public:
		Hand();

		/* Sort cards by rank (7 cards) */
		void setHand(std::vector<Card>& card, std::vector<Card>& hole);

		// Returns the type of the hand
		Type getType( );
	
		// Clear hand, handType and vectors
		void clear( );

		std::vector<Card> mCards;

		friend bool operator > ( Hand& hand1, Hand& hand2 );
		friend bool operator == ( Hand& hand1, Hand& hand2 );
		friend std::ostream& operator << ( std::ostream& output, Hand& outputHand );

	private:
		// Determine handType
		Type typeOf( const std::vector<Card>& hand );

		// Find possible hand. 
		void addCombo( int card1, int card2, int card3, int card4, int card5 );

		// Determine Hand
		bool isStraight( const std::vector<Card>& card, Type& type );
		bool isFlush( const std::vector<Card>& card, Type& type );
		bool isFourKind( const std::vector<Card>& card, Type& type );
		bool isThreeKind( const std::vector<Card>& card, Type& type );
		bool isFullHouse( const std::vector<Card>& card, Type& type );
		bool isTwoPair( const std::vector<Card>& card, Type& type );
		bool isPair( const std::vector<Card>& card, Type& type );

		Type mType;
		std::vector<std::vector<Card> > mPossibleHands; // Vector of possible hands
		bool mValid;
};

#endif
