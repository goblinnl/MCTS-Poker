#ifndef TYPE_H
#define TYPE_H

// Internal
#include "Constants.hpp"

class Type {
	public:
		Type( );
		~Type( );

		void setType( int label, int kick1 = 0, int kick2 = 0, int kick3 = 0, int kick4 = 0, int kick5 = 0 );
		int getType();
		void clear( );

		friend bool operator > ( Type& type1, Type& type2 );
		friend bool operator == ( Type& type1, Type& type2 );
	
	private:
		int mLabel;
		int mKick1;
		int mKick2;
		int mKick3;
		int mKick4;
		int mKick5;

}; // Handtypes

#endif