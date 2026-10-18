#pragma once
#include "types.h"

int findHeroIndex(const PartyList& party, const char* searchName);
int sumHeroStats(Character hero);
int findStrongestHeroIndex(const PartyList& party);
int characterPower(Character hero);
int totalPartyPower(const PartyList& party);
bool dismissHero(PartyList& party, const char* searchName);
Character getHeroByName(const PartyList& party, const char* searchName);
void recruitHero(PartyList& party, Character newHero);
void printHero(const Character hero);
void printParty(const PartyList& party);
void sortByLevelDescending(PartyList& party);
