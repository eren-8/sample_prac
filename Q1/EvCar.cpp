#include "EvCar.h"

EvCar::EvCar(std::string id, int battery_charging_time, EvCarType type, float chassis_length, int seat_count, int speed)
    :m_car_id{id}, m_battery_charging_time{battery_charging_time}, m_type{type}, m_chassis_length{chassis_length}, m_seat_count{seat_count}, m_top_speed{speed}
{
}
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "m_car_id: " << rhs.m_car_id
       << " m_battery_charging_time: " << rhs.m_battery_charging_time
       << " m_type: ";
       if(static_cast<int>(rhs.m_type)==0){
        os<<"PURE_EV";
       }
       else if(static_cast<int>(rhs.m_type)==1){
        os<<"IC_BASED";
       }
       os << " m_chassis_length: " << rhs.m_chassis_length
       << " m_seat_count: " << rhs.m_seat_count
       << " m_top_speed: " << rhs.m_top_speed;
    return os;
}
