#include "CarUnit.h"

CarUnit::CarUnit(std::string brand, float price, CarType type, int speed, int rpm, CarGearSystem gear)
    :m_car_brand{brand}, m_car_price{price}, m_car_type{type}, m_car_top_speed{speed}, m_car_top_rpm{rpm}, m_car_gear_system{gear}
{
}
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs) {
    os << "m_car_brand: " << rhs.m_car_brand
       << " m_car_price: " << rhs.m_car_price
       << " m_car_type: ";
        if(static_cast<int>(rhs.m_car_type)==0){
            os<<"SEDAN";
        }
        else if(static_cast<int>(rhs.m_car_type)==1){
            os<<"SUV";
        }
        else if(static_cast<int>(rhs.m_car_type)==2){
            os<<"HATCHBACK";
        }
       os<< " m_car_top_speed: " << rhs.m_car_top_speed
       << " m_car_top_rpm: " << rhs.m_car_top_rpm
       << " m_car_gear_system: ";
       if(static_cast<int>(rhs.m_car_gear_system)==0){
        os<<"PRNDL";
       }
       else if(static_cast<int>(rhs.m_car_gear_system)==1){
        os<<"TIPTRONIC";
       }
       else if(static_cast<int>(rhs.m_car_gear_system)==2){
        os<<"CLASSIC";
       }
    return os;
}
