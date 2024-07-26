

#ifndef NOINSTANCEEXCEPTION_H
#define NOINSTANCEEXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class NoInstanceException : public std::exception
{
    std::string _msg;

public:
    NoInstanceException() = delete;

    NoInstanceException(const NoInstanceException &) = delete; // disabled copy constructor

    NoInstanceException(NoInstanceException &&) = delete; // disabled move constructor brand new in C++11

    NoInstanceException &operator=(const NoInstanceException &) = delete; // disabled assignment operator
    NoInstanceException &operator=(NoInstanceException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~NoInstanceException() = default;
    NoInstanceException(std::string msg) : _msg(msg)
    {
    }
    std::string what()
    {
        return _msg;
    }

    
};


#endif // NOINSTANCEEXCEPTION_H
