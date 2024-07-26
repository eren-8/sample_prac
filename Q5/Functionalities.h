#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<list>
#include "Vehicle.h"
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<functional>
#include<numeric>
#include<memory>
#include<vector>
#include "MapEmptyFutureException.h"
#include "SetEmptyFutureException.h"
#include "VehicleEmptyFutureException.h"
#include "InvalidInputException.h"


using Vptr = std::shared_ptr<Vehicle>;
using Container = std::list<std::shared_ptr<Vehicle>>;
using VContainer = std::vector<std::shared_ptr<Vehicle>>;
using PriorityQ = std::priority_queue<Vptr,VContainer,std::function<bool(const Vptr&,const Vptr&)>>;
extern std::function<bool(const Vptr&,const Vptr&)> fn;

void CreateObjects(Container& data);

/* function to return array of transmission type for last n instances */
VContainer ReturnNInstancesOfTransmissionType(Container& data, unsigned int N);

/* function to return priority queue of vehicle instances sorted according to comparator function passed as parameter */
PriorityQ  pq(VContainer& data);// std::function<bool(const Vptr&,const Vptr&)> fn

/* a function to return set of price values */
std::unordered_set<float> SetOfVehiclePrice(Container& data);

/* function to return map of n key value pairs where m_id is key and category is value. */
std::unordered_map<std::string,VehicleType> ReturnMapOfIdnCategory(Container& data);

/* function which takes list of vehicle id and returns array of corress bootspace val */
std::array<int,5> ReturnBootSpace(Container& data, std::list<std::string>& idcontainer);

/* function to accept a unary function and apply i on the boot space. the modified value must be 
erturned in ersulting vector container */
std::vector<int> ReturnModifiedValues(Container& data, std::function<int(int)> fn);

/* function to return container of all instances for how  instances value is true*/
Container ReturnContainerIfAllInstanceValueAreTrue(Container& data);


#endif // FUNCTIONALITIES_H
