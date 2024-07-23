#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"

class Car 
{
private:
    int _seat_count {3};
    float _price {1000.0f};
    float _wheel_base {0.0f};
    CarType _chassis {CarType::STEEL};
public:
    Car() = default; // Default constructor
    Car(const Car&) = default; // Copy constructor
    Car& operator=(const Car&) = default; // Copy assignment operator
    Car(Car&&) = default; // Move constructor
    Car& operator=(Car&&) = default; // Move assignment operator
    ~Car() = default; // Destructor

    Car(int seatcount, float price, float wheelbase, CarType type);

    int seatCount() const { return _seat_count; }
    void setSeatCount(int seat_count) { _seat_count = seat_count; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    float wheelBase() const { return _wheel_base; }
    void setWheelBase(float wheel_base) { _wheel_base = wheel_base; }

    CarType chassis() const { return _chassis; }
    void setChassis(const CarType &chassis) { _chassis = chassis; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
