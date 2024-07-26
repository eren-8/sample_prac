#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    try{
        std::optional<Container> F2 = ReturnContainerWithPriceGreaterThan6L(data);
        if(F2.has_value()){
            Container result = F2.value();
            for(const VType& v:result){
                if(std::holds_alternative<EVCarptr>(v)){
                    std::cout<<std::get<1>(v)<<"\n";
                }
                else if(std::holds_alternative<ICECarptr>(v)){
                    std::cout<<*(std::get<0>(v))<<"\n";
                }
            }
        }
        float F3 = AverageOfAllEVcar(data);
        std::cout<<"average of all ev cars are: "<<F3<<"\n";

        std::size_t count = FindCountOfSameType(data,EPowerType::ELECTRIC);
        std::cout<<"count of same type are: "<<count<<"\n";

        std::string F5 = ReturnBrandNameOfSameID(data,"1");
        std::cout<<"brand name of given id is: "<<F5<<"\n";

        SetContainer F6 = ReturnUniqueBatteryType(data);
        for(auto obj:F6){
            if(obj==BatteryType::LI_ON){
                std::cout<<"LI_ON\n";
            }
            else if(obj==BatteryType::NICAD){
                std::cout<<"NICAD\n";
            }
            else if(obj==BatteryType::OTHER){
                std::cout<<"OTHER\n";
            }
        }

        bool F7 = WhetherOnceInstanceHasPriceAbove60k(data);
        std::cout<<"Atleast one instance price have price above 60k are: "<<std::boolalpha<<F7<<"\n";

    }
    catch(VectorEmptyException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InvalidInputException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(NoInstanceException& ex){
        std::cout<<ex.what()<<"\n";
    }
}
