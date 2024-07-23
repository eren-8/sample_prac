#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include "EvCarType.h"

class EvCar 
{
private:
    float _batteryCapacity {0.0f};
    EvCarType _charging_type {EvCarType::AC};
    float _price {1000.0f};

public:
    EvCar() = default; // Default constructor
    EvCar(const EvCar&) = default; // Copy constructor
    EvCar& operator=(const EvCar&) = delete; // Copy assignment operator
    EvCar(EvCar&&) = default; // Move constructor
    EvCar& operator=(EvCar&&) = delete; // Move assignment operator
    ~EvCar() = default; // Destructor

    EvCar(float capacity, EvCarType type, float price);
    float CalculateGst();

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    EvCarType chargingType() const { return _charging_type; }
    void setChargingType(const EvCarType &charging_type) { _charging_type = charging_type; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
