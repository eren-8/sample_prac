#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    std::list<std::string> idcontainer = {"1","2","3"};
    auto fn = [](const Vptr& v1,const Vptr& v2)->bool{
        return v1->vehiclePrice() < v1->vehiclePrice();
    };
    VContainer vdata;
    for(auto i:data){
        vdata.push_back(i);
    }
    std::future<VContainer> F2 = std::async(std::launch::async,&ReturnNInstancesOfTransmissionType,std::ref(data),3);
    std::future<std::unordered_set<float>> F3 = std::async(std::launch::async,&SetOfVehiclePrice,std::ref(data));
    std::future<std::unordered_map<std::string,VehicleType>> F4 = std::async(std::launch::async,&ReturnMapOfIdnCategory,std::ref(data));
    std::future<std::array<int,5>> F5 = std::async(std::launch::async,&ReturnBootSpace,std::ref(data),std::ref(idcontainer));
    std::future<Container> F6 = std::async(std::launch::async,&ReturnContainerIfAllInstanceValueAreTrue,std::ref(data));
    std::future<std::vector<int>> F7 = std::async(std::launch::async, &ReturnModifiedValues,std::ref(data),[](int a){return a/10;});
    std::future<PriorityQ> F8 = std::async(std::launch::async,&pq,std::ref(vdata));


    try{
        std::vector<int> result = F7.get();
        for(int obj:result){
            std::cout<<obj<<" ";
        }
        std::cout<<"\n";
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        VContainer result = F2.get();
        for(auto obj:result){
            std::cout<<*obj<<"\n";
        }
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        std::unordered_set<float> result = F3.get();
        for(auto obj:result){
            std::cout<<obj<<"\n";
        }
    }
    catch(SetEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        std::array<int,5> result = F5.get();
        for(auto obj:result){
            std::cout<<obj<<"\n";
        }
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        std::unordered_map<std::string,VehicleType> result = F4.get();
        for(auto& [k,v] : result){
            std::cout<<"key: "<<k<<" "<<"value: ";
            if(v==VehicleType::GOVT){
                std::cout<<"GOVT\n";
            }
            if(v==VehicleType::PUBLIC){
                std::cout<<"PUBLIC\n";
            }
            else if(v==VehicleType::PRIVATE){
                std::cout<<"PRIVATE\n";
            }
        }
    }
    catch(MapEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        Container result = F6.get();
        for(auto obj:result){
            std::cout<<*obj<<"\n";
        }
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        PriorityQ result = F8.get();
        std::cout<<"top element of queue is: "<<*result.top()<<"\n";
    }
    catch(VehicleEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

}
