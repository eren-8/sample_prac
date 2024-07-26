#include "Functionalities.h"



void CreateObjects(Container &data)
{
    data[0] = std::make_shared<EvCar>("1",45,EvCarType::IC_BASED,2.0f,4,145);
    data[1] = std::make_shared<EvCar>("2",85,EvCarType::PURE_EV,3.0f,6,100);
    data[2] = std::make_shared<EvCar>("3",95,EvCarType::IC_BASED,4.0f,4,145);
    data[3] = std::make_shared<EvCar>("4",60,EvCarType::PURE_EV,5.0f,6,140);
    data[4] = std::make_shared<EvCar>("5",88,EvCarType::IC_BASED,1.0f,3,105);
}

std::list<Evptr> FindNInstaces(Container &data, unsigned int N)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    if(N<=0 || N>data.size()){
        throw InvalidDataException("value of N is invalid");
    }
    std::list<Evptr> result;
    std::copy_n(data.begin(),N,
    std::inserter(result,result.begin()));
    return result;
}

std::size_t FindCountOfChassisLengthAboveThreshold(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }

    std::size_t count = std::count_if(data.begin(),data.end(),
    [](const Evptr& obj){
        return obj->chassisLength()>2.7f;
    });
    return count;
}

int ReturnTopSpeedById(Container &data, std::string id)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    int topspeed=data[0]->topSpeed();
    for(auto obj:data){
        if(obj->carId()==id){
            topspeed=obj->topSpeed();
        }
    }
    return topspeed;

}

std::optional<DataContainer> ReturnContainerBasedOnLambda(Container &data, std::function<bool(const Evptr&)>fn)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    DataContainer result;
    int i=0;
    for(const Evptr& obj:data){
        if(fn(obj)&&i<=data.size()){
            result.push_back(obj);
        }
    }
    if(result.empty()){
        throw std::nullopt;
    }
    return result;
}

bool AtleastOnePureEv(Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("data is empty");
    }
    bool answer = std::any_of(data.begin(),data.end(),
    [](const Evptr& obj){
        return obj->type()==EvCarType::PURE_EV;
    });
    return answer;
}
