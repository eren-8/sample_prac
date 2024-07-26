#include "Car.h"

Car::Car(std::string number, float price, std::reference_wrapper<Engine> engine)
    :m_car_reg_num{number}, m_price{price}, m_car_engine{engine}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "m_car_reg_num: " << rhs.m_car_reg_num
       << " m_price: " << rhs.m_price
       << " m_car_engine: " << rhs.m_car_engine.get();
    return os;
}
