#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;

typedef unsigned int TELEM;

class TBitField {
	private:
		int BitLen; // bit field length - max. number of bits
		TELEM* pMem; // memory to represent the bit field
		int MemLen; // number of memes to represent the bit field

		// implementation methods
		int GetMemIndex(const int n) const; // index in pMem for bit n (# О2)
		TELEM GetMemMask(const int n) const; // bitmask for bit n (# О3)
	public:
		TBitField(int len); // (# О1)
		TBitField(const TBitField& bf); // (# П1)
		~TBitField(); //                                    (#С)

		// access to bits
		int GetLength(void) const; // get the length (number of bits) (# О)
		void SetBit(const int n); // set the bit (# О4)
		void ClrBit(const int n); // clear the bit (# П2)
		bool GetBit(const int n) const; // get the value of the bit (# Л1)

		// bitwise operations
		bool operator== (const TBitField& bf) const; // comparison (# О5)
		bool operator!= (const TBitField & bf) const; // comparison
		TBitField& operator= (const TBitField& bf); // assignment (# П3)
		TBitField operator| (const TBitField& bf); // operation "or" (# О6)
		TBitField operator& (const TBitField& bf); // operation "and" (# Л2)
		TBitField operator~ (void); // negation (# С)

		friend istream& operator >> (istream& is, TBitField& bf);
		// (# О7)
		friend ostream& operator << (ostream& os, const TBitField& bf);
		// (# П4)
};

// The structure of the storage of the bit field
// bit.field - a set of bits with numbers from 0 to BitLen
// array pMem is considered as a sequence of MemLen elements
// bits in el p-meme are numbered from right to left (from low to high)
// О8 Л2 П4 С2

#endif
