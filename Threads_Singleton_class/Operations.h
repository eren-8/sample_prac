#ifndef OPERATIONS_H
#define OPERATIONS_H

#include<memory>
#include<variant>
#include<iostream>
#include<vector>
#include<mutex>
#include "EvCar.h"
#include "Automobile.h"
#include "ContainerEmptyFutureException.h"
#include<unordered_map>

using EvPtr = std::shared_ptr<EvCar>;
using AutomobilePtr = std::shared_ptr<Automobile>;
using VType = std::variant<EvPtr,AutomobilePtr>;
using Container = std::vector<VType>;
using map = std::unordered_map<std::string,VType>;

class Operations {
private:
    Container m_data;
    map mapper;
    std::mutex mt;
    Operations(const Operations&) = delete; // Copy constructor
    Operations& operator=(const Operations&) = delete; // Copy assignment operator
    Operations(Operations&&) = delete; // Move constructor
    Operations& operator=(Operations&&) = delete; // Move assignment operator

    static std::shared_ptr<Operations> _instance;

public:
    Operations() = default; // Default constructor
    ~Operations() = default; // Destructor

    static std::shared_ptr<Operations> getInstance();

    void CreateObjects();
    void FindAndDisplayGstForAllEVCar();
    void FindAndDisplayCountOfSeatInAutomobile();
    void FindAndDisplayAveragePriceOfAllAutoobile();
    void FindAtleastOneInstanceOfEvCarHavingDCorNot();
    void Print();
};


#endif // OPERATIONS_H
