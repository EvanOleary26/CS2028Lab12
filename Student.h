#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>

class Student {
	private:
		std::string firstName;
		std::string lastName;
		int mNumber;
		std::string major;

	public:
		Student() : firstName(" "), lastName(" "), mNumber(-1), major(" ") {};
        Student(std::string fN,std::string lN, int mN, std::string mjr) : firstName(fN), lastName(lN), mNumber(mN), major(mjr) {};

        int operator%(const int &right) { return this->mNumber % right; }

        bool operator>(const Student &right) { return this->mNumber > right.mNumber; }
        bool operator<(const Student &right) { return this->mNumber < right.mNumber; }
        bool operator==(const Student &right) { return mNumber == right.mNumber; }
		bool operator!=(const Student& right) { return mNumber != right.mNumber; }

		friend std::ostream& operator<<(std::ostream& os, const Student& right) {
			os << "m" << right.mNumber;
			return os;
		}
};

#endif
