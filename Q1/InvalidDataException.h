#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class InvalidDataException : public std::exception
{
    std::string _msg;

public:
    InvalidDataException() = delete;

    InvalidDataException(const InvalidDataException &) = delete; // disabled copy constructor

    InvalidDataException(InvalidDataException &&) = delete; // disabled move constructor brand new in C++11

    InvalidDataException &operator=(const InvalidDataException &) = delete; // disabled assignment operator
    InvalidDataException &operator=(InvalidDataException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~InvalidDataException() = default;
    InvalidDataException(std::string msg) : _msg(msg)
    {
    }
    std::string what()
    {
        return _msg;
    }

    
};

#endif // INVALIDDATAEXCEPTION_H
