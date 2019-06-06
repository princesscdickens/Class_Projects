// Place implementation

#include "Place.h"

using namespace std;
    // private:
    // //City cities[26];
    
    // City oneCity[1];
    // bool heroHasBeenHere;
    // int pointsPlace;
    // char typePlace;

    //constructor
Place::Place()
{
    heroControlsTile = false;
    pointsPlace = 0;
    typePlace = 'p';
}

Place::Place(char inputTypePlace) /** this needs to go in Game.cpp if I want to access the cities[] array */
{
    heroControlsTile = false;
    typePlace = inputTypePlace;
    if(typePlace == 'w') //water
    {
        pointsPlace = 1;
    }
    else if(typePlace == 'p') //land
    {
        pointsPlace = 2;
    }
}
    
    //setters
void Place::setHeroControlsTile(bool inputResult)
{
    heroControlsTile = inputResult;
}

void Place::setPointsPlace(int inputResult) //do only cities have points, or any random tile?
{
    pointsPlace = inputResult;
}

void Place::setTypePlace(char inputResult)
{
    typePlace = inputResult;
}

void Place::setMoneyPlace(int inputMoney)
{
    moneyPlace = inputMoney;
}

void Place::addCityObject(City cityObject) //for capital-letter City objects.
{
    if(cityObject.getLetterCity() >= 'A' && cityObject.getLetterCity() <= 'Z') //a City
    {
        oneCity[0] = cityObject; //add City object for this letter
    }
}
    
    //getters
bool Place::getHeroControlsTile()
{
    return heroControlsTile;
}

int Place::getPointsPlace() //do only cities have points, or any random tile?
{
    return pointsPlace;
}

char Place::getTypePlace()
{
    return typePlace;
}

int Place::getMoneyPlace()
{
    return moneyPlace;
}

string Place::getCityObjectName() //return name of the City object
{
    //search to see if Place IS a City. If not, return "water" or "land"
    //if a City, return the name of the City.
    if(typePlace == 'w') //water
    {
       return "water";
    }
    else if(typePlace == 'p') //land
    {
        return "land";
    }
    else if(typePlace >= 'A' && typePlace <= 'Z') //a City
    {
        return oneCity[0].getNameCity();
    }
}