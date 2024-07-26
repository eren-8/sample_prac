#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<variant>
#include<iostream>
#include<memory>
#include<numeric>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<optional>
#include "ICECar.h"
#include "NoInstanceException.h"
#include "EvCar.h"
#include "VectorEmptyException.h"
#include "InvalidInputException.h"

using ICECarptr = std::shared_ptr<ICECar>;
using EVCarptr = std::shared_ptr<EvCar>;
using VType = std::variant<ICECarptr,EVCarptr>;
using Container = std::vector<VType>;
using SetContainer = std::unordered_set<BatteryType>;

void CreateObjects(Container& data);

/* return container of ice and ev with price greater than 6,00,000 */
std::optional<Container> ReturnContainerWithPriceGreaterThan6L(Container& data);

/* function to calculate and return average price of all EVCAR */
float AverageOfAllEVcar(Container& data);

/* find and return count of evcar with engine type matching 2nd argument ONLY CONSIDER EVCAR */
std::size_t FindCountOfSameType(Container& data, EPowerType type);

/* find and return brand name whose id is same as 2nd parameter */
std::string ReturnBrandNameOfSameID(Container& data, std::string id);

/* function to return containre of unique battery type */
SetContainer ReturnUniqueBatteryType(Container& data);

/* return a boolean whether atleast one isntance have price above 60k */
bool WhetherOnceInstanceHasPriceAbove60k(Container& data);

#endif // FUNCTIONALITIES_H
