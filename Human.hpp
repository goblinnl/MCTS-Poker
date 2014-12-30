#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>



class Human {
	public:
		Human( );
		Human( int human );
		~Human( );
		
		void addMoney( int amount );
		void tablePoint( std::map<std::string, double> * mapPoint );

		
		double getAggressiveness( );
		double getTightness( );
		double getCardWeight( );
		double getMoney( );
		bool getBusted( );
		bool getFold( );
		std::map<std::string, double>* getWeight( );


		void setBusted( );
		void setUnfold( );
		void setWeights( );
		void setFlop( );
		void setFoldBeforeFlop( );


		void fold( );
		void raiseBet( double amount );
		void checkCall( double amount );
		void isWon( double amount );

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