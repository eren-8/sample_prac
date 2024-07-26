#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace(
        MapEntry("1",std::make_shared<CarUnit>("BMW",1000.0f,CarType::SUV,200,120,CarGearSystem::PRNDL))
    );
    data.emplace(
        MapEntry("2",std::make_shared<CarUnit>("TOYOTA",2000.0f,CarType::SEDAN,300,100,CarGearSystem::CLASSIC))
    );
    data.emplace(
        MapEntry("3",std::make_shared<CarUnit>("MERCEDES",3000.0f,CarType::HATCHBACK,400,105,CarGearSystem::TIPTRONIC))
    );
    data.emplace(
        MapEntry("4",std::make_shared<CarUnit>("MAHINDRA",4000.0f,CarType::HATCHBACK,2000,125,CarGearSystem::PRNDL))
    );
    data.emplace(
        MapEntry("5",std::make_shared<CarUnit>("BMW",5000.0f,CarType::SUV,1500,150,CarGearSystem::TIPTRONIC))
    );
}

std::optional<bool> CheckIfAllGearAreSame(Container &data)
{
    if(data.empty()){
        throw std::nullopt;
    }
    CarGearSystem type = (*data.begin()).second->carGearSystem();

    bool answer = std::all_of(data.begin(),data.end(),
    [&](const MapEntry& mp){
        return mp.second->carGearSystem()==type;
    });
    return answer;
}

std::optional<VectorContainer> ReturnInstanceOfSameCarType(Container &data, CarType type)
{
    if(data.empty()){
        throw std::nullopt;
    }
    VectorContainer result;
    std::for_each(data.begin(),data.end(),
    [&](const MapEntry& mp){
        if(mp.second->carType()==type){
            result.push_back(mp.second);
        }
    });
    if(result.empty()){
        throw std::nullopt;
    }
    return result;
}

std::optional<float> ReturnPriceOfCarWithLowestSpeed(Container &data)
{
    if(data.empty()){
        throw std::nullopt;
    }
    auto itr = std::min_element(data.begin(),data.end(),
    [&](const MapEntry& mp1, const MapEntry& mp2){
        return mp1.second->carTopSpeed() < mp2.second->carTopSpeed();
    });
    if(itr==data.end()){
        throw std::nullopt;
    }
    return (*itr).second->carPrice();
}

std::optional<std::size_t> ReturnCountWhosePriceIsAboveThreshold(Container &data, float price)
{
    if(data.empty()){
        throw std::nullopt;
    }
    std::size_t count = std::count_if(data.begin(),data.end(),
    [&](const MapEntry& mp){
        return mp.second->carPrice()>price;
    });
    if(count==0){
        throw std::nullopt;
    }
    return count;
}
