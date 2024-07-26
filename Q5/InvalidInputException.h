#include <iostream>
#include<stdexcept>
#include <future>

class InvalidInputException : public std::future_error {
private:
    std::string _msg;

public:
    InvalidInputException() = default; // Default constructor
    InvalidInputException(const InvalidInputException &) = default;           // Copy constructor
    InvalidInputException &operator=(const InvalidInputException &) = delete; // Copy assignment operator
    InvalidInputException(InvalidInputException &&) = delete;                 // Move constructor
    InvalidInputException &operator=(InvalidInputException &&) = delete;      // Move assignment operator
    ~InvalidInputException() = default;                           // Destructor
    InvalidInputException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
