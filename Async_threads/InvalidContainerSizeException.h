#include <iostream>
#include<stdexcept>
#include <future>

class InvalidContainerSizeException : public std::future_error {
private:
    std::string _msg;

public:
    InvalidContainerSizeException() = default; // Default constructor
    InvalidContainerSizeException(const InvalidContainerSizeException &) = default;           // Copy constructor
    InvalidContainerSizeException &operator=(const InvalidContainerSizeException &) = delete; // Copy assignment operator
    InvalidContainerSizeException(InvalidContainerSizeException &&) = delete;                 // Move constructor
    InvalidContainerSizeException &operator=(InvalidContainerSizeException &&) = delete;      // Move assignment operator
    ~InvalidContainerSizeException() = default;                           // Destructor
    InvalidContainerSizeException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
