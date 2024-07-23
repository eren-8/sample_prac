#include "Operations.h"
#include<algorithm>

std::shared_ptr<Operations> Operations::_instance = nullptr;

std::shared_ptr<Operations> Operations::getInstance() {
    if (!_instance) {
        _instance = std::make_shared<Operations>();
    }
    return _instance;
}

void Operations::CreateObjects()
{
    mapper.emplace(std::make_pair<std::string,VType>("1",std::make_shared<Automobile>("1",AutomobileType::REGULAR,1000.0f,4,100)));
    m_data.push_back(std::make_shared<Automobile>("1",AutomobileType::REGULAR,1000.0f,4,100));
    m_data.push_back(std::make_shared<Automobile>("2",AutomobileType::TRANSPORT,2000.0f,5,1000));
    m_data.push_back(std::make_shared<Automobile>("3",AutomobileType::REGULAR,500.0f,3,3000));
    
    m_data.push_back(std::make_shared<EvCar>(1000.0f,EvCarType::DC,1000.0f));
    m_data.push_back(std::make_shared<EvCar>(2000.0f,EvCarType::AC,3000.0f));
}

void Operations::FindAndDisplayGstForAllEVCar()
{
    if(m_data.empty()){
        throw ContainerEmptyFutureException("data is empty!\n",std::future_errc::no_state);
    }
    for(VType& v:m_data){
        float gst=0;
        if(std::holds_alternative<EvPtr>(v)){
            std::lock_guard<std::mutex>lg(mt);
            std::cout<<"gst of evcar is: "<<std::get<0>(v)->CalculateGst()<<"\n";
        }
        else{

        }
    }
}

void Operations::FindAndDisplayCountOfSeatInAutomobile()
{
    if(m_data.empty()){
        throw ContainerEmptyFutureException("data is empty!\n",std::future_errc::no_state);
    }
    int count=0;
    // for(VType& v:m_data){
    //     if(std::holds_alternative<AutomobilePtr>(v)){
    //         if(std::get<1>(v)->seatCount()>4){
    //             count++;
    //         }
    //     }
    // }
    std::size_t countif = std::count_if(m_data.begin(),m_data.end(),
    [](const VType& data){
        if(std::holds_alternative<AutomobilePtr>(data)){
            return std::get<1>(data)->seatCount()>=4;
        }
    });
    std::lock_guard<std::mutex>lg(mt);
    std::cout<<"Count of automobiles with seat count greater than 4 is: "<<countif<<"\n";
}

void Operations::FindAndDisplayAveragePriceOfAllAutoobile()
{
    if(m_data.empty()){
        throw ContainerEmptyFutureException("data is empty!\n",std::future_errc::no_state);
    }
    int count=0;
    float sum=0.0f;
    for(VType& v:m_data){
        if(std::holds_alternative<AutomobilePtr>(v)){
            sum += std::get<1>(v)->price();
            count++;
        }
    }
    float average = static_cast<float>(sum/count);
    std::lock_guard<std::mutex>lg(mt);
    std::cout<<"average price of all automobile is: "<<average<<"\n";
}

void Operations::FindAtleastOneInstanceOfEvCarHavingDCorNot()
{
    if(m_data.empty()){
        throw ContainerEmptyFutureException("data is empty!\n",std::future_errc::no_state);
    }
    int flag=0;
    for(VType& v:m_data){
        if(std::holds_alternative<EvPtr>(v)){
            if(std::get<0>(v)->chargingType()==EvCarType::DC){
                std::lock_guard<std::mutex>lg(mt);
                std::cout<<"TRUE\n";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        std::lock_guard<std::mutex>lg(mt);
        std::cout<<"FALSE\n";
    }
}

void Operations::Print()
{
    for(auto&[k,v] : mapper){
        std::cout<<"key: "<<k<<"\n";
        std::visit([](auto&& val){std::cout<<*val<<"\n";},v);
    }
}
