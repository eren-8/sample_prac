#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);

    std::optional<bool> F2 = CheckIfAllGearAreSame(data);
    if(F2.has_value()){
        bool f2 = F2.value();
        std::cout<<"all gear of all instance are same is: "<<std::boolalpha<<f2<<"\n";
    }

    std::optional<VectorContainer> F3 = ReturnInstanceOfSameCarType(data,CarType::HATCHBACK);
    if(F3.has_value()){
        VectorContainer result = F3.value();
        std::cout<<"instance of car which has same type are: \n";
        for(auto i:result){
            std::cout<<*i<<"\n";
        }
    }

    std::optional<float> F4 = ReturnPriceOfCarWithLowestSpeed(data);
    if(F4.has_value()){
        float price = F4.value();
        std::cout<<"price of car with lowest speed is: "<<price<<"\n";
    }
    std::optional<std::size_t> F5 = ReturnCountWhosePriceIsAboveThreshold(data,3000);
    if(F5.has_value()){
        std::size_t count = F5.value();
        std::cout<<"count of cars that have price greater than given threshold is: "<<count<<"\n";
    }

}