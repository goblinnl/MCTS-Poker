#ifndef CONSTANTS_H
#define CONSTANTS_H

/* TODO Fix the enums & correct comments*/

///< Betting Rules
enum 
{
	HOLECARDS, 
	FLOP, 
	TURN, 
	RIVER 
};

/** Hands. */
enum typeName 
{ 
	BLANK, 
	JUNK, 
	PAIR, 
	TWOPAIR, 
	THREEKIND, 
	STRAIGHT, 
	FLUSH, 
	FULL,
	FOURKIND, 
	SFLUSH,
	RFLUSH 
};

///< Forced Bets
enum 
{ 
	DEALER = 0,
	SMALLBLIND = 1,
	BIGBLIND = 2
};

///< Level of Experience
enum 
{ 
	BEGINNER = 0,
	INTERMEDIATE = 1,
	EXPERT = 2
};

///< Betting Options
enum 
{ 
	CHECK,
	CALL,
	RAISE,
	FOLD
};

#endif