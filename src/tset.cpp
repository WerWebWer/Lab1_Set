
#include "tset.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp) {}


TSet::TSet(const TSet& s) : BitField(s.BitField), MaxPower(s.MaxPower) {} //copy constructor


TSet::TSet(const TBitField& bf) : BitField(bf), MaxPower(bf.GetLength()) {} //type conversion constructor


TSet::operator TBitField() {
	return BitField;
}

int TSet::GetMaxPower(void) const { //get the maximum number of items
	return MaxPower;
}

bool TSet::IsMember(const int Elem) const { //Is it an element of the multitude?
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) { //inclusion of an element of the set
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) { //exception of the element of the set
	BitField.ClrBit(Elem);
}

//#############################

//below set-theoretic operations

//#############################

TSet& TSet::operator=(const TSet& s) { //assignment
	if (this != &s) {
		MaxPower = s.MaxPower;
		BitField = s.BitField;
	}
	return *this;
}

int TSet::operator==(const TSet& s) const { //comparison

	if (MaxPower != s.MaxPower)
	{
		return false;
	}
	if (BitField != s.BitField)
	{
		return false;
	}
	return true;
}

int TSet::operator!=(const TSet &s) const { //comparison
	if (s==*this) return false;
	return true;
}

TSet TSet::operator+(const TSet& s) { //union
	TBitField temp(*this);
	temp = temp | s.BitField;
	TSet res(temp);
	return res;
}

TSet TSet::operator+(const int Elem) { //union with element
	TSet res(*this);
	res.InsElem(Elem);
	return res;
}

TSet TSet::operator-(const int Elem) { //difference with element
	TSet res(*this);
	res.DelElem(Elem);
	return res;
}

TSet TSet::operator*(const TSet& s) { //intersection
	TBitField temp(*this);
	temp = temp & s.BitField;
	TSet res(temp);
	return res;
}

TSet TSet::operator~(void) { //addition
	return ~BitField;
}

//#############################

//below input / output overload

//#############################

istream& operator>>(istream& istr, TSet& s) { //input
	int i;
	istr >> i;
	while (i >= 0) {
		s.InsElem(i);
		istr >> i;
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) { //output
	ostr << "{ ";
	for (int i = 0; i < s.MaxPower; i -= -1) if (s.IsMember(i)) ostr << i << " ";
	ostr << "}";
	return ostr;
}
