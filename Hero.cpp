// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// HERO implementation

#include "Hero.h"

using namespace std;
// private:
//     string nameHero;
//     int money;
//     int influence;
//     int army;
//     bool hasShip;
//     int countWarriors
//     vector<Warrior> ownedWarriors; //limit 4
//     int currentRow;
//     int currentColumn;
//     bool hasDragonglassHero;
    
//constructors
Hero::Hero() //sets default heroes
{
    nameHero = "";
    money = 0;
    influence = 0;
    army = 0;
    // add condition to keep Hero away from Water tile when Hero has NO ship
    
    hasShipHero = false;
    countWarriors = 0;
    hasDragonglassHero = false;
}
// parameterized
Hero::Hero(string inputName, int inputMoney, int inputInfluence, int inputArmySize, int inputNumWarriors, bool inputHasShip) //sets NEW hero created by User //sets NEW hero created by User
{
    nameHero = inputName;
    money = inputMoney;
    influence = inputInfluence;
    army = inputArmySize;
    countWarriors = inputNumWarriors;
    hasShipHero = inputHasShip;
    // add default row and column
    currentRow = 12;
    currentColumn = 7;
    hasDragonglassHero = false;
}
    
    //setters
void Hero::setName(string inputNameHero)
{
    nameHero = inputNameHero;
}

void Hero::setMoney(int amountMoney)
{
    money = money + amountMoney;
}

void Hero::setInfluence(int amountInfluence)
{
    influence = influence + amountInfluence;
}

void Hero::setArmySize(int sizeArmy) //army of knights
{
    army = army + sizeArmy;
}

void Hero::addWarrior(Warrior warriorName)
{
    //vector<Warrior> ownedWarriors;
    if(countWarriors < 4)
    {
        warriorName.setIsFree(false);
        ownedWarriors.push_back(warriorName); //add a warrior
        //cout << "Your Grace has acquired the noble warrior, " << ownedWarriors[countWarriors].getName() << endl;
        countWarriors++;
        
        //problem here!!
    }
    else
    {
        cout << "Max number of Warriors reached." << endl;
    }
}

void Hero::setRowLocation(int inputCurrentRow)
{
    //add condition for if this coordinate would lead to water with NO ship
    
    if(inputCurrentRow < 0 || inputCurrentRow > 25)
    {
        cout << "Invalid latitude" << endl;
    }
    else if(inputCurrentRow > 0 && inputCurrentRow < 26)
    {
        currentRow = inputCurrentRow;
    }
}

void Hero::setColumnLocation(int inputCurrentColumn)
{
    //add condition for if this coordinate would lead to water with NO ship
    
    if(inputCurrentColumn < 0 || inputCurrentColumn > 16)
    {
        cout << "Invalid longitude" << endl;
    }
    else if(inputCurrentColumn > 0 && inputCurrentColumn < 17)
    {
        currentColumn = inputCurrentColumn;
    }
}

void Hero::addShip(bool inputHasShip)
{
    hasShipHero = inputHasShip;
}
    
void Hero::setHasDragonglassHero(bool inputHasDragonglassHero)
{
    hasDragonglassHero = inputHasDragonglassHero;
}
    
    //getters
string Hero::getNameHero()
{
    return nameHero;
}

int Hero::getMoney()
{
    return money;
}

int Hero::getInfluence()
{
    return influence;
}

int Hero::getArmySize()
{
    return army;
}

int Hero::getCountWarriors()
{
    return countWarriors;
}

int Hero::getRowHero()
{
    return currentRow;
}

int Hero::getColumnHero()
{
    return currentColumn;
}

void Hero::getLocation()
{
    cout << "Current coordinates are: (" << currentRow << ", " << currentColumn << ")" << endl;
}

bool Hero::doesHeroHaveShip()
{
    return hasShipHero;
}

bool Hero::getHasDragonglassHero()
{
    return hasDragonglassHero;
}

int Hero::getOwnedWarriorVectorSize()
{
    return ownedWarriors.size();
}

void Hero::setAllOwnedWarriorsStrength(int inputStrength)
{
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        ownedWarriors[i].setStrength(inputStrength);
    }
}

void Hero::setAllOwnedWarriorsMorale(int inputMorale)
{
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        ownedWarriors[i].setMorale(inputMorale);
    }
}

void Hero::setAllOwnedWarriorLoyalty(int inputLoyalty)
{
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        ownedWarriors[i].setLoyalty(inputLoyalty);
    }
}

int Hero::getFirstWarriorsMorale()
{
    if(ownedWarriors.size() > 0)
    {
        return ownedWarriors[0].getMorale();
    }
}

int Hero::getFirstWarriorsLoyalty()
{
    if(ownedWarriors.size() > 0)
    {
        return ownedWarriors[0].getLoyalty();
    }
}

string Hero::getOwnedWarriorName(int OwnedWarriorIndex)
{
    return ownedWarriors[OwnedWarriorIndex].getName();
}

Warrior Hero::getOwnedWarriorObject(int OwnedWarriorIndex)
{
    return ownedWarriors[OwnedWarriorIndex];
}

void Hero::addOwnedWarrior(Warrior warriorObject) 
{
    warriorObject.setIsFree(false);
    if(ownedWarriors.size() < 4)
    {
        ownedWarriors.push_back(warriorObject);
        //cout << "Your Grace has acquired Warrior " << warriorObject.getName() << endl;
    }
}

void Hero::deleteOwnedWarrior(int warriorIndex)
{
    ownedWarriors.erase(ownedWarriors.begin() + warriorIndex);
}

int Hero::getChosenWarriorStrength(int warriorIndex)
{
    return ownedWarriors[warriorIndex].getStrength();
}

bool Hero::getDoesAnyOwnedWarriorHaveShip()
{
    bool atLeastOneShip = false;
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        if(ownedWarriors[i].doesWarriorHaveShip() == true)
        {
            atLeastOneShip = true;
        }
    }
    return atLeastOneShip;
}

void Hero::setAllOwnedWarriorLocations()
{
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        ownedWarriors[i].setRowWarrior(currentRow);
        ownedWarriors[i].setColumnWarrior(currentColumn);
    }
}

double Hero::getPowerScore()
{
    double powerScore = army;
    for(int i = 0; i < ownedWarriors.size(); i++)
    {
        powerScore = powerScore + (ownedWarriors[i].getStrength() * (ownedWarriors[i].getMorale() / 50));
    }
    return powerScore;
}

