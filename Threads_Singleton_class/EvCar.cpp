#include "EvCar.h"

EvCar::EvCar(float capacity, EvCarType type, float price)
    :_batteryCapacity{capacity}, _charging_type{type}, _price{price}
{
}

float EvCar::CalculateGst()
{
    return _price*0.1;
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_batteryCapacity: " << rhs._batteryCapacity
       << " _charging_type: ";
    if(static_cast<int>(rhs._charging_type)==0){
        os<<"DC";
    }
    else if(static_cast<int>(rhs._charging_type)==1){
        os<<"AC";
    }
    else if(static_cast<int>(rhs._charging_type)==2){
        os<<"BOTH";
    }
    os << " _price: " << rhs._price;
    return os;
}
