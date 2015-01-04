#ifndef HUMAN_H
#define HUMAN_H

// Internal
#include "Card.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Constants.hpp"

// External
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

extern std::ofstream& output;

class Human : public Croupier {
	public:
		Human( );
		Human( double money, std::map<std::string, double>& preFlop, std::string name );
		~Human( );
		
		double options( bool limitRaise, double highestBet, bool isHolecard, bool isFirst, int numberOfPlayers, int inRound );

		bool getFold( );
		bool getBust( );
		bool getAllIn( );
		bool getRaised( );
		
		void clear( );
		void clearRaised( );
		void clearBet( );
		void setBusted( );

		void setMoney( double amount );
		double getMoney( );

		void setHand( );
		Hand getHand( );

		void setCard( Card card, int position );
		void clearCards( );

		std::string getName( );
		double getBet( );

		void setSmallBlind( double amount );
		void setBigBlind( double amount );

		int setPosition( int position );
		int getPosition( );
		
		void setStrength( );
		int getStrength( );

		void sortHoleCards( );
		void setPreflopOdds( std::map<std::string, double>& odds );

		friend std::ostream& operator << ( std::ostream& output, Human &outputHuman );

		void outSmallBlind( );

	private:	
		double actionSmallBlind( bool isHolecard, bool isFirst );
		double actionBigBlind( bool isHolecard, bool isFirst );
		int actionDecision( int decision );

		
		double setCall( );
		double setFold( );
		double setCheck( );
		double setRaise( double amount );
		double setAllIn( );
		void setPostFlop( bool raiseLimit );

		int postFlopHelp( );		
		void combineCards( );	
		void preFlopHelp( bool isLimitBet );
		void strengthHelp( bool isLimitBet, double& odds );
		void foldAction( );
		void betAction( bool isLimitBet );

		std::vector<Card> mAllCards;
		std::vector<Card> mTableCards;
		std::vector<Card> mHoleCards;

		Deck mTurnCards;
		Deck mRiverCards;

		Hand mHand;
		std::map<std::string, double> mPreFlop;

		double mMoney;
		double mBet;
		double mDealerBet;
		double mSmallBlind;
		double mBigBlind;

		std::string mName;

		bool mFold;
		bool mBust;
		bool mAllIn;
		bool mRaised;
		int mPosition;
		int mStrength;
		int mDecision;
		int mRaiseAmount;
		int mPlayersLeft;
		double mOdds;	
};
#endif