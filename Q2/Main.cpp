#include "Operation.h"

#include<future>
#include<thread>

int main(){
    std::shared_ptr<Operation> ptr = Operation::getInstance();
    ptr->CreateObjects();

    std::future<std::optional<RefContainer>> F2 = std::async(std::launch::async,&Operation::ReturnEngineReference,ptr);
    std::future<std::optional<bool>> F3 = std::async(std::launch::async,&Operation::ReturnIfTorqueAbove120,ptr);
    std::future<std::optional<float>> F4 = std::async(std::launch::async,&Operation::ReturnAverageHorsePowerWithinThreshold,ptr,4000);
    std::future<std::optional<EngineType>> F5 = std::async(std::launch::async,&Operation::ReturnTypeOfSameRegNum,ptr,"3");
    std::future<std::optional<std::reference_wrapper<Engine>>> F6 = std::async(std::launch::async,&Operation::ReturnEngineInstanceOfHighestTorque,ptr);

    std::optional<RefContainer> f2 = F2.get();
    if(f2.has_value()){
        RefContainer result = f2.value();
        for(auto i:result){
            std::cout<<i<<"\n";
        }
    }
    
    std::optional<bool> f3 = F3.get();
    if(f3.has_value()){
        bool answer =f3.value();
        std::cout<<"all instance of torque are above 120 is: "<<std::boolalpha<<answer<<"\n";
    }

    std::optional<float> f4 = F4.get();
    if(f4.has_value()){
        float answer =f4.value();
        std::cout<<"average is: "<<answer<<"\n";
    }

    std::optional<EngineType> f5 = F5.get();
    if(f5.has_value()){
        EngineType type = f5.value();
        if(type==EngineType::CRDI){
            std::cout<<"type is CRDI\n";
        }
        else if(type==EngineType::MPFI){
            std::cout<<"type is MPFI\n";
        }
        else if(type==EngineType::TURBOCHARGED){
            std::cout<<"type is TURBOCHARGED\n";
        }
    }

    std::optional<std::reference_wrapper<Engine>> f6 = F6.get();
    if(f6.has_value()){
        std::reference_wrapper<Engine> answer = f6.value();
        std::cout<<"instance of engine with hoghest torque is: "<<"\n";
        std::cout<<answer<<"\n";
    }

}