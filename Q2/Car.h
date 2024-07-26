#ifndef CAR_H
#define CAR_H

#include <iostream>
#include<functional>
#include "Engine.h"

class Car 
{
private:
    std::string m_car_reg_num {"0"};
    float m_price {100.0f};
    std::reference_wrapper<Engine> m_car_engine;
public:
    Car() = default; // Default constructor
    Car(const Car&) = default; // Copy constructor
    Car& operator=(const Car&) = delete; // Copy assignment operator
    Car(Car&&) = default; // Move constructor
    Car& operator=(Car&&) = delete; // Move assignment operator
    ~Car() = default; // Destructor

    Car(std::string number,float price, std::reference_wrapper<Engine>engine);

    std::string carRegNum() const { return m_car_reg_num; }
    void setCarRegNum(const std::string &car_reg_num) { m_car_reg_num = car_reg_num; }

    float price() const { return m_price; }
    void setPrice(float price) { m_price = price; }

    std::reference_wrapper<Engine> carEngine() const { return m_car_engine; }
    void setCarEngine(const std::reference_wrapper<Engine> &car_engine) { m_car_engine = car_engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
