#include "types.h"
#include "party.h"

bool levelUp(PartyList& party, const char* searchName) {
	int index = findHeroIndex(party, searchName);

	if (index != -1)
	{
		party.heroes[index].level++;
		party.heroes[index].maxHp += 10;
		party.heroes[index].currentHp = party.heroes[index].maxHp; // после левел апа полностью вылечивается
		return true;
	}
	else
		return false;
}

bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon) {
	int index = findHeroIndex(party, searchName);

	if (index != -1)
	{
		party.heroes[index].weapon = newWeapon;
		return true;
	}
	else
		return false;
}

bool damageHero(PartyList& party, const char* searchName, int amount) {
	int index = findHeroIndex(party, searchName);

	if (index != -1)
	{
		if (party.heroes[index].currentHp > amount)
			party.heroes[index].currentHp -= amount;
		else
			party.heroes[index].currentHp = 0;
		return true;
	}
	else
		return false;
}


bool healHero(PartyList& party, const char* searchName, int amount) {
	int index = findHeroIndex(party, searchName);

	if (index != -1)
	{
		int hp = party.heroes[index].currentHp + amount;
		if (party.heroes[index].maxHp > hp)
			party.heroes[index].currentHp = hp;
		else
			party.heroes[index].currentHp = party.heroes[index].maxHp;
		return true;
	}
	else
		return false;
}