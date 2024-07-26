#include <stdexcept>
#include <string>
#include <cstring>
class InvalidInputException : public std::exception
{
    std::string _msg;

public:
    InvalidInputException() = delete;

    InvalidInputException(const InvalidInputException &) = delete; // disabled copy constructor

    InvalidInputException(InvalidInputException &&) = delete; // disabled move constructor brand new in C++11

    InvalidInputException &operator=(const InvalidInputException &) = delete; // disabled assignment operator
    InvalidInputException &operator=(InvalidInputException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~InvalidInputException() = default;
    InvalidInputException(std::string msg) : _msg(msg)
    {
    }
    std::string what()
    {
        return _msg;
    }

    
};