
#ifndef __SET_H__
#define __SET_H__

#include "tbitfield.h"

class TSet
{
private:
	int MaxPower; // maximum power of the set
	TBitField BitField; // bit field for storing the characteristic vector
public:
	TSet(int mp);
	TSet(const TSet& s); // copy constructor
	TSet(const TBitField& bf); // type conversion constructor
	operator TBitField (); // type conversion to bit field
	// access to bits
	int GetMaxPower(void) const; // maximum power of the set
	void InsElem(const int Elem); // include element in set
	void DelElem(const int Elem); // remove an element from the set
	bool IsMember(const int Elem) const; // check for the presence of an element in the set
	// set-theoretic operations
	int operator== (const TSet& s) const; // comparison
	int operator!= (const TSet & s) const; // comparison
	TSet& operator= (const TSet& s); // assignment
	TSet operator+ (const int Elem); // union with the element
									 // element must be from the same university
	TSet operator- (const int Elem); // difference with element
									 // element must be from the same university
	TSet operator+ (const TSet& s); // an association
	TSet operator* (const TSet& s); // intersection
	TSet operator~ (void); // addition

  friend istream &operator>>(istream &istr, TSet &bf);
  friend ostream &operator<<(ostream &ostr, const TSet &bf);
};
#endif
