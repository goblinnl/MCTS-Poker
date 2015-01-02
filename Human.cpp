#include "Human.hpp"

/**
 * Default constructor.
 *
 */
Human::Human( ) : mChipAmount( 0 ), mHandsPlayed( 0 ), mHandsWon( 0 ), mFlopSeen( 0 ), mRaises( 0 ), mOut( false ), mBust( false )
{

}

/**
 * Constructor.
 *
 * @param chipCount Amount of chips.
 */
Human::Human( int chipCount ) : mChipAmount( chipCount ), mHandsPlayed( 0 ), mHandsWon( 0 ), mFlopSeen( 0 ), mRaises( 0 ), mOut( false ), mBust( false )
{

}

/**
 * Sets a money.
 *
 * @param amount Of Money.
 */
void Human::setMoney( int amount )
{
	mChipAmount += double( amount );
	mBust = false;
}

/**
 * Table point.
 *
 * @param [in,out] mapPoint If non-null, the map point.
 */
void Human::tablePoint( std::map<std::string, double>* mapPoint )
{
	 mWeightTable = mapPoint;
}

/**
 * Is winning.
 *
 * @param amount The amount of money player won.
 */
void Human::isWinning( double amount )
{
	mChipAmount += amount;
}

/**
 * Sets the flop.
 */
void Human::setFlop( )
{
	mFlopSeen++;
}

/**
 * Sets fold before flop.
 */
void Human::setFoldBeforeFlop( )
{
	mFlopSeen--;
}

/**
 * Gets the strength of the human player.
 *
 * @return The strength.
 */
double Human::getStrength( )
{
	return double( mRaises / mHandsPlayed );
}

/**
 * Gets the tightness.
 *
 * @return The tightness.
 */
double Human::getTightness( )
{
	return double( mFlopSeen / mHandsPlayed );
}

/**
 * Sets the fold.
 */
void Human::setFold( )
{
	mOut = true;
}

/**
 * Raises the bet event.
 *
 * @param amount The amount.
 */
void Human::raiseBet( double amount )
{
	if( ( !mOut ) && ( amount <= mChipAmount ) && ( !mBust ) )
		mChipAmount -= amount;
}

/**
 * Check call.
 *
 * @param amount The amount.
 */
void Human::checkCall( double amount )
{
	if( ( !mOut ) && ( amount > mChipAmount ) && ( !mBust ) )
		mChipAmount -= amount;
}

/**
 * Sets the busted.
 */
void Human::setBusted( )
{
	mBust = true;
}

/**
 * Gets the weight.
 *
 * @return null if it fails, else the weight.
 */
std::map<std::string, double>* Human::getWeight( )
{
	return mWeightTable;
}

/**
 * Gets the money.
 *
 * @return The money.
 */
double Human::getMoney( )
{
	return mChipAmount;
}

/**
 * Sets the fold.
 */
void Human::setFold( )
{
	mOut = false;
}

/**
 * Gets the fold.
 *
 * @return true if it succeeds, false if it fails.
 */
bool Human::getFold( )
{
	return mOut;
}

/**
 * Gets the busted.
 *
 * @return true if it succeeds, false if it fails.
 */
bool Human::getBusted( )
{
	return mBust;
}