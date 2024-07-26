#include <iostream>
#include<stdexcept>
#include <future>

class VehicleEmptyFutureException : public std::future_error {
private:
    std::string _msg;

public:
    VehicleEmptyFutureException() = default; // Default constructor
    VehicleEmptyFutureException(const VehicleEmptyFutureException &) = default;           // Copy constructor
    VehicleEmptyFutureException &operator=(const VehicleEmptyFutureException &) = delete; // Copy assignment operator
    VehicleEmptyFutureException(VehicleEmptyFutureException &&) = delete;                 // Move constructor
    VehicleEmptyFutureException &operator=(VehicleEmptyFutureException &&) = delete;      // Move assignment operator
    ~VehicleEmptyFutureException() = default;                           // Destructor
    VehicleEmptyFutureException(std::string msg, std::future_errc ec) : future_error(ec), _msg{msg} {}
    std::string what() {
        return _msg;
    }
};
