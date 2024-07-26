#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>
#include "EvCarType.h"

class EvCar 
{
private:
    std::string m_car_id {"0"};
    int m_battery_charging_time {50};
    EvCarType m_type {EvCarType::IC_BASED};
    float m_chassis_length {10.0f};
    int m_seat_count {0};
    int m_top_speed {100};
public:
    EvCar() = default; // Default constructor
    EvCar(const EvCar&) = default; // Copy constructor
    EvCar& operator=(const EvCar&) = delete; // Copy assignment operator
    EvCar(EvCar&&) = delete; // Move constructor
    EvCar& operator=(EvCar&&) = delete; // Move assignment operator
    ~EvCar() = default; // Destructor

    EvCar(std::string id,int battery_charging_time,EvCarType type,float chassis_length,int seat_count,int speed);//parametrized constructor

    std::string carId() const { return m_car_id; }
    void setCarId(const std::string &car_id) { m_car_id = car_id; }

    int batteryChargingTime() const { return m_battery_charging_time; }
    void setBatteryChargingTime(int battery_charging_time) { m_battery_charging_time = battery_charging_time; }

    EvCarType type() const { return m_type; }
    void setType(const EvCarType &type) { m_type = type; }

    float chassisLength() const { return m_chassis_length; }
    void setChassisLength(float chassis_length) { m_chassis_length = chassis_length; }

    int seatCount() const { return m_seat_count; }
    void setSeatCount(int seat_count) { m_seat_count = seat_count; }

    int topSpeed() const { return m_top_speed; }
    void setTopSpeed(int top_speed) { m_top_speed = top_speed; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
