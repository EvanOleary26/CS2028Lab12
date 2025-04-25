#include "Student.h"

// Define static members here (only once)
bool Student::sortFirstName = false;
bool Student::sortLastName = false;

void Student::sortByFirstName() {
    sortFirstName = true;
    sortLastName = false;
}

void Student::sortByLastName() {
    sortFirstName = false;
    sortLastName = true;
}

void Student::sortByMNumber() {
    sortFirstName = false;
    sortLastName = false;
}

// Operator overloads
Student::operator int() const {
    return mNumber;
}

int Student::operator%(const int &right) {
    return this->mNumber % right;
}

int Student::operator/(const int &right) {
    return this->mNumber / right;
}

bool Student::operator>(const Student &right) {
    if (sortFirstName) {
        return this->firstName > right.firstName;
    } else if (sortLastName) {
        return this->lastName > right.lastName;
    }
    return this->mNumber > right.mNumber;
}

bool Student::operator<(const Student &right) {
    if (sortFirstName) {
        return this->firstName < right.firstName;
    } else if (sortLastName) {
        return this->lastName < right.lastName;
    }
    return this->mNumber < right.mNumber;
}

bool Student::operator==(const Student &right) {
    if (sortFirstName) {
        return this->firstName == right.firstName;
    } else if (sortLastName) {
        return this->lastName == right.lastName;
    }
    return this->mNumber == right.mNumber;
}

bool Student::operator!=(const Student &right) {
    if (sortFirstName) {
        return this->firstName != right.firstName;
    } else if (sortLastName) {
        return this->lastName != right.lastName;
    }
    return this->mNumber != right.mNumber;
}

// Friend stream operator
std::ostream& operator<<(std::ostream& os, const Student& right) {
    os << "m" << right.mNumber;
    return os;
}