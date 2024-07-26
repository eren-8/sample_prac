#ifndef ICECAR_H
#define ICECAR_H

#include <iostream>
#include "EngineType.h"

class ICECar 
{
private:
    std::string _id;
    std::string _brand_name;
    float _price;
    EngineType _engine_type;
public:
    ICECar() = default; // Default constructor
    ICECar(const ICECar&) = default; // Copy constructor
    ICECar& operator=(const ICECar&) = delete; // Copy assignment operator
    ICECar(ICECar&&) = delete; // Move constructor
    ICECar& operator=(ICECar&&) = delete; // Move assignment operator
    ~ICECar() = default; // Destructor

    ICECar(std::string id,std::string brand,float price, EngineType type);

    float CalculateRegisterationCharges();

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string brandName() const { return _brand_name; }
    void setBrandName(const std::string &brand_name) { _brand_name = brand_name; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    EngineType engineType() const { return _engine_type; }
    void setEngineType(const EngineType &engine_type) { _engine_type = engine_type; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_H
