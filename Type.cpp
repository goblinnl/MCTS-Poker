// Internal
#include "stdafx.h"
#include "Type.hpp"

/* Default constructor. */
Type::Type( ) : mLabel( BLANK ), mKick1( 0 ), mKick2( 0 ), mKick3( 0 ), mKick4( 0 ), mKick5( 0 )
{

}

/* Destructor. */
Type::~Type( )
{

}

/**
 * Sets a Handtype.
 *
 * @param label The label.
 * @param kick1 The first kick.
 * @param kick2 The second kick.
 * @param kick3 The third kick.
 * @param kick4 The fourth kick.
 * @param kick5 The fifth kick.
 */
void Type::setType( int label, int kick1, int kick2, int kick3, int kick4, int kick5 )
{
	mLabel = BLANK;
	mKick1 = kick1;
	mKick2 = kick2;
	mKick3 = kick3;
	mKick4 = kick4;
	mKick5 = kick5;
}

/**
 * Gets the card label (type)
 *
 * @return The type.
 */
int Type::getType( )
{
	return mLabel;
}

/**
 * Clears this object to its blank/initial state.
 */
void Type::clear( )
{
	mLabel = BLANK;
	mKick1 = 0;
	mKick2 = 0;
	mKick3 = 0;
	mKick4 = 0;
	mKick5 = 0;
}

/**
 * Greater-than comparison operator.
 *
 * @author User
 * @date 23-12-2014
 *
 * @param [in,out] Handtype1 The first hand to compare.
 * @param [in,out] Handtype2 The second hand to compare.
 *
 * @return true if the first parameter is greater than to the second.
 */
bool operator > ( Type& type1, Type& type2 )
{
	if( type1.mLabel > type2.mLabel )
		return true;

	if( type1.mLabel == type2.mLabel )
	{
		if( type1.mKick1 > type2.mKick1 )		
			return true;			

		if( type1.mKick1 == type2.mKick1 ) {

			if( type1.mKick2 > type2.mKick2 )
				return true;

			if( type1.mKick2 == type2.mKick2 ) 
			{
				if( type1.mKick3 > type2.mKick3 )
					return true;

				if( type1.mKick3 == type2.mKick3 )
				{
					if( type1.mKick4 > type2.mKick4 )
						return true;

					if( type1.mKick4 == type2.mKick4 )
					{
						if( type1.mKick5 > type2.mKick5 )
							return true;
						else
							return false; // Kick 5
					}
					else {
						return false; // Kick 4
					}					
				}
				else {
					return false; // Kick 3
				}			
			}
			else {
				return false; // Kick 2
			}
		}
		else {
			return false; // Kick 1
		}
	} 
	else{
		return false;
	}
}

/**
 * Equality operator.
 *
 * @param [in,out] Handtype1 The first hand to compare.
 * @param [in,out] Handtype2 The second hand to compare.
 *
 * @return true if Handtype1 is equal to HandType2
 */
bool operator == ( Type& type1, Type& type2 )
{

	if( type1.mLabel == type2.mLabel &&
		type1.mKick1 == type2.mKick2 &&
		type1.mKick2 == type2.mKick2 &&
		type1.mKick3 == type2.mKick3 &&
		type1.mKick4 == type2.mKick4 &&
		type1.mKick5 == type2.mKick5 )
	{
		return true;
	} 
	
	return false;
}