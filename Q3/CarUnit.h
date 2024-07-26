#ifndef CARUNIT_H
#define CARUNIT_H

#include <iostream>
#include "CarType.h"
#include "CarGearSystem.h"

class CarUnit 
{
private:
    std::string m_car_brand;
    float m_car_price;
    CarType m_car_type;
    int m_car_top_speed;
    int m_car_top_rpm;
    CarGearSystem m_car_gear_system;
public:
    CarUnit() = default; // Default constructor
    CarUnit(const CarUnit&) = default; // Copy constructor
    CarUnit& operator=(const CarUnit&) = delete; // Copy assignment operator
    CarUnit(CarUnit&&) = delete; // Move constructor
    CarUnit& operator=(CarUnit&&) = delete; // Move assignment operator
    ~CarUnit() = default; // Destructor

    CarUnit(std::string brand,float price, CarType type, int speed,int rpm, CarGearSystem gear);

    std::string carBrand() const { return m_car_brand; }
    void setCarBrand(const std::string &car_brand) { m_car_brand = car_brand; }

    float carPrice() const { return m_car_price; }
    void setCarPrice(float car_price) { m_car_price = car_price; }

    CarType carType() const { return m_car_type; }
    void setCarType(const CarType &car_type) { m_car_type = car_type; }

    int carTopSpeed() const { return m_car_top_speed; }
    void setCarTopSpeed(int car_top_speed) { m_car_top_speed = car_top_speed; }

    int carTopRpm() const { return m_car_top_rpm; }
    void setCarTopRpm(int car_top_rpm) { m_car_top_rpm = car_top_rpm; }

    CarGearSystem carGearSystem() const { return m_car_gear_system; }
    void setCarGearSystem(const CarGearSystem &car_gear_system) { m_car_gear_system = car_gear_system; }

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};

#endif // CARUNIT_H
