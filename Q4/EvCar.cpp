#include "EvCar.h"

EvCar::EvCar(std::string id, std::string brand, float price, EPowerType enginetype, BatteryType batterytype)
    :_id{id}, _brandName{brand}, _price{price}, _engine_type{enginetype}, _battery_type{batterytype}
{
}

float EvCar::CalculateRegisterationCharges()
{
    if(_engine_type==EPowerType::ELECTRIC){
        return 0.05 * _price;
    }
    else if(_engine_type==EPowerType::HYBRID){
        return 0.08 * _price;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_id: " << rhs._id
       << " _brandName: " << rhs._brandName
       << " _price: " << rhs._price
       << " _engine_type: ";
       if(static_cast<int>(rhs._engine_type)==0){
        os<<"HYBRID";
       }
       else if(static_cast<int>(rhs._engine_type)==1){
        os<<"ELECTRIC";
       }
       os<< " _battery_type: ";
       if(static_cast<int>(rhs._battery_type)==0){
        os<<"LI_ON";
       }
       else if(static_cast<int>(rhs._battery_type)==1){
        os<<"NICAD";
       }
       else if(static_cast<int>(rhs._battery_type)==2){
        os<<"OTHER";
       }
    return os;
}
