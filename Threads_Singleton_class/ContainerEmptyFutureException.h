#include <iostream>
#include<stdexcept>
#include <future>

class ContainerEmptyFutureException : public std::future_error {
private:
    std::string _msg;

public:
    ContainerEmptyFutureException() = default; // Default constructor
    ContainerEmptyFutureException(const ContainerEmptyFutureException &) = default;           // Copy constructor
    ContainerEmptyFutureException &operator=(const ContainerEmptyFutureException &) = delete; // Copy assignment operator
    ContainerEmptyFutureException(ContainerEmptyFutureException &&) = delete;                 // Move constructor
    ContainerEmptyFutureException &operator=(ContainerEmptyFutureException &&) = delete;      // Move assignment operator
    ~ContainerEmptyFutureException() = default;                           // Destructor
    ContainerEmptyFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
