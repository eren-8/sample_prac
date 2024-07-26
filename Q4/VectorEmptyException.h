#include <stdexcept>
#include <string>
#include <cstring>
class VectorEmptyException : public std::exception
{
    std::string _msg;

public:
    VectorEmptyException() = delete;

    VectorEmptyException(const VectorEmptyException &) = delete; // disabled copy constructor

    VectorEmptyException(VectorEmptyException &&) = delete; // disabled move constructor brand new in C++11

    VectorEmptyException &operator=(const VectorEmptyException &) = delete; // disabled assignment operator
    VectorEmptyException &operator=(VectorEmptyException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~VectorEmptyException() = default;
    VectorEmptyException(std::string msg) : _msg(msg)
    {
    }
    std::string what()
    {
        return _msg;
    }

    
};