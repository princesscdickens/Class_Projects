// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// CITY implementation

#include "City.h"
using namespace std;
    // private:
    // char letterCity;
    // string nameCity;
    // int moneyCity;
    // int armySizeCity;
    // int pointsCity;
    
City::City()
{
    letterCity = 'A';
    nameCity = "";
    moneyCity = 0;
    armySizeCity = 0;
    pointsCity = 0;
}

City::City(char inputLetterCity, string inputNameCity, int inputMoneyCity, int inputArmySizeCity, int inputPointsCity) //bool hasBeenVisited?
{
    letterCity = inputLetterCity;
    nameCity = inputNameCity;
    moneyCity = inputMoneyCity;
    armySizeCity = inputArmySizeCity;
    pointsCity = inputPointsCity;
}

    //setters
void City::setLetterCity(char inputLetterCity)
{
    letterCity = inputLetterCity;
}

void City::setNameCity(string inputNameCity)
{
    nameCity = inputNameCity;
}
void City::setMoneyCity(int inputMoneyCity)
{
    moneyCity = inputMoneyCity;
}

void City::setArmySize(int inputArmySizeCity)
{
    armySizeCity = inputArmySizeCity;
}

void City::setPointsCity(int inputPointsCity)
{
    pointsCity = inputPointsCity;
}

    //getters
char City::getLetterCity()
{
    return letterCity;
}

string City::getNameCity()
{
    return nameCity;
}

int City::getMoneyCity()
{
    return moneyCity;
}

int City::getArmySizeCity()
{
    return armySizeCity;
}

int City::getPointsCity()
{
    return pointsCity;
}