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
 * @return The card suit.
 */
char Card::getSuit( ) const
{
	return mSuit;
}

/**
 * Gets the number.
 * @return The card number. 'A'for ace or '1' for one.
 */
char Card::getNumber( ) const
{
	return mNumber;
}

/**
 * Gets face number.
 * @return The face number. (14 for ace, 0 for a one)
 */
int Card::getFaceNumber( ) const
{
	int cardNumber;

	if( mNumber != 'T' && mNumber != 'J' &&	mNumber != 'Q' && mNumber != 'K' &&	mNumber != 'A' )	
		return mNumber - 1;
	
	switch( mNumber )
	{
	case 'T':
		{
			cardNumber = 10;
			break;
		}
	case 'J':
		{
			cardNumber = 11;
			break;
		}
	case 'Q':
		{
			cardNumber = 12;
			break;
		}
	case 'K':
		{
			cardNumber = 13;
			break;
		}
	case 'A':
		{
			cardNumber = 14;
			break;
		}
	}

	return mNumber;
}

/**
 * Equality operator.
 * @param [in,out] card1 The first instance to compare.
 * @param card2			 The second instance to compare.
 *
 * @return true if the parameters are considered equivalent.
 */
bool operator==( Card& card1, Card card2 )
{
	return ( card1.getCard( ) == card2.getCard( ) );
}

/**
 * Stream insertion operator.
 * @param [in,out] output	  The output.
 * @param [in,out] outputCard The output card.
 *
 * @return The shifted result.
 */
std::ostream& operator<< ( std::ostream& output, Card& outputCard )
{
	return output << outputCard.getCard( );
	//return output
}

/**
 * Greater-than comparison operator.
 * @param [in,out] card1 The first instance to compare.
 * @param [in,out] card2 The second instance to compare.
 *
 * @return true if the first parameter is greater than to the second.
 */
bool operator > ( Card& card1, Card& card2 )
{
	if( card1.getFaceNumber( ) > card2.getFaceNumber( ) )
		return true;

	return false;
}

/**
 * Less-than comparison operator.
 * @param [in,out] card1 The first instance to compare.
 * @param [in,out] card2 The second instance to compare.
 *
 * @return true if the first parameter is less than the second.
 */
bool operator < ( Card& card1, Card& card2  )
{
	if( card1.getFaceNumber( ) < card2.getFaceNumber( ) )
		return false;

	return true;
}