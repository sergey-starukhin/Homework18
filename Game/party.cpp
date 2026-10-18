#include <iostream>
#include <cstring>
#include <windows.h>
#include "party.h"
using namespace std;

int findHeroIndex(const PartyList& party, const char* searchName)
{
    for (int i = 0; i < party.size; i++)
    {
        if (strcmp(party.heroes[i].name, searchName) == 0)
            return i;
    }
    return -1;
}

int sumHeroStats(Character hero)
{
    return hero.stats.strength + hero.stats.agility + hero.stats.intelligence;
}

int findStrongestHeroIndex(const PartyList& party) 
{
    if (party.size == 0)
        return -1;
    else
    {
        int strongestIndex = 0;
        int strongestValue = 0;
        for (int i = 0; i < party.size; i++)
        {
            if (strongestValue < sumHeroStats(party.heroes[i]))
            {
                strongestValue = sumHeroStats(party.heroes[i]);
                strongestIndex = i;
            }
        }
        return strongestIndex;
    }
}

int characterPower(Character hero)
{
    return (hero.level * 10) + hero.weapon.power;
}

int totalPartyPower(const PartyList& party) 
{
    int total = 0;
    for (int i = 0; i < party.size; i++)
    {
        total += characterPower(party.heroes[i]);
    }
    return total;
}

bool dismissHero(PartyList& party, const char* searchName) 
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    { 
        return false;
    }
    else
    {
        if (party.size == 1)
        {
            delete[] party.heroes;
            party.size = 0;
        }
        else
        {
            int newSize = party.size - 1;
            Character* newHeroes = new Character[newSize];

            for (int i = 0; i < newSize; i++)
            {
                if (i < index)
                    newHeroes[i] = party.heroes[i];
                else
                    newHeroes[i] = party.heroes[i + 1];
            }

            delete[] party.heroes;
            party.heroes = newHeroes;
            party.size = newSize;            
        }
        return true;
    }
}

Character getHeroByName(const PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index > -1)
        return party.heroes[index];
    else return { "empty", "none", -1, -1, -1, {-1, -1, -1}, {"none", -1} };
}

void recruitHero(PartyList& party, Character newHero)
{
    int newSize = party.size + 1;
    Character* newHeroes = new Character[newSize];

    for (int i = 0; i < party.size; i++)
    {
        newHeroes[i] = party.heroes[i];
    }
    newHeroes[party.size] = newHero;
    delete[] party.heroes;
    party.heroes = newHeroes;
    party.size = newSize;
}

void printHero(const Character hero)
{
    cout << "Name: " << hero.name << endl;
    cout << "Class: " << hero.classType << endl;
    cout << "Current level: " << hero.level << endl;
    cout << "Hit points: " << hero.currentHp << "/" << hero.maxHp << endl;
    cout << "-------------------------" << endl;
    cout << "Stats" << endl;
    cout << "Strength:\t\t" << hero.stats.strength << endl;
    cout << "Agility:\t\t" << hero.stats.agility << endl;
    cout << "Intelligence:\t\t" << hero.stats.intelligence << endl;
    cout << "-------------------------" << endl;
    cout << "Current weapon: " << hero.weapon.name << endl << endl;
}

void printParty(const PartyList& party)
{
    for (int i = 0; i < party.size; i++)
    {
        cout << i + 1 << " hero: " << endl;
        printHero(party.heroes[i]);
    }
}

void sortByLevelDescending(PartyList& party)
{
    for (int i = 0; i < party.size; i++)
    {
        for (int j = party.size - 1; j > i; j--)
        {
            if (party.heroes[j - 1].level < party.heroes[j].level)
            {
                Character temp = party.heroes[j - 1];
                party.heroes[j - 1] = party.heroes[j];
                party.heroes[j] = temp;
            }
        }
    }
}
