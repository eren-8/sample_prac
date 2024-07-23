#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include "AutomobileType.h"

class Automobile 
{
private:
    std::string _id {"0"};
    AutomobileType _type {AutomobileType::REGULAR};
    float _price {1000.0f};
    int _seat_count {4};
    int _engine_horsepower {100};
public:
    Automobile() = default; // Default constructor
    Automobile(const Automobile&) = default; // Copy constructor
    Automobile& operator=(const Automobile&) = delete; // Copy assignment operator
    Automobile(Automobile&&) = default; // Move constructor
    Automobile& operator=(Automobile&&) = delete; // Move assignment operator
    ~Automobile() = default; // Destructor

    Automobile(std::string id,AutomobileType type,float price,int seat_count,int engine_horsepower);

    float CalculateGst();

    std::string id() const { return _id; }

    AutomobileType type() const { return _type; }
    void setType(const AutomobileType &type) { _type = type; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    int seatCount() const { return _seat_count; }
    void setSeatCount(int seat_count) { _seat_count = seat_count; }

    int engineHorsepower() const { return _engine_horsepower; }
    void setEngineHorsepower(int engine_horsepower) { _engine_horsepower = engine_horsepower; }

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};

#endif // AUTOMOBILE_H
