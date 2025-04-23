#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <iostream>

class Exception {
public:
    int errorNumber;
    std::string errorMessage;

    Exception() : errorNumber(0), errorMessage("") {};
    Exception(int errNum) : errorNumber(errNum) {};
    Exception(std::string errMess) : errorMessage(errMess) {};
    Exception(int errNum, std::string errMess) : errorNumber(errNum), errorMessage(errMess) {};
};




#endif