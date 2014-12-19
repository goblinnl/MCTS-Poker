#ifndef CARD_H
#define CARD_H

#include <ostream>
#include <string>

class Card
{
	public:
		Card( );
		Card( char number, char suit );
		~Card( );
		std::string getCard( ) const;
		void setValue( char number, char suit );
		void setNumber( char number );
		void setSuit( char suit );
		char getSuit( ) const;
		char getNumber( ) const;
		int getFaceNumber( ) const;

		// Overload equals comparison if two cards are equal
		friend bool operator== ( Card& card1, Card& card2 );
		friend std::ostream& operator<< ( std::ostream& output, Card &outputCard );
		friend bool operator> ( Card& card1, Card& card2 );
		friend bool operator< ( Card& card1, Card& card2 );			

	private:
		char mSuit;
		char mNumber;

};
#endif
