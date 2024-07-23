#include "Functionalities.h"

int main(){
    DataContainer data;
    CarContainer car;
    CreateObjects(data, car);
    
    std::future<vecContainer> F2 = std::async(&ReturnBrandLicenseCost,std::ref(data));
    std::future<RefContainer> F3 = std::async(&ReturnWrapperOfSameType,std::ref(data),BrandType::CONSUMER);
    std::future<bool> F6 = std::async(&IfAllCarHaveSeatCountMoreThan4,std::ref(data));
    try{
    vecContainer f2=F2.get();
    for(auto obj:f2){
        std::cout<<"registeration cost of 3 brand licence "<<obj<<"\n";
    }
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    std::cout<<"********************************************************************************\n";
    try{
    RefContainer f3 = F3.get();
    for(auto obj:f3){
        std::cout<<"wapper of same type are: "<<obj.get()<<"\n";
    }
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    std::cout<<"********************************************************************************\n";
    try{
        std::cout<<"return instance of car: \n";
        std::future<void> F4 = std::async(&ReturnInstanceOfCar,std::ref(data),100);
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    std::cout<<"********************************************************************************\n";
    try{
        std::cout<<"Lowest chassis details are:  \n";
        std::future<void> F5 = std::async(&PrintLowestChassisDetails,std::ref(data));
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    std::cout<<"********************************************************************************\n";
    try{
    bool f6 = F6.get();
    std::cout<<"if all car have seat count more than 4: "<<std::boolalpha<<f6<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    std::cout<<"********************************************************************************\n";
}