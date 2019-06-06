// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// HERO header

#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

#include "Warrior.h"

class Hero
{
    private:
    string nameHero;
    int money;
    int influence;
    int army;
    vector<Warrior> ownedWarriors; //limit 4
    int countWarriors;
    int currentRow;
    int currentColumn;
    bool hasShipHero;
    bool hasDragonglassHero;
    
    public:
    //constructors
    Hero(); //sets default heroes
    Hero(string inputName, int inputMoney, int inputInfluence, int inputArmySize, int inputNumWarriors, bool inputHasShip); //sets NEW hero created by User
    
    //setters
    void setName(string inputNameHero);
    void setMoney(int amountMoney);
    void setInfluence(int amountInfluence);
    void setArmySize(int sizeArmy); //army of knights
    void addWarrior(Warrior warriorName);
    void setRowLocation(int inputRow);
    void setColumnLocation(int inputColumn);
    void addShip(bool inputAddShip);
    void setHasDragonglassHero(bool inputHasDragonglassHero);
    
    //getters
    string getNameHero();
    int getMoney();
    int getInfluence();
    int getArmySize();
    int getCountWarriors();
    int getRowHero();
    int getColumnHero();
    void getLocation();
    bool doesHeroHaveShip();
    bool getHasDragonglassHero();
    
    int getOwnedWarriorVectorSize();
    void setAllOwnedWarriorsStrength(int inputStrength);
    void setAllOwnedWarriorsMorale(int inputMorale);
    void setAllOwnedWarriorLoyalty(int inputLoyalty);
    int getFirstWarriorsMorale();
    int getFirstWarriorsLoyalty();
    string getOwnedWarriorName(int OwnedWarriorIndex);
    Warrior getOwnedWarriorObject(int OwnedWarriorIndex);
    void addOwnedWarrior(Warrior warriorObject);
    void deleteOwnedWarrior(int warriorIndex);
    int getChosenWarriorStrength(int warriorIndex);
    bool getDoesAnyOwnedWarriorHaveShip();
    void setAllOwnedWarriorLocations();
    double getPowerScore();
    //int getFirstWarriorLoyalty();
    
    //other functions
};
#endif
