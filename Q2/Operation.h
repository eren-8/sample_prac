#ifndef OPERATION_H
#define OPERATION_H

#include<memory>
#include<iostream>
#include<optional>
#include<functional>
#include "Engine.h"
#include<algorithm>
#include<vector>
#include<numeric>
#include<optional>
#include<mutex>
#include "Car.h"

using Carptr = std::shared_ptr<Car>;
using RefContainer = std::vector<std::reference_wrapper<Engine>>;
class Operation {
private:
    std::vector<Carptr> m_data;
    bool flag=false;
    std::mutex mt;
    std::vector<Engine> m_engine;
    Operation(const Operation&) = delete; // Copy constructor
    Operation& operator=(const Operation&) = delete; // Copy assignment operator
    Operation(Operation&&) = delete; // Move constructor
    Operation& operator=(Operation&&) = delete; // Move assignment operator

    static std::shared_ptr<Operation> _instance;

public:
    Operation() = default; // Default constructor
    ~Operation() = default; // Destructor

    static std::shared_ptr<Operation> getInstance();

    void CreateObjects();
    /* function to return container of engine ref wrapper for each input */
    std::optional<RefContainer> ReturnEngineReference();

    /* return bool whether engine torque is above 120 */
    std::optional<bool> ReturnIfTorqueAbove120();

    /* find average horsepower whose price is above threshold (2nd parameter) */
    std::optional<float> ReturnAverageHorsePowerWithinThreshold(float price);

    /* return engine type whose car reg num is passed as argument */
    std::optional<EngineType> ReturnTypeOfSameRegNum(std::string number);

    /* return engine reference whose torque is hoghhest */
    std::optional<std::reference_wrapper<Engine>> ReturnEngineInstanceOfHighestTorque();
};

#endif // OPERATION_H
