#include "ICECar.h"

ICECar::ICECar(std::string id, std::string brand, float price, EngineType type)
    :_id{id}, _brand_name{brand}, _price{price}, _engine_type{type}
{
}

float ICECar::CalculateRegisterationCharges()
{
    if(_engine_type==EngineType::PETROL){
        return 0.1 * _price;
    }
    else if(_engine_type==EngineType::DIESEL){
        return 0.13 * _price;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id
       << " _brand_name: " << rhs._brand_name
       << " _price: " << rhs._price
       << " _engine_type: ";
       if(static_cast<int>(rhs._engine_type)==0){
        os<<"PETROL";
       }
       else if(static_cast<int>(rhs._engine_type)==1){
        os<<"DIESEL";
       }
    return os;
}
