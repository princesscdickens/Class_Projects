#include "Playerscore.h"

using namespace std;

    // private:
    // // <username>-<Hero>-<points score>-<won/lost>
    // string username;
    // string heroName;
    // int pointsScore;
    // string wonLost;

Playerscore::Playerscore()
{
    username = "";
    heroName = "";
    pointsScore = 0;
    wonLost = "";
}
    
Playerscore::Playerscore(string inputUsername, string inputHeroName, int inputPointsScore, string inputWonLost)
{
    username = inputUsername;
    heroName = inputHeroName;
    pointsScore = inputPointsScore;
    wonLost = inputWonLost;
}
    
    //setters
void Playerscore::setUsername(string inputUsername)
{
    username = inputUsername;
}

void Playerscore::setHeroName(string inputHeroName)
{
    heroName = inputHeroName;
}

void Playerscore::setPointsScore(int inputPointsScore)
{
    pointsScore = inputPointsScore;
}

void Playerscore::setWonLost(string inputWonLost)
{
    wonLost = inputWonLost;
}
    
    //getters
string Playerscore::getUsername()
{
    return username;
}

string Playerscore::getHeroName()
{
    return heroName;
}

int Playerscore::getPointsScore()
{
    return pointsScore;
}

string Playerscore::getWonLost()
{
    return wonLost;
}