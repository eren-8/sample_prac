#include "Brand.h"

Brand::Brand(BrandType type, std::string bname, CarContainerRef cars)
    :_type{type}, _unique_tm{bname}, _cars{cars}
{
}
std::ostream &operator<<(std::ostream &os, const Brand &rhs) {
    os << "_type: ";
    if(static_cast<int>(rhs._type)==0){
        os<<"CONSUMER";
    }
    else if(static_cast<int>(rhs._type)==1){
        os<<"SPECIAL_PURPOSE";
    }
    else if(static_cast<int>(rhs._type)==2){
        os<<"TRANSPORT";
    }
    os << " _unique_tm: " << rhs._unique_tm
       << " _cars: ";
       for(auto& obj:rhs._cars){
        os<<obj.get();
       }
    return os;
}
