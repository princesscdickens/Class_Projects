// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// CITY header

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class City
{
    private:
    char letterCity;
    string nameCity;
    int moneyCity;
    int armySizeCity;
    int pointsCity;
    
    public:
    //constructor
    City();
    City(char inputLetterCity, string inputNameCity, int inputMoneyCity, int inputArmySizeCity, int inputPointsCity); //bool hasBeenVisited?
    
    //setters
    void setLetterCity(char inputLetterCity);
    void setNameCity(string inputNameCity);
    void setMoneyCity(int inputMoneyCity);
    void setArmySize(int inputArmySizeCity);
    void setPointsCity(int inputPointsCity);
    
    //getters
    char getLetterCity();
    string getNameCity();
    int getMoneyCity();
    int getArmySizeCity();
    int getPointsCity();
};
#endif