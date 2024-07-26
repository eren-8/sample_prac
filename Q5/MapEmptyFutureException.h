#include <iostream>
#include<stdexcept>
#include <future>

class MapEmptyFutureException : public std::future_error {
private:
    std::string _msg;

public:
    MapEmptyFutureException() = default; // Default constructor
    MapEmptyFutureException(const MapEmptyFutureException &) = default;           // Copy constructor
    MapEmptyFutureException &operator=(const MapEmptyFutureException &) = delete; // Copy assignment operator
    MapEmptyFutureException(MapEmptyFutureException &&) = delete;                 // Move constructor
    MapEmptyFutureException &operator=(MapEmptyFutureException &&) = delete;      // Move assignment operator
    ~MapEmptyFutureException() = default;                           // Destructor
    MapEmptyFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
