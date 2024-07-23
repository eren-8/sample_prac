#include "Car.h"

Car::Car(int seatcount, float price, float wheelbase, CarType type)
    :_seat_count{seatcount}, _price{price}, _wheel_base{wheelbase}, _chassis{type}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_seat_count: " << rhs._seat_count
       << " _price: " << rhs._price
       << " _wheel_base: " << rhs._wheel_base
       << " _chassis: ";
       if(static_cast<int>(rhs._chassis)==0){
        os<<"CARBON_FIBER";
       }
       else if(static_cast<int>(rhs._chassis)==1){
        os<<"STEEL";
       }
    return os;
}
