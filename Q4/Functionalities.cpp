#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(
        std::make_shared<ICECar>("1","BMW",610000,EngineType::DIESEL)
    );
    data.push_back(
        std::make_shared<ICECar>("2","BMW",40000,EngineType::PETROL)
    );
    data.push_back(
        std::make_shared<EvCar>("3","Mercedes",60000,EPowerType::ELECTRIC,BatteryType::LI_ON)
    );
    data.push_back(
        std::make_shared<EvCar>("4","TATA",6000,EPowerType::HYBRID,BatteryType::LI_ON)
    );
    data.push_back(
        std::make_shared<ICECar>("5","Audi",130000,EngineType::DIESEL)
    );
}

std::optional<Container> ReturnContainerWithPriceGreaterThan6L(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    Container result;
    std::for_each(data.begin(),data.end(),
    [&](const VType& v){
        std::visit([&](auto&& val){
            if(val->price()>600000){
                result.push_back(v);
            }
        },v);
    });
    if(result.empty()){
        throw std::nullopt;
    }
    return result;
}

float AverageOfAllEVcar(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    int count=0;
    float total_price = std::accumulate(data.begin(),data.end(),0.0f,
    [&](float curr_value,const VType& v){
        if(std::holds_alternative<EVCarptr>(v)){
            count++;
            return curr_value + std::get<1>(v)->price();
        }
    });
    if(total_price==0.0f){
        throw NoInstanceException("no instance match");
    }
    return static_cast<float>(total_price/count);
}

std::size_t FindCountOfSameType(Container &data, EPowerType type)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    std::size_t count = std::count_if(data.begin(),data.end(),
    [&](const VType& v){
        if(std::holds_alternative<EVCarptr>(v)){
            return std::get<1>(v)->engineType()==type;
        }
    });
    if(count==0){
        throw NoInstanceException("no instance of evcar of give type exists");
    }
    return count;
}

std::string ReturnBrandNameOfSameID(Container &data, std::string id)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    std::string name;
    for(const VType& v:data){
        std::visit([&](auto&& val){
            if(val->id()==id){
                name = val->brandName();
            }
        },v);
    }
    return name;
}

SetContainer ReturnUniqueBatteryType(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    SetContainer result;
    std::for_each(data.begin(),data.end(),
    [&](const VType& v){
        if(std::holds_alternative<EVCarptr>(v)){
            result.emplace(std::get<1>(v)->batteryType());
        }
    });
    if(result.empty()){
        throw NoInstanceException("no type available");
    }
    return result;
}

bool WhetherOnceInstanceHasPriceAbove60k(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    for(const VType& v:data){
        std::visit([&](auto&& val){
            if(val->price()>60000){
                return true;
            }
        },v);
    }
    return false;
}
