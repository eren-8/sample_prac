#include "Functionalities.h"

bool comparator(const Vptr& v1, const Vptr& v2){
    return v1->vehiclePrice() < v2->vehiclePrice();
}

std::function<bool(const Vptr&,const Vptr&)> fn = [](const Vptr& v1,const Vptr& v2)->bool{
    return v1->vehiclePrice() < v2->vehiclePrice();
};

void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<Vehicle>("1",1000.0f,VehicleType::GOVT,TransmissionType::AMT,100,true)
    );
    data.emplace_back(
        std::make_shared<Vehicle>("2",2000.0f,VehicleType::PUBLIC,TransmissionType::MANUAL,200,true)
    );
    data.emplace_back(
        std::make_shared<Vehicle>("3",3000.0f,VehicleType::PRIVATE,TransmissionType::AUTOMATIC,300,true)
    );
    data.emplace_back(
        std::make_shared<Vehicle>("4",4000.0f,VehicleType::PUBLIC,TransmissionType::AUTOMATIC,50,false)
    );
    data.emplace_back(
        std::make_shared<Vehicle>("5",5000.0f,VehicleType::GOVT,TransmissionType::AMT,100,true)
    );
}

VContainer ReturnNInstancesOfTransmissionType(Container &data, unsigned int N)
{
    if(data.empty()){
        throw VehicleEmptyFutureException("data is empty",std::future_errc::no_state);
    }
    if(N<0 || N>data.size()){
        throw InvalidInputException("input value is invalid",std::future_errc::no_state);
    }

    VContainer result;
    int count=0;
    for(Container::reverse_iterator itr=data.rbegin();itr!=data.rend();itr++){
        if(count==N){
            break;
        }
        else{
            result.push_back(*itr);
            count++;
        }
    }
    return result;
}

PriorityQ pq(VContainer& data)//std::function<bool(const Vptr&,const Vptr&)>& fn
{
    // std::priority_queue<Vptr,std::list<Vptr>,decltype(fn)> p()
    std::priority_queue<Vptr,VContainer,decltype(fn)> p(fn);
    for(const Vptr& obj:data){
        p.emplace(obj);
    }
    return p;
}

std::unordered_set<float> SetOfVehiclePrice(Container &data)
{
    if(data.empty()){
        throw VehicleEmptyFutureException("data is empty",std::future_errc::no_state);
    }
    std::unordered_set<float> result;
    for(auto obj:data){
        result.emplace(obj->vehiclePrice());
    }
    if(result.empty()){
        throw SetEmptyFutureException("set is empty",std::future_errc::no_state);
    }
    return result;
}

std::unordered_map<std::string, VehicleType> ReturnMapOfIdnCategory(Container &data)
{
    if(data.empty()){
        throw VehicleEmptyFutureException("data is empty",std::future_errc::no_state);
    }

    std::unordered_map<std::string, VehicleType> result;
    for(auto obj:data){
        result.emplace(std::make_pair<std::string,VehicleType>(obj->vehicleId(),obj->vehicleCategory()));
    }
    if(result.empty()){
        throw MapEmptyFutureException("map is empty",std::future_errc::no_state);
    }
    return result;
}

std::array<int, 5> ReturnBootSpace(Container &data, std::list<std::string> &idcontainer)
{
    std::array<int, 5> result;
    int i=0;
    for(auto obj:data){
        for(auto val:idcontainer){
            if(val==obj->vehicleId() && i<5){
                result[i] = obj->bootSpace();
                i++;
            }
        }
    }
    return result;
}

std::vector<int> ReturnModifiedValues(Container &data, std::function<int(int)> fn)
{
    std::vector<int> result;
    for(auto obj:data){
        int temp = fn(obj->bootSpace());
        obj->setBootSpace(temp);
        result.push_back(obj->bootSpace());
    }
    return result;
}

Container ReturnContainerIfAllInstanceValueAreTrue(Container &data)
{
    Container result;
    for(auto obj:data){
        if(obj->isVehicleInsured()==true){
            result.push_back(obj);
        }
    }
    return result;
}
