#include "Functionalities.h"

void CreateObjects(DataContainer &data, CarContainer& car)
{
    // std::vector<Car> temp1;
    // std::vector<Car> temp2;
    // std::vector<Car> temp3;
    car.emplace_back(Car(4,123,123,CarType::CARBON_FIBER));
    car.emplace_back(Car(2,1,123,CarType::STEEL));
    car.emplace_back(Car(6,2,123,CarType::CARBON_FIBER));

    car.emplace_back(Car(10,3,123,CarType::CARBON_FIBER));
    car.emplace_back(Car(1,4,123,CarType::STEEL));
    car.emplace_back(Car(3,5,123,CarType::CARBON_FIBER));

    car.emplace_back(Car(100,6,123,CarType::CARBON_FIBER));
    car.emplace_back(Car(100,7,123,CarType::STEEL));
    car.emplace_back(Car(100,8,123,CarType::STEEL));
    // for(int i=0;i<3;i++){
    //     car1.emplace_back(std::ref(temp1[i]));
    // }
    // for(int i=0;i<3;i++){
    //     car2.emplace_back(std::ref(temp1[i]));
    // }
    // for(int i=0;i<3;i++){
    //     car3.emplace_back(std::ref(temp1[i]));reference_wrapperreference_wrapper
    // }
    car.push_back(Car(4,123,123,CarType::CARBON_FIBER));
    car.push_back(Car(4,123,123,CarType::CARBON_FIBER));
    car.push_back(Car(4,123,123,CarType::CARBON_FIBER));
    CarContainerRef cars {std::ref(car[0]),std::ref(car[1]),std::ref(car[2])};
    data.push_back(std::make_shared<Brand>(BrandType::CONSUMER,"toyota",cars));
    CarContainerRef cars2 {std::ref(car[3]),std::ref(car[4]),std::ref(car[5])};
    data.emplace_back(std::make_shared<Brand>(BrandType::SPECIAL_PURPOSE,"BMW",(cars2)));
    CarContainerRef cars3 {std::ref(car[6]),std::ref(car[7]),std::ref(car[8])};
    data.emplace_back(std::make_shared<Brand>(BrandType::TRANSPORT,"Mercedes",(cars3)));
}

vecContainer ReturnBrandLicenseCost(DataContainer &data)
{
    if(data.empty()){
        throw DataEmptyFutureException("data is empty!",std::future_errc::no_state);
    }
    vecContainer result;
    float cost=0;
    for(auto& brand:data){
        if(brand){
            for(auto car:brand->cars()){
                cost += car.get().price();
            }
        }
        result.push_back(cost);
    }
    return result;
}

RefContainer ReturnWrapperOfSameType(DataContainer &data, BrandType type)
{
    if(data.empty()){
        throw DataEmptyFutureException("data is empty!",std::future_errc::no_state);
    }
    RefContainer result;
    for(auto& brand:data){
        if(brand->type()==type){
            result.push_back(brand->cars()[0]);
            result.push_back(brand->cars()[1]);
            result.push_back(brand->cars()[2]);
        }
    }
    return result;
}

void ReturnInstanceOfCar(DataContainer &data,float threshold)
{
    if(data.empty()){
        throw DataEmptyFutureException("data is empty!",std::future_errc::no_state);
    }
    for(auto& brand:data){
        for(int i=0;i<3;i++){
            if(brand->cars()[i].get().price()>threshold){
                std::cout<<brand->cars()[i]<<"\n";
            }
        }
    }
}

void PrintLowestChassisDetails(DataContainer &data)
{
    if(data.empty()){
        throw DataEmptyFutureException("data is empty!",std::future_errc::no_state);
    }
    CarType result;
    float minimum = data[0]->cars()[0].get().price();
    for(auto& brand:data){
        for(int i=0;i<3;i++){
            if(brand->cars()[i].get().price()<=minimum){
                if(brand->cars()[i].get().chassis()==CarType::CARBON_FIBER){
                    result = CarType::CARBON_FIBER;
                }
                else if(brand->cars()[i].get().chassis()==CarType::STEEL){
                    result = CarType::STEEL;
                }
            }
        }
    }
    if(result==CarType::CARBON_FIBER){
        std::cout<<"CARBON FIBER\n";
    }
    else if(result==CarType::STEEL){
        std::cout<<"STEEL\n";
    }
}

bool IfAllCarHaveSeatCountMoreThan4(DataContainer &data)
{
    if(data.empty()){
        throw DataEmptyFutureException("data is empty!",std::future_errc::no_state);
    }
    int count=0;
    for(auto& brand:data){
        for(int i=0;i<3;i++){
            if(brand->cars()[i].get().seatCount()>4){
                count++;
            }
        }
    }
    if(count==3*data.size()){
            return true;
        }
        else{
            return false;
        }
}
