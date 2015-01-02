#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>


class Human {
	public:
		Human( );
		Human( int chipCount );
		~Human( );
		
		
		void tablePoint( std::map<std::string, double> * mapPoint );

		
		double getStrength( );
		double getTightness( );
		double getCardWeight( );
		double getMoney( );
		bool getBusted( );
		bool getFold( );
		std::map<std::string, double>* getWeight( );

		void setMoney( int amount );
		void setBusted( );
		void setUnfold( );
		void setFlop( );
		void setFoldBeforeFlop( );
		void setFold( );

		
		void raiseBet( double amount );
		void checkCall( double amount );
		void isWinning( double amount );

	private:
		std::map<std::string, double>* mWeightTable;
		double mChipAmount;
		int mHandsPlayed;
		int mHandsWon;
		int mFlopSeen;
		int mRaises;
		bool mOut;
		bool mBust;		
};
#endif