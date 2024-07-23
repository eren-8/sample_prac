#include "Functionalities.h"

int main(){
    Container data {1,2,3,4,5};
    StrContainer StrData {"C++","Coding","Demo"};
    std::future<int> F1 = std::async(&SumOf3NosInContainer,std::ref(data));
    std::future<int> F2 = std::async(&MinimumOfLast3Numbers,std::ref(data));
    std::future<std::optional<Container>> F3 = std::async(&FunctionWithAllPrimeNumbersInContainer,std::ref(data));
    std::future<std::optional<Container>> F4 = std::async(&FunctionWithLambda,std::ref(data),[](int num)->bool{
    return num%7==0;});
    std::future<std::string> F5 = std::async(&ReturnMaxCharactersString,std::ref(StrData));
    std::future<std::optional<CharContainer>> F6 = std::async(&ReturnNonVowelCharacters,std::ref(StrData));

    try{
        int sumOf3 = F1.get();
        std::cout<<"Sum of first 3 numbers is: "<<sumOf3<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InvalidContainerSizeException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        int minimumOf3 = F2.get();
        std::cout<<"Minimum of last 3 numbers is: "<<minimumOf3<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
    catch(InvalidContainerSizeException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        Container primeNumbers;
        std::optional<Container> temp = F3.get();
        if(temp.has_value()){
            primeNumbers = temp.value();
        }
        std::cout<<"The Prime numbers are: ";
        for(int& num:primeNumbers){
            std::cout<<num<<" ";
        }
        std::cout<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        Container lambda;
        std::optional<Container> temp = F4.get();
        if(temp.has_value()){
            lambda = temp.value();
        }
        std::cout<<"The Prime numbers are: ";
        for(int& num:lambda){
            std::cout<<num<<" ";
        }
        std::cout<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        std::string maximumChars = F5.get();
        std::cout<<"The maximum String in Container is: "<<maximumChars<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }

    try{
        CharContainer charStr;
        std::optional<CharContainer> temporary = F6.get();
        if(temporary.has_value()){
            charStr = temporary.value();
        }
        std::cout<<"The non-vowel characters are: ";
        for(int i=0;i<charStr.size();i++){
            std::cout<<charStr[i]<<" ";
        }
        std::cout<<"\n";
    }
    catch(DataEmptyFutureException& ex){
        std::cout<<ex.what()<<"\n";
    }
}
