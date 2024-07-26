#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    try{
        std::list Ninstances = FindNInstaces(data,3);
        std::cout<<"data of first N instances is: "<<"\n";
        for(auto obj:Ninstances){
            std::cout<<*obj<<"\n";
        }

        std::size_t count = FindCountOfChassisLengthAboveThreshold(data);
        std::cout<<"count of instances having threshold above 2.7 is: "<<count<<"\n";

        int top_speed = ReturnTopSpeedById(data,"2");
        std::cout<<"top speed of given id is: "<<top_speed<<"\n";


        bool answer = AtleastOnePureEv(data);
        std::cout<<"atleast one instance is of type PURE_EV is: "<<std::boolalpha<<answer<<"\n";

        auto fn = [](const Evptr& obj){
            return obj->topSpeed()<120;};
        std::optional<DataContainer> result = ReturnContainerBasedOnLambda(data,fn);
        if(result.has_value()){
            DataContainer ans=result.value();
            for(auto obj:ans){
                std::cout<<*obj<<"\n";
            }
        }
        else{
            throw VectorEmptyException("resultant is empty!");
        }

    }

    catch(VectorEmptyException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InvalidDataException& ex){
        std::cout<<ex.what()<<"\n";
    }
}
