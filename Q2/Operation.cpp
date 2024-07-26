#include "Operation.h"

std::shared_ptr<Operation> Operation::_instance = nullptr;

std::shared_ptr<Operation> Operation::getInstance() {
    if (!_instance) {
        _instance = std::make_shared<Operation>();
    }
    return _instance;
}

void Operation::CreateObjects()
{
    m_engine.push_back(Engine("E1",156,400,EngineType::CRDI));
    m_engine.push_back(Engine("E2",200,200,EngineType::MPFI));
    m_engine.push_back(Engine("E3",300,400,EngineType::TURBOCHARGED));
    m_engine.push_back(Engine("E4",326,500,EngineType::CRDI));
    m_engine.push_back(Engine("E5",120,100,EngineType::MPFI));

    m_data.push_back(std::make_shared<Car>("1",1000.0f,std::ref(m_engine[0])));
    m_data.push_back(std::make_shared<Car>("2",2000.0f,std::ref(m_engine[1])));
    m_data.push_back(std::make_shared<Car>("3",3000.0f,std::ref(m_engine[2])));
    m_data.push_back(std::make_shared<Car>("4",4000.0f,std::ref(m_engine[3])));
    m_data.push_back(std::make_shared<Car>("5",5000.0f,std::ref(m_engine[4])));
}

std::optional<RefContainer> Operation::ReturnEngineReference()
{
    if(m_data.empty()){
        throw std::nullopt;
    }
    RefContainer result;
    std::for_each(m_data.begin(),m_data.end(),
    [&](const Carptr& obj){
        result.push_back(obj->carEngine());
    });
    if(result.empty()){
        throw std::nullopt;
    }
    return result;
}

std::optional<bool> Operation::ReturnIfTorqueAbove120()
{
    if(m_data.empty()){
        throw std::nullopt;
    }
    bool answer =std::all_of(m_data.begin(),m_data.end(),
    [](const Carptr& obj){
        return obj->carEngine().get().engineTorque()>=120;
    });
    return answer;
}

std::optional<float> Operation::ReturnAverageHorsePowerWithinThreshold(float price)
{
    if(m_data.empty()){
        throw std::nullopt;
    }
    int count=0;
    float average = std::accumulate(m_data.begin(),m_data.end(),0.0f,
    [&](float curr_value,const Carptr& obj){
        if(obj->price()>price){
            count++;
            return curr_value + obj->carEngine().get().horsepower();
        }
    });
    if(count==0){
        throw std::nullopt;
    }
    return static_cast<float>(average/count);
}

std::optional<EngineType> Operation::ReturnTypeOfSameRegNum(std::string number)
{
    if(m_data.empty()){
        throw std::nullopt;
    }
    EngineType type;
    auto itr = std::find_if(m_data.begin(),m_data.end(),
    [&](const Carptr& obj){
        return obj->carRegNum()==number;
    });
    type = (*itr)->carEngine().get().engineType();
    return type;
}

std::optional<std::reference_wrapper<Engine>> Operation::ReturnEngineInstanceOfHighestTorque()
{
    if(m_data.empty()){
        throw std::nullopt;
    }
    auto itr = std::max_element(m_data.begin(),m_data.end(),
    [](const Carptr& c1, const Carptr& c2){
        return c1->carEngine().get().engineTorque() < c2->carEngine().get().engineTorque();
    });
    if(itr==m_data.end()){
        throw std::nullopt;
    }
    return (*itr)->carEngine();
}
