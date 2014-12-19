#include "stdafx.h"
#include "Deck.hpp"



/**
 * Default constructor.
 */
Deck::Deck( )
{

}

/**
 * Destructor.
 */
Deck::~Deck( )
{

}

/**
 * Create a deck of cards.
 */
void Deck::setDeck( )
{
	/** Create spades deck. (c1 / c13) */
	Card c1( 'A', 'S' );	
	Card c2( 'K', 'S' );
	Card c3( 'Q', 'S' );
	Card c4( 'J', 'S' );
	Card c5( 'T', 'S' );
	Card c6( '9', 'S' );
	Card c7( '8', 'S' );
	Card c8( '7', 'S' );
	Card c9( '6', 'S' );
	Card c10( '5', 'S' );
	Card c11( '4', 'S' );
	Card c12( '3', 'S' );
	Card c13( '2', 'S' );

	/** Push spades to deck. */
	deck.push_back( c1 );
	deck.push_back( c2 );
	deck.push_back( c3 );
	deck.push_back( c4 );
	deck.push_back( c5 );
	deck.push_back( c6 );
	deck.push_back( c7 );
	deck.push_back( c8 );
	deck.push_back( c9 );
	deck.push_back( c10 );
	deck.push_back( c11 );
	deck.push_back( c12 );
	deck.push_back( c13 );
		
	/** Create hearts deck. (c14 / c26) */
	Card c14( 'A', 'H' );
	Card c15( 'K', 'H' );
	Card c16( 'Q', 'H' );
	Card c17( 'J', 'H' );
	Card c18( 'T', 'H' );
	Card c19( '9', 'H' );
	Card c20( '8', 'H' );
	Card c21( '7', 'H' );
	Card c22( '6', 'H' );
	Card c23( '5', 'H' );
	Card c24( '4', 'H' );
	Card c25( '3', 'H' );
	Card c26( '2', 'H' );

	/** Push hearts to deck. */
	deck.push_back( c14 );
	deck.push_back( c15 );
	deck.push_back( c16 );
	deck.push_back( c17 );
	deck.push_back( c18 );
	deck.push_back( c19 );
	deck.push_back( c20 );
	deck.push_back( c21 );
	deck.push_back( c22 );
	deck.push_back( c23 );
	deck.push_back( c24 );
	deck.push_back( c25 );
	deck.push_back( c26 );
		
	/** Create clubs deck. (c27 / c39) */
	Card c27( 'A', 'C' );
	Card c28( 'K', 'C' );     
	Card c29( 'Q', 'C' );
	Card c30( 'J', 'C' );
	Card c31( 'T', 'C' );
	Card c32( '9', 'C' );
	Card c33( '8', 'C' );
	Card c34( '7', 'C' );
	Card c35( '6', 'C' );
	Card c36( '5', 'C' );
	Card c37( '4', 'C' );
	Card c38( '3', 'C' );
	Card c39( '2', 'C' );

	/** Push clubs to deck. */
	deck.push_back( c27 );
	deck.push_back( c28 );
	deck.push_back( c29 );
	deck.push_back( c30 );
	deck.push_back( c31 );
	deck.push_back( c32 );
	deck.push_back( c33 );
	deck.push_back( c34 );
	deck.push_back( c35 );
	deck.push_back( c36 );
	deck.push_back( c37 );
	deck.push_back( c38 );
	deck.push_back( c39 );

	/** Create diamond deck. (c40 / c52) */
	Card c40( 'A', 'D' );
	Card c41( 'K', 'D' );
	Card c42( 'Q', 'D' );
	Card c43( 'J', 'D' );
	Card c44( 'T', 'D' );
	Card c45( '9', 'D' );
	Card c46( '8', 'D' );
	Card c47( '7', 'D' );
	Card c48( '6', 'D' );
	Card c49( '5', 'D' );
	Card c50( '4', 'D' );
	Card c51( '3', 'D' );
	Card c52( '2', 'D' );

	deck.push_back( c40 );
	deck.push_back( c41 );
	deck.push_back( c42 );
	deck.push_back( c43 );
	deck.push_back( c44 );
	deck.push_back( c45 );
	deck.push_back( c46 );
	deck.push_back( c47 );
	deck.push_back( c48 );
	deck.push_back( c49 );
	deck.push_back( c50 );
	deck.push_back( c51 );
	deck.push_back( c52 );
}

/**
 * Shuffle deck with random shuffle.
 */
void Deck::shuffleDeck( )
{
	clear();
	setDeck();
	std::random_shuffle( deck.begin( ), deck.end( ) );
}