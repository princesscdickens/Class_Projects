// Place header

#ifndef PLACE_H
#define PLACE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

#include "City.h"

using namespace std;

class Place // = Tile. There are 400 in the game --> [25][16]
{
    private:
    //City cities[26];
    City oneCity[1];
    bool heroControlsTile;
    int pointsPlace;
    int moneyPlace;
    char typePlace;
    
    public:
    //constructor
    Place();
    Place(char inputTypePlace);
    
    //setters
    void setHeroControlsTile(bool inputResult);
    void setPointsPlace(int inputResult); //water = 1 point, land = 2 points, City = 3-30 points
    void setTypePlace(char inputResult);
    void setMoneyPlace(int inputMoney);
    void addCityObject(City cityObject); //for capital-letter City objects.
    
    //getters
    bool getHeroControlsTile();
    int getPointsPlace(); 
    char getTypePlace();
    int getMoneyPlace();
    string getCityObjectName(); //return name of the City object, if there is a City object
};

#endif