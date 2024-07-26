#include "Vehicle.h"

Vehicle::Vehicle(std::string id, float price, VehicleType type, TransmissionType Ttype, int bootspace, bool isinsured)
    :m_vehicle_id{id}, m_vehicle_price{price}, m_vehicle_category{type}, m_transmission_type{Ttype}, m_boot_space{bootspace}, m_is_vehicle_insured{isinsured}
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "m_vehicle_id: " << rhs.m_vehicle_id
       << " m_vehicle_price: " << rhs.m_vehicle_price
       << " m_vehicle_category: ";
       if(static_cast<int>(rhs.m_vehicle_category)==0){
        os<<"PUBLIC";
       }
       else if(static_cast<int>(rhs.m_vehicle_category)==1){
        os<<"PRIVATE";
       }
       else if(static_cast<int>(rhs.m_vehicle_category)==2){
        os<<"GOVT";
       }
       os<<" m_transmission_type: ";
       if(static_cast<int>(rhs.m_transmission_type)==0){
        os<<"AMT";
       }
       else if(static_cast<int>(rhs.m_transmission_type)==0){
        os<<"MANUAL";
       }
       else if(static_cast<int>(rhs.m_transmission_type)==0){
        os<<"AUTOMATIC";
       }
       os<< " m_boot_space: " << rhs.m_boot_space
       << " m_is_vehicle_insured: " << std::boolalpha <<rhs.m_is_vehicle_insured;
    return os;
}
