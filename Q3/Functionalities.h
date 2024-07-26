#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<unordered_map>
#include<iostream>
#include<memory>
#include<optional>
#include<algorithm>
#include<vector>
#include<numeric>
#include "CarUnit.h"


using Carptr = std::shared_ptr<CarUnit>;
using Container = std::unordered_map<std::string,Carptr>;
using VectorContainer = std::vector<Carptr>;
using MapEntry = std::pair<std::string,Carptr>;

void CreateObjects(Container& data);

/* check whether all instances have same gear system or not */
std::optional<bool> CheckIfAllGearAreSame(Container& data);

/* return container of instance with car type same as given parameter */
std::optional<VectorContainer> ReturnInstanceOfSameCarType(Container& data, CarType type);

/* find and return price of car whose top speed is lowest */
std::optional<float> ReturnPriceOfCarWithLowestSpeed(Container& data);

/* return count of isntances whose price is above given threshold given as 2nd parameter */
std::optional<std::size_t> ReturnCountWhosePriceIsAboveThreshold(Container& data, float price);

#endif // FUNCTIONALITIES_H
