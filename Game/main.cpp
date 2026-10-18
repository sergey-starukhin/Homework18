#include <iostream>
#include <cstring>
#include <windows.h>
#include "types.h"
#include "party.h"
#include "combat.h"
#include "saveLoad.h"
using namespace std;

//Закінчити етап 2 гри "Табір героїв", винести код обох етапів в окремі файли
//Оголошення структур в types.h
//Етап 1 в party.h, party.cpp
//Етап 2 в combat.h, combat.cpp
//нижче умови завдання(можна скопіювати і вставити в ваш main.cpp файл) :



//                                      САМОСТІЙНА РОБОТА: "ТАБІР ГЕРОЇВ"

//  Сюжет: ти - керівник табору героїв. До табору приходять нові герої, яких потрібно записати, підвищувати їм рівень, видавати зброю,
//  лікувати чи наносити їм шкоду в боях, і, на жаль, іноді герой гине в бою і його потрібно прибрати зі списку. Наприкінці - визначити
//  найсильнішого героя табору і загальну "силу" всього табору.

//  Структури нижче ВЖЕ ГОТОВІ - не потрібно їх змінювати, лише використовувати. Зверни увагу: Character - це ВКЛАДЕНА структура
//  (містить Stats і Item як поля), а PartyList - це масив структур Character (кожен герой табору).





//  ================== ЕТАП 1: CREATE + READ ==================

//  Завдання 1.1. Напишіть функцію
//      void recruitHero(PartyList& party, Character newHero);
//  яка додає нового героя В КІНЕЦЬ динамічного масиву героїв - за принципом:
//  -   виділити новий масив на +1,
//  -   скопіювати старі записи,
//  -   додати новий,
//  -   звільнити старий масив.

//  Завдання 1.2. Напишіть функцію
//      int findHeroIndex(const PartyList& party, const char* searchName);
//  -   яка повертає ІНДЕКС героя за іменем,
//  -   або -1, якщо такого героя в таборі немає.
//  -   Порівнюйте імена через strcmp.

//  Завдання 1.3. Напишіть функцію
//      Character getHeroByName(const PartyList& party, const char* searchName);
//  -   яка повертає КОПІЮ героя за іменем (скористайтесь findHeroIndex).
//  -   Якщо героя не знайдено - поверніть "порожнього" героя з level = -1.

//  Завдання 1.4. Напишіть функцію
//      void printParty(const PartyList& party);
//  -   яка виводить УСІХ героїв табору: ім'я, клас, рівень, hp,
//  -   ЗВЕРНІТЬ УВАГУ - потрібно вивести і вкладені поля: силу/спритність/інтелект (stats) і назву поточної зброї (weapon.name).


//  ================== ЕТАП 2: UPDATE ==================

//  Завдання 2.1. Напишіть функцію
//      bool levelUp(PartyList& party, const char* searchName);
//  -   яка знаходить героя за іменем
//  -   збільшує level на 1, а hp - на 10.
//  -   Повертає false, якщо героя не знайдено.

//  Завдання 2.2. Напишіть функцію
//      bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon);
//  -   яка змінює ПОЛЕ weapon (вкладену структуру) героя на нову зброю (заміняє І назву, І power).
//  -   Повертає false, якщо героя не знайдено.

//  Завдання 2.3. Напишіть функцію
//      bool damageHero(PartyList& party, const char* searchName, int amount);
//  -   яка зменшує hp героя на amount.
//  -   ВАЖЛИВО: hp не повинно ставати меншим за 0 (якщо amount більший за поточне hp - встановіть hp = 0).

//  Завдання 2.4. Напишіть функцію
//      bool healHero(PartyList& party, const char* searchName, int amount);
//  -   яка збільшує hp героя на amount, але hp НЕ повинно перевищувати 100 (якщо після лікування вийшло би більше 100 - встановіть hp = 100).


//  ================== ЕТАП 3: DELETE + аналітика ==================

//  Завдання 3.1. Напишіть функцію
//      bool dismissHero(PartyList& party, const char* searchName);
//  яка видаляє героя з табору за іменем за принципом:
//  -   виділити новий масив на -1,
//  -   скопіювати всіх, окрім видаленого, звільнити старий масив.
//  -   Не забудьте про особливий випадок, коли герой останній у таборі!

//  Завдання 3.2. Напишіть функцію
//      int totalPartyPower(const PartyList& party);
//  -   яка обчислює ЗАГАЛЬНУ силу всього табору - суму по всіх героях виразу (level * 10 + weapon.power) для кожного героя.

//  Завдання 3.3. Напишіть функцію
//      int findStrongestHeroIndex(const PartyList& party);
//  -   яка повертає ІНДЕКС героя з найбільшим значенням (stats.strength + stats.agility + stats.intelligence).
//  -   Якщо табір порожній - поверніть -1.

//  Завдання 3.4. Напишіть функцію
//      void sortByLevelDescending(PartyList& party);
//  -   яка сортує масив героїв за СПАДАННЯМ рівня (level), методом бульбашки


//  ================== ПЕРЕВІРКА: демонстрація в main() ==================
//  Заповніть main() власним сюжетом, використовуючи ВСІ написані функції. Орієнтовний сценарій (можете придумати свій):
//
//  1. Наберіть до табору 3-4 героїв (recruitHero) з різними класами, рівнями, характеристиками і початковою зброєю.
//  2. Виведіть табір (printParty).
//  3. Прочитайте одного героя за іменем (getHeroByName), виведіть інформацію про нього окремо.
//  4. Підвищіть рівень одному з героїв (levelUp).
//  5. Видайте новому герою кращу зброю (equipWeapon).
//  6. Влаштуйте "бій" - один герой отримує шкоду (damageHero), потім лікується (healHero).
//  7. Обчисліть і виведіть загальну силу табору (totalPartyPower).
//  8. Знайдіть і виведіть найсильнішого героя (findStrongestHeroIndex).
//  9. Один герой "гине в бою" - видаліть його з табору (dismissHero).
//  10. Виведіть табір ще раз, щоб побачити результат усіх дій.
//  11. Не забудьте звільнити пам'ять (delete[] party.heroes) наприкінці!

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    PartyList party;
    recruitHero(party, { "Pendalf", "Mage", 3, 100, 100, {5, 6, 15 }, { "staff", 5 } });
    recruitHero(party, { "Fedor", "Rogue", 1, 80, 80, {4, 9 , 4 }, { "ring", 10000 - 9999 } });
    recruitHero(party, { "Agronome", "Warrior", 3, 175, 175, {12, 7, 7 }, { "broken sword", 3 } });
    recruitHero(party, { "Legalize", "Archer", 3, 125, 125, {6, 14, 6 }, { "bow", 5 } });

    cout << endl << "Выводим всех героев на экран: " << endl;
    printParty(party);
    cout << "Выводим героя с именем \"Fedor\" на экран: " << endl;
    printHero(party.heroes[findHeroIndex(party, "Fedor")]);

    if (levelUp(party, "Fedor"))
    {
        party.heroes[findHeroIndex(party, "Fedor")].weapon.power++;
        cout << "Фёдор повысил уровень и теперь кольцо даёт ему больше силы!" << endl;
    }

    if (equipWeapon(party, "Agronome", { "Narsil", 10 }))
    {
        cout << "Йелфы восстановили Агроному меч Кызылдура! Его атака значительно возросла!" << endl;
    
    }

    //// Сохраняем игру
    saveGroup(party, "save01");
    //delete[] party.heroes;

    // Загружаем и продолжаем играть
    loadGroup(party, "save01");

    int index = findHeroIndex(party, "Legalize");
    int damage = party.heroes[index].stats.agility + party.heroes[index].weapon.power;

    if (damageHero(party, "Fedor", damage))
    {
        cout << "Ай! Легалайз случайно попал из лука Фёдору в глаз!" << endl;
        index = findHeroIndex(party, "Fedor");
        cout << "Хит пойнты Фёдора: " << party.heroes[index].currentHp << "/" << party.heroes[index].maxHp << endl;
    }

    if (healHero(party, "Fedor", 15))
    {
        cout << "Пендальф лечит Фёдору глаз припарками. Ему стало лучше, но глаз всё ещё болит." << endl;
        cout << "Хит пойнты Фёдора: " << party.heroes[index].currentHp << "/" << party.heroes[index].maxHp << endl;
    }

    // Сохраняем и выходим из игры
    saveGroup(party, "save01");
    delete[] party.heroes;


    // ЗАПОВНІТЬ ТУТ СЮЖЕТ ГРИ, ВИКОРИСТОВУЮЧИ ВСІ ФУНКЦІЇ, ЯКІ ВИ НАПИСАЛИ

    return 0;
}

