#include "Functionalities.h"

int SumOf3NosInContainer(Container &data)
{
    if(data.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    if(data.size()<3){
        throw InvalidContainerSizeException("Size of Container is less than 3!",std::future_errc::no_state);
    }
    int count=0;
    int sum=0;
    for(int& num:data){
        if(count==3){
            break;
        }
        else{
            sum += num;
            count++;
        }
    }
    return sum;
}

int MinimumOfLast3Numbers(Container &data)
{
    int minimum=data[data.size()-1];
    if(data.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    if(data.size()<3){
        throw InvalidContainerSizeException("Size of Container is less than 3!",std::future_errc::no_state);
    }
    int count=0;
    for(Container::reverse_iterator itr=data.rbegin();itr!=data.rend();itr++){
        if(count==3){
            break;
        }
        else{
            if(*itr<minimum){
                minimum = *itr;
            }
            count++;
        }
    }
    return minimum;
}

std::optional<Container> FunctionWithAllPrimeNumbersInContainer(Container &data)
{
    Container result;
    if(data.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    for(int& num:data){
        int flag=1;
        if(num==1){
            continue;
        }
        for(int i=2;i<num;i++){
            if(num==2){
            result.push_back(2);
            break;
        }
            if((num%i)==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            result.push_back(num);
        }
    }
    if(result.empty()){
        throw DataEmptyFutureException("data empty",std::future_errc::no_state);
        return std::nullopt;
    }
    return result;
}

std::optional<Container> FunctionWithLambda(Container &data, std::function<bool(int)> lambda)
{
    Container result;
    if(data.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    for(int& num:data){
        if(lambda(num)){
            result.push_back(num);
        }
    }
    if(result.empty()){
        throw DataEmptyFutureException("data empty",std::future_errc::no_state);
        return  std::nullopt;
    }
    return result;
}

std::string ReturnMaxCharactersString(StrContainer &StrData)
{
    std::string maximumCharacters=StrData[0];
    if(StrData.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    for(std::string& str:StrData){
        if(maximumCharacters.size()<str.size()){
            maximumCharacters = str;
        }
    }
    return maximumCharacters;
}

std::optional<CharContainer> ReturnNonVowelCharacters(StrContainer &StrData)
{
    CharContainer result;
    if(StrData.empty()){
        throw DataEmptyFutureException("Data is empty!",std::future_errc::no_state);
    }
    for(std::string& str:StrData){
        for(int i=0;i<str.length();i++){
            if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            }
            else{
                result.push_back(str[i]);
            }
        }
    }
    if(result.empty()){
        throw DataEmptyFutureException("data empty",std::future_errc::no_state);
        return std::nullopt;
    }
    return result;

}
