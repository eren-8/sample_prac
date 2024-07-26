#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine 
{
private:
    std::string m_engine_number {"0"};
    int m_engine_torque {0};
    int m_horsepower {0};
    EngineType m_engine_type {EngineType::CRDI};
public:
    Engine() = default; // Default constructor
    Engine(const Engine&) = default; // Copy constructor
    Engine& operator=(const Engine&) = delete; // Copy assignment operator
    Engine(Engine&&) = default; // Move constructor
    Engine& operator=(Engine&&) = delete; // Move assignment operator
    ~Engine() = default; // Destructor

    Engine(std::string number,int torque, int hp,EngineType type);

    std::string engineNumber() const { return m_engine_number; }
    void setEngineNumber(const std::string &engine_number) { m_engine_number = engine_number; }

    int engineTorque() const { return m_engine_torque; }
    void setEngineTorque(int engine_torque) { m_engine_torque = engine_torque; }

    int horsepower() const { return m_horsepower; }
    void setHorsepower(int horsepower) { m_horsepower = horsepower; }

    EngineType engineType() const { return m_engine_type; }
    void setEngineType(const EngineType &engine_type) { m_engine_type = engine_type; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
