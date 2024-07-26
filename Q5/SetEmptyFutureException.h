#include <iostream>
#include<stdexcept>
#include <future>

class SetEmptyFutureException : public std::future_error {
private:
    std::string _msg;

public:
    SetEmptyFutureException() = default; // Default constructor
    SetEmptyFutureException(const SetEmptyFutureException &) = default;           // Copy constructor
    SetEmptyFutureException &operator=(const SetEmptyFutureException &) = delete; // Copy assignment operator
    SetEmptyFutureException(SetEmptyFutureException &&) = delete;                 // Move constructor
    SetEmptyFutureException &operator=(SetEmptyFutureException &&) = delete;      // Move assignment operator
    ~SetEmptyFutureException() = default;                           // Destructor
    SetEmptyFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
