#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include "EPowerType.h"
#include "BatteryType.h"

class EvCar 
{
private:
    std::string _id;
    std::string _brandName;
    float _price;
    EPowerType _engine_type;
    BatteryType _battery_type;
public:
    EvCar() = default; // Default constructor
    EvCar(const EvCar&) = default; // Copy constructor
    EvCar& operator=(const EvCar&) = delete; // Copy assignment operator
    EvCar(EvCar&&) = delete; // Move constructor
    EvCar& operator=(EvCar&&) = delete; // Move assignment operator
    ~EvCar() = default; // Destructor

    EvCar(std::string id, std::string brand, float price, EPowerType enginetype, BatteryType batterytype);

    float CalculateRegisterationCharges();

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string brandName() const { return _brandName; }
    void setBrandName(const std::string &brandName) { _brandName = brandName; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    EPowerType engineType() const { return _engine_type; }
    void setEngineType(const EPowerType &engine_type) { _engine_type = engine_type; }

    BatteryType batteryType() const { return _battery_type; }
    void setBatteryType(const BatteryType &battery_type) { _battery_type = battery_type; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
