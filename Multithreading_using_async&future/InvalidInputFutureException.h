#include <iostream>
#include<stdexcept>
#include <future>

class InvalidInputFutureException : public std::future_error {
private:
    std::string _msg;

public:
    InvalidInputFutureException() = default; // Default constructor
    InvalidInputFutureException(const InvalidInputFutureException &) = default;           // Copy constructor
    InvalidInputFutureException &operator=(const InvalidInputFutureException &) = delete; // Copy assignment operator
    InvalidInputFutureException(InvalidInputFutureException &&) = delete;                 // Move constructor
    InvalidInputFutureException &operator=(InvalidInputFutureException &&) = delete;      // Move assignment operator
    ~InvalidInputFutureException() = default;                           // Destructor
    InvalidInputFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
