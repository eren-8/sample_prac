#include <iostream>
#include<stdexcept>
#include <future>

class DataEmptyFutureException : public std::future_error {
private:
    std::string _msg;

public:
    DataEmptyFutureException() = default; // Default constructor
    DataEmptyFutureException(const DataEmptyFutureException &) = default;           // Copy constructor
    DataEmptyFutureException &operator=(const DataEmptyFutureException &) = delete; // Copy assignment operator
    DataEmptyFutureException(DataEmptyFutureException &&) = delete;                 // Move constructor
    DataEmptyFutureException &operator=(DataEmptyFutureException &&) = delete;      // Move assignment operator
    ~DataEmptyFutureException() = default;                           // Destructor
    DataEmptyFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
