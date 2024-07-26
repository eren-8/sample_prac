#include "Engine.h"

Engine::Engine(std::string number, int torque, int hp, EngineType type)
    :m_engine_number{number}, m_engine_torque{torque}, m_horsepower{hp}, m_engine_type{type}
{
}
std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "m_engine_number: " << rhs.m_engine_number
       << " m_engine_torque: " << rhs.m_engine_torque
       << " m_horsepower: " << rhs.m_horsepower
       << " m_engine_type: ";
       if(static_cast<int>(rhs.m_engine_type)==0){
        os<<"CRDI";
       }
       else if(static_cast<int>(rhs.m_engine_type)==1){
        os<<"MPFI";
       }
       else if(static_cast<int>(rhs.m_engine_type)==2){
        os<<"TURBOCHARGED";
       }
    return os;
}
