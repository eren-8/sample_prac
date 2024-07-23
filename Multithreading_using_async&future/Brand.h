#ifndef BRAND_H
#define BRAND_H

#include <iostream>
#include<functional>
#include "Car.h"
#include<vector>
#include<array>
#include "BrandType.h"

using RefWrapper = std::reference_wrapper<Car>;
using CarContainerRef = std::vector<RefWrapper>;

class Brand 
{
private:
    BrandType _type {BrandType::CONSUMER};
    std::string _unique_tm {""};
    CarContainerRef _cars;
public:
    Brand() = default; // Default constructor
    Brand(const Brand&) = default; // Copy constructor
    Brand& operator=(const Brand&) = delete; // Copy assignment operator
    Brand(Brand&&) = default; // Move constructor
    Brand& operator=(Brand&&) = delete; // Move assignment operator
    ~Brand() = default; // Destructor

    Brand(BrandType type, std::string bname,CarContainerRef cars);

    BrandType type() const { return _type; }
    void setType(const BrandType &type) { _type = type; }

    std::string uniqueTm() const { return _unique_tm; }

    CarContainerRef cars() const { return _cars; }
    void setCars(const CarContainerRef &cars) { _cars = cars; }

    friend std::ostream &operator<<(std::ostream &os, const Brand &rhs);
};

#endif // BRAND_H
