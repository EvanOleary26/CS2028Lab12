#ifndef __STUDENT__H
#define __STUDENT__H

#include <iostream>

class Student {
	private:
		std::string firstName;
		std::string lastName;
		int mNumber;
		std::string major;

		static bool sortFirstName;
		static bool sortLastName;
	public:
		Student() : firstName(" "), lastName(" "), mNumber(-1), major(" ") {};
		Student(int mN) : firstName(" "), lastName(" "), mNumber(mN), major(" ") {};
        Student(std::string fN,std::string lN, int mN, std::string mjr) : firstName(fN), lastName(lN), mNumber(mN), major(mjr) {};

		std::string getFirstName() { return firstName; }
		std::string getLastName() { return lastName; }
		int getMNumber() { return mNumber; }
		std::string getMajor() { return major; }

		void sortByFirstName();
		void sortByLastName();
		void sortByMNumber();
		
		// Operator overloads
		operator int() const;
		int operator%(const int &right);
		int operator/(const int &right);
		bool operator>(const Student &right);
		bool operator<(const Student &right);
		bool operator==(const Student &right);
		bool operator!=(const Student &right);

		// Friend operator
		friend std::ostream& operator<<(std::ostream& os, const Student& right);
};

#endif
