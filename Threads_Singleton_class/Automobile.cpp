#include "Automobile.h"

Automobile::Automobile(std::string id, AutomobileType type, float price, int seat_count, int engine_horsepower)
    :_id{id}, _type{type}, _price{price}, _seat_count{seat_count}, _engine_horsepower{engine_horsepower}
{
}

float Automobile::CalculateGst()
{
    return 0.18 * _price;
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "_id: " << rhs._id
       << " _type: ";
       if(static_cast<int>(rhs._type)==0){
        os<<"REGULAR";
       }
       else if(static_cast<int>(rhs._type)==1){
        os<<"TRANSPORT";
       }
      os << " _price: " << rhs._price
       << " _seat_count: " << rhs._seat_count
       << " _engine_horsepower: " << rhs._engine_horsepower;
    return os;
}
