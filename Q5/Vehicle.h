#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "TransmissionType.h"
#include "VehicleType.h"

class Vehicle 
{
private:
    std::string m_vehicle_id;
    float m_vehicle_price;
    VehicleType m_vehicle_category;
    TransmissionType m_transmission_type;
    int m_boot_space;
    bool m_is_vehicle_insured;
public:
    Vehicle() = default; // Default constructor
    Vehicle(const Vehicle&) = default; // Copy constructor
    Vehicle& operator=(const Vehicle&) = delete; // Copy assignment operator
    Vehicle(Vehicle&&) = default; // Move constructor
    Vehicle& operator=(Vehicle&&) = default; // Move assignment operator
    ~Vehicle() = default; // Destructor

    Vehicle(std::string id, float price, VehicleType type, TransmissionType Ttype, int bootspace, bool isinsured);

    std::string vehicleId() const { return m_vehicle_id; }
    void setVehicleId(const std::string &vehicle_id) { m_vehicle_id = vehicle_id; }

    float vehiclePrice() const { return m_vehicle_price; }
    void setVehiclePrice(float vehicle_price) { m_vehicle_price = vehicle_price; }

    VehicleType vehicleCategory() const { return m_vehicle_category; }
    void setVehicleCategory(const VehicleType &vehicle_category) { m_vehicle_category = vehicle_category; }

    TransmissionType transmissionType() const { return m_transmission_type; }
    void setTransmissionType(const TransmissionType &transmission_type) { m_transmission_type = transmission_type; }

    int bootSpace() const { return m_boot_space; }
    void setBootSpace(int boot_space) { m_boot_space = boot_space; }

    bool isVehicleInsured() const { return m_is_vehicle_insured; }
    void setIsVehicleInsured(bool is_vehicle_insured) { m_is_vehicle_insured = is_vehicle_insured; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
