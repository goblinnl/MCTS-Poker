// Internal
#include "stdafx.h"
#include "Hand.hpp"

/**
 * Default constructor.
 */
Hand::Hand( ) : mValid( false )
{

}

/**
 * Sets a poker hand.
 *
 * @param [in,out] table The table (Croupier).
 * @param [in,out] hole  The hole (Type of card).
 */
void Hand::setHand( std::vector<Card>& table, std::vector<Card>& hole )
{
	Card card( 'A', 'h' );

	std::vector<Card>::iterator i = table.begin( );
	std::vector<Card>::iterator j = table.end( );

	mCards.assign( i, j );
	mCards.push_back( hole[ 0 ] );
	mCards.push_back( hole[ 1 ] );

	// Sort cards high to low ( bubble sorting )
	for( unsigned int  i = 0; i < mCards.size( ); i++ ) {
		for( unsigned int j = 0; j < mCards.size( ) - 1; j++ )
		{
			if( mCards[ j ].getFaceNumber( ) < mCards[ j + 1 ].getFaceNumber( ) )
			{
				card = mCards[ j ];
				mCards[ j ] = mCards[ j + 1 ];
				mCards[ j + 1 ] = card;
			}
		}
	}

	// Add Card Combinations
	addCombo( 0, 1, 2, 3, 4 );
	addCombo( 1, 2, 3, 4, 5 );
	addCombo( 0, 2, 3, 4, 5 );
	addCombo( 0, 1, 3, 4, 5 );
	addCombo( 0, 1, 2, 4, 5 );
	addCombo( 0, 1, 2, 3, 5 );
	addCombo( 2, 3, 4, 5, 6 );
	addCombo( 1, 3, 4, 5, 6 );
	addCombo( 1, 2, 4, 5, 6 );
	addCombo( 1, 2, 3, 5, 6 );
	addCombo( 1, 2, 3, 4, 6 );
	addCombo( 0, 3, 4, 5, 6 );
	addCombo( 0, 2, 4, 5, 6 );
	addCombo( 0, 2, 3, 5, 6 );
	addCombo( 0, 2, 3, 4, 6 );
	addCombo( 0, 1, 4, 5, 6 );
	addCombo( 0, 1, 3, 5, 6 );
	addCombo( 0, 1, 3, 4, 6 );
	addCombo( 0, 1, 2, 5, 6 );
	addCombo( 0, 1, 2, 4, 6 );
	addCombo( 0, 1, 2, 3, 6 );
}

/**
 * Gets the type of the best hand.
 * @return The best hand type.
 */
Type Hand::getType( )
{
	Type bestHand;
	Type currentHand;

	for( unsigned int i=0; i < mPossibleHands.size( ); ++i )
	{
		currentHand = typeOf( mPossibleHands[ i ] );

		if( currentHand > bestHand )
			bestHand = currentHand;
	}

	mValid = true;
	mType = bestHand;
	
	return bestHand;
}

/**
 * What kind of hand a player has: Pair, Two Pairs, Flush etc.
 *
 * @param hand The current holding hand.
 *
 * @return A Type.
 */
Type Hand::typeOf( const std::vector<Card>& hand )
{
	Type handType;

	bool setFlush = isFlush( hand, handType );
	bool setStraight = isStraight( hand, handType );

	if( setFlush == true && setStraight == true )
	{
		if( hand[ 0 ].getNumber( ) == 'A' )
		{
			handType.setType( RFLUSH );
		}
		else {
			handType.setType( SFLUSH, hand[ 0 ].getFaceNumber( ) );
		}
	}

	else if( isFourKind( hand, handType ) ) { }
	else if( isFullHouse( hand, handType ) ) { }
	else if( setStraight == true ) { }
	else if( isThreeKind( hand, handType ) ) { }
	else if( isTwoPair( hand, handType ) ) { }
	else if( isPair( hand, handType ) ) { }
	else if( setFlush == true )
	{
		handType.setType( FLUSH, hand[ 0 ].getFaceNumber( ), 
								hand[ 1 ].getFaceNumber( ),
								hand[ 2 ].getFaceNumber( ),
								hand[ 3 ].getFaceNumber( ), 
								hand[ 4 ].getFaceNumber( ) );
	}
	else {
		handType.setType( JUNK, hand[ 0 ].getFaceNumber( ),
								hand[ 1 ].getFaceNumber( ),
								hand[ 2 ].getFaceNumber( ),
								hand[ 3 ].getFaceNumber( ),
								hand[ 4 ].getFaceNumber( ) );
	}

	return handType;
}

/**
 * Adds a combonation of cards.
 *
 * @param card1 The first card.
 * @param card2 The second card.
 * @param card3 The third card.
 * @param card4 The fourth card.
 * @param card5 The fifth card.
 */
void Hand::addCombo( int card1, int card2, int card3, int card4, int card5 )
{
	std::vector<Card> card(5);

	card[ 0 ] = mCards[ card1 ];
	card[ 1 ] = mCards[ card2 ];
	card[ 2 ] = mCards[ card3 ];
	card[ 3 ] = mCards[ card4 ];
	card[ 4 ] = mCards[ card5 ];

	// Vectors of Vectors
	mPossibleHands.push_back( card );
}

/**
 * Clears hand to its blank/initial state.
 */
void Hand::clear( )
{
	mCards.clear( );
	mType.clear( );
	mPossibleHands.clear( );
	mValid = false;
}

/*
* THE POKER RULES 
*/

/**
 * Query if 'hand' is straight.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if straight, false if not.
 */
bool Hand::isStraight( const std::vector<Card>& hand, Type& type )
{

	bool isStraight = false;

	// Set Card Faces to variable
	int faceNumber0 = hand[ 0 ].getFaceNumber( ) + 0;
	int faceNumber1 = hand[ 1 ].getFaceNumber( ) + 1;
	int faceNumber2 = hand[ 2 ].getFaceNumber( ) + 2;
	int faceNumber3 = hand[ 3 ].getFaceNumber( ) + 3;
	int faceNumber4 = hand[ 4 ].getFaceNumber( ) + 4;

	int kicker = hand[ 0 ].getFaceNumber();

	// Ace-low straight
	if( faceNumber0 == 14 )
	{
		faceNumber0 = 1;
		kicker = hand[ 1 ].getFaceNumber( );
	}

	// If Straight
	if( ( faceNumber0 == faceNumber1 ) && ( faceNumber1 == faceNumber2 )
		&& ( faceNumber2 == faceNumber3 ) && ( faceNumber3 == faceNumber4 ) )
	{
		type.setType( STRAIGHT, kicker );
		isStraight = true;
	}

	return isStraight;
}

/**
 * Query if 'hand' is flush.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if flush, false if not.
 */
bool Hand::isFlush( const std::vector<Card>& hand, Type& type )
{
	char suit0 = hand[ 0 ].getSuit( );
	char suit1 = hand[ 1 ].getSuit( );
	char suit2 = hand[ 2 ].getSuit( );
	char suit3 = hand[ 3 ].getSuit( );
	char suit4 = hand[ 4 ].getSuit( );


	if( ( suit0 == suit1 ) && ( suit1 == suit2 ) && 
		( suit2 == suit3 ) && ( suit3 == suit4 ) )
	{
		type.setType( FLUSH );
		return true;
	}

	return false;
}

/**
 * Query if 'hand' is four of a kind.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if four of a kind, false if not.
 */
bool Hand::isFourKind( const std::vector<Card>& hand, Type& type )
{
	bool isFourKind = false;

	char card0 = hand[ 0 ].getNumber( );
	char card1 = hand[ 1 ].getNumber( );
	char card2 = hand[ 2 ].getNumber( );
	char card3 = hand[ 3 ].getNumber( );
	char card4 = hand[ 4 ].getNumber( );
	
	if( ( card0 == card1 ) && ( card1 == card2 ) && ( card2 == card3 ) )
	{
		type.setType( FOURKIND, hand[ 0 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ) );
		isFourKind = true;
	}	
	else if( ( card1 == card2 ) && ( card2 == card3 ) && ( card3 == card4 ) ) {
		type.setType( FOURKIND, hand[ 1 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ) );
		isFourKind = true;
	}
	
	return isFourKind;
}

/**
 * Query if 'hand' is three of a kind.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if three of a kind, false if not.
 */
bool Hand::isThreeKind( const std::vector<Card>& hand, Type& type )
{
	bool isThreeKind = false;

	char card0 = hand[ 0 ].getNumber( );
	char card1 = hand[ 1 ].getNumber( );
	char card2 = hand[ 2 ].getNumber( );
	char card3 = hand[ 3 ].getNumber( );
	char card4 = hand[ 4 ].getNumber( );

	if( ( card0 == card1 ) && ( card1 == card2 ) )
	{
		type.setType( THREEKIND, hand[ 0 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ) );
		isThreeKind = true;
	}

	if( ( card1 == card2 ) && ( card2 == card3 ) )
	{
		type.setType( THREEKIND, hand[ 1 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ) );
		isThreeKind = true;
	}
	else if( ( card2 == card3 ) && ( card3 == card4 ) )	{
		type.setType( THREEKIND, hand[ 2 ].getFaceNumber( ), hand[ 1 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ) );
		isThreeKind = true;
	}

	return isThreeKind;
}

/**
 * Query if 'hand' is full house.
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if full house, false if not.
 */
bool Hand::isFullHouse( const std::vector<Card>& hand, Type& type )
{
	bool isThreeKind = false;

	char card0 = hand[ 0 ].getNumber( );
	char card1 = hand[ 1 ].getNumber( );
	char card2 = hand[ 2 ].getNumber( );
	char card3 = hand[ 3 ].getNumber( );
	char card4 = hand[ 4 ].getNumber( );

	if( ( card0 == card1 ) && ( card1 == card2 ) && ( card2 == card3 ) && ( card3 == card4 ) )
	{
		type.setType( FULL, hand[ 0 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ) );
		isThreeKind = true;
	}
	else if( ( card0 == card1 ) && ( card2 == card3 ) && ( card3 == card4 ) ) {
		type.setType( FULL, hand[ 2 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ) );
		isThreeKind = true;
	}

	return isThreeKind;
}

/**
 * Query if 'hand' is two pair.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if two pair, false if not.
 */
bool Hand::isTwoPair( const std::vector<Card>& hand, Type& type )
{
	bool isTwoPair = false;

	char card0 = hand[ 0 ].getNumber( );
	char card1 = hand[ 1 ].getNumber( );
	char card2 = hand[ 2 ].getNumber( );
	char card3 = hand[ 3 ].getNumber( );
	char card4 = hand[ 4 ].getNumber( );

	if( ( card0 == card1 ) && ( card2 == card3 ) )
	{
		type.setType( TWOPAIR, hand[ 0 ].getFaceNumber( ), hand[ 2 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ) );
		isTwoPair = true;
	}
	else if( ( card0 == card1 ) && ( card3 == card4 ) )	{
		type.setType( TWOPAIR, hand[ 0 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ), hand[ 2 ].getFaceNumber( ) );
		isTwoPair = true;
	}
	else if( ( card1 == card2 ) && ( card3 == card4 ) )	{
		type.setType( TWOPAIR, hand[ 1 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ) );
		isTwoPair = true;
	}

	return isTwoPair;
}

/**
 * Query if 'hand' is pair.
 *
 * @param hand		    The hand.
 * @param [in,out] type The cardtype.
 *
 * @return true if pair, false if not.
 */
bool Hand::isPair( const std::vector<Card>& hand, Type& type )
{
	bool isPair = false;

	char card0 = hand[ 0 ].getNumber( );
	char card1 = hand[ 1 ].getNumber( );
	char card2 = hand[ 2 ].getNumber( );
	char card3 = hand[ 3 ].getNumber( );
	char card4 = hand[ 4 ].getNumber( );

	if( card0 == card1 )
	{
		type.setType( PAIR, hand[ 0 ].getFaceNumber( ), hand[ 2 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ) );
		isPair = true;
	}
	else if( card1 == card2 ) {
		type.setType( PAIR, hand[ 1 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ), hand[ 3 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ) );
		isPair = true;
	}
	else if( card2 == card3 ) {
		type.setType( PAIR, hand[ 2 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ), hand[ 1 ].getFaceNumber( ), hand[ 4 ].getFaceNumber( ) );
		isPair = true;
	}
	else if( card3 == card4 ) {
		type.setType( PAIR, hand[ 3 ].getFaceNumber( ), hand[ 0 ].getFaceNumber( ), hand[ 1 ].getFaceNumber( ), hand[ 2 ].getFaceNumber( ) );
		isPair = true;
	}

	return isPair;
}

/**
 * Stream insertion operator.
 * 
 * @param [in,out] output	  The output.
 * @param [in,out] outputHand The output hand.
 *
 * @return The shifted result.
 */
std::ostream& operator << ( std::ostream& output, Hand& outputHand )
{
	std::vector<Card>::iterator print;
	
	for( print = outputHand.mCards.begin( ); print != outputHand.mCards.end( ); ++print ) {
		output << *print << " ";
	}
	
	Type& outputType = outputHand.getType( );
	std::cout << "   ";
	
	switch( outputType.getType( ) )
	{
		case RFLUSH:
			output << "Royal Flush";
			break;
		case SFLUSH:
			output << "Straight Flush";
			break;
		case FOURKIND:
			output << "Rour Of A Kind";
			break;
		case FULL:
			output << "Full House";
			break;
		case FLUSH:
			output << "Flush";
			break;
		case STRAIGHT:
			output << "Straight";
			break;
		case THREEKIND:
			output << "Three Of A Kind";
			break;
		case TWOPAIR:
			output << "Two Pair";
			break;
		case PAIR:
			output << "Pair";
			break;
		case JUNK:
			output << "Junk";
			break;
		default:
			output << "Blank";
			break;
	}

	return output;
}

/**
 * Greater-than comparison operator.
 * 
 * @param [in,out] hand1 The first instance to compare.
 * @param [in,out] hand2 The second instance to compare.
 *
 * @return true if the first parameter is greater than to the second.
 */
bool operator > ( Hand& hand1, Hand& hand2 )
{
	return hand1.getType( ) > hand2.getType( );
}

/**
 * Equality operator.
 * 
 * @param [in,out] hand1 The first instance to compare.
 * @param [in,out] hand2 The second instance to compare.
 *
 * @return true if the parameters are considered equivalent.
 */
bool operator == ( Hand& hand1, Hand& hand2 )
{
	return hand1.getType( ) == hand2.getType( );
}

