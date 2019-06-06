// CS1300 Spring 2019
// Author: Princess Dickens
// Recitation: 207 - Shipra Behera
// Cloud9 Workspace Editor Link: https://ide.c9.io/pdickens/csci1300_pdickens
// Project 3

// WARRIOR implementation

#include "Warrior.h"
using namespace std;
    // private:
    // string nameWarrior;
    // int strength;
    // int loyalty;
    // int morale;
    // bool isFree;
    // bool hasShipWarrior;
    // bool hasDragonglass;
    // int rowWarrior;
    // int columnWarrior;
    
Warrior::Warrior()
{
    string nameWarrior = "";
    int strength = 0;
    int loyalty = 0;
    int morale = 0;
    bool isFree = true;
    bool hasShipWarrior = false;
    bool hasDragonglass = false;
    int rowWarrior = 0;
    int columnWarrior = 0;
    // initialize location to land
}

Warrior::Warrior(string inputNameWarrior, int inputStrength, int inputLoyalty, int inputMorale, bool inputIsFree, bool inputHasShipWarrior, bool inputHasDragonglass)
{
    string nameWarrior = inputNameWarrior;
    int strength = inputStrength;
    int loyalty = inputLoyalty;
    int morale = inputMorale;
    bool isFree = inputIsFree;
    bool hasShipWarrior = inputHasShipWarrior;
    bool hasDragonglass = inputHasDragonglass;
    int rowWarrior = 0;
    int columnWarrior = 0;
    //initialize random land location 
}
    //setters
void Warrior::setNameWarrior(string inputNameWarrior)
{
    nameWarrior = inputNameWarrior;
}

void Warrior::setStrength(int inputStrength)
{
    strength = inputStrength;
}

void Warrior::setLoyalty(int inputLoyalty)
{
    loyalty = inputLoyalty;
}

void Warrior::setMorale(int inputMorale)
{
    morale = inputMorale;
}

void Warrior::setIsFree(bool inputIsFree)
{
    if(inputIsFree == true)
    {
        isFree = true;
    }
    else
    {
        isFree = false;
    }
}

void Warrior::addShipWarrior(bool inputHasShipWarrior)
{
    if(inputHasShipWarrior == true)
    {
        hasShipWarrior = true;
    }
    else
    {
        hasShipWarrior = false;
    }
}

void Warrior::addDragonglass(bool inputHasDragonglass)
{
    if(inputHasDragonglass == true)
    {
        hasDragonglass = true;
    }
    else
    {
        hasDragonglass = false;
    }
} 

void Warrior::setRowWarrior(int inputRowWarrior)
{
    rowWarrior = inputRowWarrior;
}

void Warrior::setColumnWarrior(int inputColumnWarrior)
{
    columnWarrior = inputColumnWarrior;
}

    //getters
string Warrior::getName()
{
    return nameWarrior;
}

int Warrior::getStrength()
{
    return strength;
}

int Warrior::getLoyalty()
{
    return loyalty;
}

int Warrior::getMorale()
{
    return morale;
}

bool Warrior::getIsFree()
{
    return isFree;
}

bool Warrior::doesWarriorHaveShip()
{
    return hasShipWarrior;
}

bool Warrior::doesWarriorHaveDragonglass()
{
    return hasDragonglass;
}
int Warrior::getRowWarrior()
{
    return rowWarrior;
}

int Warrior::getColumnWarrior()
{
    return columnWarrior;
}