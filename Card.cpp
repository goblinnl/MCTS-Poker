#include "stdafx.h"
#include "Card.hpp"


/**
 * Default constructor.
 */
Card::Card()
{

}

/**
 * Constructor.
 * @param number Number of card.
 * @param card   The card.
 */
Card::Card( char number, char card )
{
	setValue( number, card );
}

/**
 * Destructor.
 */
Card::~Card()
{

}

/**
 * Gets the card.
 * @return The card (Suit and number).
 */
std::string Card::getCard() const
{
	std::string card;

	card.append( 1, mNumber );
	card.append( 1, mSuit );

	return card;
}

/**
 * Sets a card value.
 * @param number Number of card.
 * @param suit   The suit.
 */
void Card::setValue(char number, char suit)
{
	setNumber( number );
	setSuit( suit );
}

/**
 * Sets a number.
 * @param number Number of card.
 */
void Card::setNumber( char number )
{
	mNumber = number;
}

/**
 * Sets a suit.
 * @param suit The suit.
 */
void Card::setSuit( char suit )
{
	mSuit = suit;
}

/**
 * Gets the suit.
 * @return The suit.
 */
char Card::getSuit( ) const
{
	return mSuit;
}
