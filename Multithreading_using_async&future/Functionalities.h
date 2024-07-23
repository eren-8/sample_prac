#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Brand.h"
#include<iostream>
#include<thread>
#include<vector>
#include<future>
#include "DataEmptyFutureException.h"
#include "InvalidInputFutureException.h"
#include<memory>

using BrandPtr = std::shared_ptr<Brand>;
using DataContainer = std::vector<BrandPtr>;
using RefContainer = std::vector<std::reference_wrapper<Car>>;
using vecContainer = std::vector<float>;
using CarContainer = std::vector<Car>;

void CreateObjects(DataContainer& data,CarContainer& car);

/* function to return container of 3 values representing brand license ergistration cost */
vecContainer ReturnBrandLicenseCost(DataContainer& data);

/* function to return car ref wrapper whose brand type is same as 2nd parameter */
RefContainer ReturnWrapperOfSameType(DataContainer& data, BrandType type);

/* function to return details of all car instane from everybrand whose price is above threshold use future?? */
void ReturnInstanceOfCar(DataContainer& data, float threshold);

/* function to print chassis detuals whose price is lowest accriss a brands */
void PrintLowestChassisDetails(DataContainer& data);

/* function to loop over all brand instance and return a boolean to indicate whether instance of car in that brand have a seatcount above 4 */
bool IfAllCarHaveSeatCountMoreThan4(DataContainer& data);



#endif // FUNCTIONALITIES_H
