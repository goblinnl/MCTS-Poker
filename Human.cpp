#include "Human.hpp"

Human::Human( )
{

}

Human::Human( double money, std::map<std::string, double>& preFlop, std::string name ) : mFold( false ),
mBust( false ), mAllIn( false ), mRaised( false ), mPosition( 0 ), mStrength( 0 ), mDecision( 0 ), mRaiseAmount( 0 ),
mPlayersLeft( 0 ), mOdds( 0 )
{
	mMoney = money;
	mPreFlop = preFlop;
	mName = name;
	setStrength( );
}

Human::~Human( )
{

}

void Human::clear( )
{
	mBet = 0;
	mBust = false;
	mFold = false;
	mAllIn = false;
	clearCards( );
}


void Human::setMoney( double amount )
{
	mMoney += amount;
}

double Human::getMoney( )
{
	return mMoney;
}

void Human::setHand( )
{
	mHand.setHand( mTableCards, mHoleCards );
}

void Human::setCard( Card card, int position )
{
	if( position == HOLECARDS )
		mHoleCards.push_back( card );

	if( position == FLOP || position == TURN || position == RIVER )
		mHoleCards.push_back( card );
}

void Human::clearCards( )
{
	mHand.clear( );
	mTableCards.clear( );
	mHoleCards.clear( );
	mAllCards.clear( );
}

void Human::setPreflopOdds( std::map<std::string, double>& odds )
{
	mPreFlop = odds;
}

double Human::options( bool limitRaise, double highestBet, bool isHolecard, bool isFirst, int numberOfPlayers, int inRound )
{
	mTurnCards.shuffleDeck( );
	mRiverCards.shuffleDeck( );

	mDealerBet = highestBet;
	mPlayersLeft = numberOfPlayers;

	if( inRound == 1 )
		return 0.0;

	std::cout << "Current Highest Bet: " << highestBet << "\n";
	output << "Current Highest Bet: " << highestBet << "\n";

	// Small Blind
	double smallBlind = this->actionSmallBlind( isHolecard, isFirst );
	if( smallBlind != -1 )
		return smallBlind;

	// Big Blind
	double bigBlind = this->actionBigBlind( isHolecard, isFirst );
	if( bigBlind != -1 )
		return bigBlind;

	// Holecard
	 isHolecard ? preFlopHelp( limitRaise ) : setPostFlop( limitRaise );

	// Other Options
	return actionDecision( mDecision );
}

double Human::actionSmallBlind( bool isHolecard, bool isFirst )
{

	if( ( mPosition == SMALLBLIND ) && ( isFirst ) && ( isHolecard ) )
	{
		if( mSmallBlind > mMoney )
		{
			mAllIn = true;

			double oldMoney = mMoney;
			mBet += mMoney;

			// Reset Money
			mMoney = 0.0;

			// Output
			std::cout << mName << " is the Small Blind but not enough Money, so All In with the Amount  " << oldMoney << "\n";
			output << mName << " is the Small Blind but not enough Money, so All In with the Amount:  " << oldMoney << "\n";

			return oldMoney;
		}
		else
		{
			mMoney -= mSmallBlind;
			mBet += mSmallBlind;

			// Output
			std::cout << mName << " is the small blind and forced to bet the Amount: " << mSmallBlind << "\n";
			output << mName << " is the small blind and forced to bet the Amount; " << mSmallBlind << "\n";

			return mSmallBlind;
		}
	}

	return -1;
}

double Human::actionBigBlind( bool isHolecard, bool isFirst )
{
	if( ( mPosition == BIGBLIND ) && ( isFirst ) && ( isHolecard ) )
	{
		mAllIn = true;

		double oldMoney = mMoney;
		mBet += mMoney;

		// Reset Money
		mMoney = 0.0;

		// Output
		std::cout << mName << "is the big blind but not enought Money, so all in with the Amount: " << oldMoney << "\n";
		output << mName << "is the big blind but not enought Money, so all in with the Amount: " << oldMoney << "\n";

		return oldMoney;
	}
	else {
		mMoney -= mBigBlind;
		mBet += mBigBlind;

		std::cout << mName << " is the big blind and is fored to bet the Amount: " << mBigBlind << "\n";
		output << mName << " is the big blind and is fored to bet the Amount: " << mBigBlind << "\n";

		return mBigBlind;
	}

	return -1;
}

int Human::actionDecision( int decision )
{
	switch( decision )
	{
	case CHECK:
		return setCheck( );
		break;
	case CALL:
		return setCall( );
		break;
	case RAISE:
		return setRaise( mRaiseAmount );
		break;
	case FOLD:
		return setFold( );
		break;
	default:
		std::cout << " No decision made" << "\n";
		output << " No decision made" << "\n";
		return -1;
		break;
	}

	return -1;
}

void Human::combineCards( )
{
	mAllCards.clear( );
	mAllCards = mTableCards;
	mAllCards.push_back( mHoleCards[ 0 ] );
	mAllCards.push_back( mHoleCards[ 1 ] );
}

bool Human::getFold( )
{
	return mFold;
}

bool Human::getBust( )
{
	return mBust;
}

bool Human::getAllIn( )
{
	return mAllIn;
}

bool Human::getRaised( )
{
	return mRaised;
}

void Human::clearRaised( )
{
	mRaised = false;
}

void Human::clearBet( )
{
	mBet = 0.0;
}

void Human::setBusted( )
{
	mBust = true;
}

std::string Human::getName( )
{
	return mName;
}

double Human::getBet( )
{
	return mBet;
}

void Human::setSmallBlind( double amount )
{
	mSmallBlind = amount;
}

void Human::setBigBlind( double amount )
{
	mBigBlind = amount;
}

double Human::setCall( )
{
	double tAmount = 0.0;

	if( ( mDealerBet - mBet ) == 0 )
	{
		tAmount = setCheck( );
	} 
	else if( ( mDealerBet > mBet ) > mMoney ) {
		mAllIn = true;
		tAmount = mMoney;
		mMoney = 0.;

		std::cout << mName << " goes all in with Amount: " << tAmount << "\n";
		output << mName << " goes all in with Amount:  " << tAmount << "\n";
	}
	else {
		tAmount = ( mDealerBet - mBet );
		mMoney -= tAmount;
		mBet = mDealerBet;
		std::cout << mName << " called the bet Amount: " << tAmount << "\n";
		output << mName << " called the bet Amount: " << tAmount << "\n";
	}

	return tAmount;
}

double Human::setFold( )
{
	mFold = true;

	std::cout << mName << " folded " << " \n";
	output << mName << " folded " << " \n";
	
	return 0.0;
}

double Human::setCheck( )
{
	std::cout << mName << " checked " << "\n";
	output << mName << " checked " << "\n";
	return 0.0;
}

double Human::setRaise( double amount )
{
	double tAmount = 0.0;

	// Not Enough money to raise, all in 
	if( ( mDealerBet - mBet ) > mMoney )
	{
		tAmount = setCall( );
	} 
	// Not Enought to call & raise
	else if( ( mDealerBet - mBet + amount ) > mMoney ) {
		mAllIn = true;
		mBet += mMoney;
		tAmount = mMoney;
		mMoney = 0.0;
		std::cout << mName << "goes all in with Amount: " << tAmount << "\n";
		output << mName << "goes all in with Amount: " << tAmount << "\n";
	}
	else {
		tAmount = ( mDealerBet - mBet + amount );
		mMoney -= tAmount;

		double betOff = ( mDealerBet - mBet );
		std::cout << mName << "called the bet of " << betOff << " and raised Amount: " << amount << "\n";
		output << mName << "called the bet of " << betOff << " and raised Amount: " << amount << "\n";
		mBet = tAmount;
		mRaised = true;
	}

	return tAmount;
}

double Human::setAllIn( )
{
	mAllIn = true;
	double tAmount = mMoney;
	mMoney = 0.0;
	return tAmount;
}

int Human::getPosition( )
{
	return mPosition;
}

int Human::setPosition( int position )
{
	mPosition = position;
}

void Human::preFlopHelp( bool isLimitBet )
{
	std::string lookup = mHoleCards[ 0 ].getCard( ) + mHoleCards[ 1 ].getCard( );
	mOdds = mPreFlop.find( lookup )->second;

	// Help Strenght & calculate odds
	this->strengthHelp( mPlayersLeft, mOdds );
	
}

// TODO function needs some proper testing
void Human::strengthHelp( bool isLimitBet, double& odds )
{
	// Excel sheet for the odds 
	double oddsBeginner		[ 9 ] = { 41, 26.5, 19.4, 15.4, 12.7, 10.7, 9.7, 8.4, 7.6 };
	double oddsIntermediate [ 9 ] = { 49, 31, 23.3, 18.7, 16, 13.7, 12, 11, 9.9 };
	double oddsExpert		[ 9 ] = { 55, 37, 28.0, 22.5, 19, 16.5, 14.5, 13, 12 };

	// For Players
	for( unsigned int p = 2; p < 10; p++ )
	{
		// numplayer = 2
		if( p == mPlayersLeft )
		{
			// odds (-1) Because 9 players starting (minimum) 2 players
			int oddsIndex = p - 2;

			// Skill Levels (0) Beginner, (1) Intermediate, (2) Expert			
			if( getStrength( ) == BEGINNER )
			{
				if( odds >= oddsBeginner[ oddsIndex ] )
					betAction( isLimitBet );
				else
					foldAction( );
			}

			if( getStrength( ) == INTERMEDIATE )
			{
				if( odds >= oddsIntermediate[ oddsIndex ] )
					betAction( isLimitBet );
				else
					foldAction( );
			}

			if( getStrength( ) == EXPERT )
			{
				if( odds >= oddsExpert[ oddsIndex ] )
					betAction( isLimitBet );
				else
					foldAction( );
			}
		}
	}	
}

void Human::setPostFlop( bool isLimitBet )
{
	mDecision = this->postFlopHelp( );

	// Don't raise  if limited & Don't check < money
	while( ( isLimitBet && mDecision == RAISE ) || ( mDealerBet > mBet ) && ( mDecision == CHECK ) )	
		mDecision = postFlopHelp( );

	mRaiseAmount = 2 * mBigBlind;
}

int Human::postFlopHelp( )
{
	// Random (CHECK / CALL / RAISE /FOLD)
	int randBet = ( rand( ) % 10 );

	if( randBet <= 3 )
	{
		randBet = CHECK;
	}
	else if( ( randBet > 3 ) && ( randBet <= 6 ) ) {
		randBet = CALL;
	}
	else if( ( randBet > 6 ) && ( randBet <= 8 ) ) {
		randBet = RAISE;
	}
	else {
		randBet = FOLD;
	}
	
	return randBet;
}

void Human::setStrength( )
{
	// Skill Between (0 - 2)
	mStrength = rand( ) % 3; 
}

int Human::getStrength( )
{
	return mStrength;
}

void Human::sortHoleCards( )
{
	if( mHoleCards[ 0 ] < mHoleCards[ 1 ] )
	{
		mHoleCards[ 0 ] = mHoleCards[ 1 ];
		mHoleCards[ 1 ] = mHoleCards[ 0 ];
	}
}

void Human::foldAction( )
{
	if( mDealerBet == mBet )
	{
		mDecision = CHECK;
	}
	else if( mPlayersLeft <= 3 ) {
		mDecision = CALL;
	}
	else {
		mDecision = FOLD;
	}
}

void Human::betAction( bool isLimitBet )
{
	if( ( mDealerBet >= 2 * mBigBlind ) || ( isLimitBet ) ) 
	{
		mDecision = CALL;
	}
	else {
		int modulus = ( rand( ) % 5 ) + 1;
		mRaiseAmount = ( double ) mSmallBlind * modulus;
		mDecision = RAISE;
	}
}

std::ostream& operator << ( std::ostream& output, Human &outputHuman )
{
	output << outputHuman.mPosition << "\t";
	output << outputHuman.mName << "\t";
	output << outputHuman.mAllIn << "\t";
	output << outputHuman.mFold << "\t";
	output << outputHuman.mBust << "\t";
	output << outputHuman.mStrength << "\t";	
	output << outputHuman.mMoney << "\t";

	return output;
}







