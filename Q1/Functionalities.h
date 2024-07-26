#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "EvCar.h"
#include<iostream>
#include<array>
#include<memory>
#include<functional>
#include<list>
#include<vector>
#include<optional>
#include<algorithm>
#include "VectorEmptyException.h"
#include "InvalidDataException.h"

using Evptr = std::shared_ptr<EvCar>;
using DataContainer = std::vector<Evptr>;
using Container = std::array<Evptr,5>;


/* create 5 instances of object in heap in contiguous memory locations */
void CreateObjects(Container& data);

/* function to find and return list of first N instances from input. */
std::list<Evptr> FindNInstaces(Container& data, unsigned int N);

/* find and return count of instnaces with chassis length above 2.7f */
std::size_t FindCountOfChassisLengthAboveThreshold(Container& data);

/* function to return top speed whose id is passed as parameter */
int ReturnTopSpeedById(Container& data, std::string id);

/* function to return a container which satisfy the predicate */
std::optional<DataContainer> ReturnContainerBasedOnLambda(Container& data,std::function<bool(const Evptr&)>fn);

/* function to return bool to indicate atleast 1 input has pure_ev */
bool AtleastOnePureEv(Container& data);

#endif // FUNCTIONALITIES_H
