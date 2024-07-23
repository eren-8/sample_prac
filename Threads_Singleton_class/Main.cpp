#include "Operations.h"
#include<thread>
#include<chrono>

int main(){
    std::shared_ptr<Operations> ptr = Operations::getInstance();
    ptr->CreateObjects();
    ptr->FindAndDisplayCountOfSeatInAutomobile();
    std::thread t2(&Operations::FindAndDisplayGstForAllEVCar,ptr);
    std::thread t3(&Operations::FindAndDisplayCountOfSeatInAutomobile,ptr);
    std::thread t4(&Operations::FindAndDisplayAveragePriceOfAllAutoobile,ptr);
    std::thread t5(&Operations::FindAtleastOneInstanceOfEvCarHavingDCorNot,ptr);

    try{
        if(t2.joinable()){
            t2.join();
        }
    }
    catch(ContainerEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        if(t3.joinable()){
            t3.join();
        }
    }
    catch(ContainerEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        if(t4.joinable()){
            t4.join();
        }
    }
    catch(ContainerEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    try{
        if(t5.joinable()){
            t5.join();
        }
    }
    catch(ContainerEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
}
