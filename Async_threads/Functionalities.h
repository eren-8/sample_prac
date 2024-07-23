#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include<functional>
#include<thread>
#include<optional>
#include "DataEmptyFutureException.h"
#include<future>
#include "InvalidContainerSizeException.h"


using Container = std::vector<int>;
using StrContainer = std::vector<std::string>;
using CharContainer =std::vector<char>;

/* a function that returns sum of first 3 numbers in container */
int SumOf3NosInContainer(Container& data);

/* a function that returns minimum of last 3 numbers in conatiner */
int MinimumOfLast3Numbers(Container& data);

/* a function that returns container of all prime numbers in container */
std::optional<Container> FunctionWithAllPrimeNumbersInContainer(Container& data);

/* a funcntion that accepts container and predicate lambda function. returns container which passes the lambda */
std::optional<Container> FunctionWithLambda(Container& data,std::function<bool(int)>lambda);

/* function to accept container of strings and return the string with max amount of characters frmo the input */
std::string ReturnMaxCharactersString(StrContainer& StrData);

/* function that accepts container of strings and returns a container of non-vowel chars from input */
std::optional<CharContainer> ReturnNonVowelCharacters(StrContainer& StrData);

#endif // FUNCTIONALITIES_H
