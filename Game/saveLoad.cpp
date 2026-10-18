#include <iostream>
#include "types.h"
#include "saveLoad.h"
using namespace std;

int countCharacters(const char* fileName)
{
    FILE* file = nullptr;
    fopen_s(&file, fileName, "rb");

    if (file == nullptr)
    {
        cout << "Ошибка! Сохранение не доступно!" << endl;
        return -1;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);

    fclose(file);

    return fileSize / sizeof(Character);
}

bool saveGroup(PartyList& party, const char* fileName) {
	FILE* file = nullptr;
	fopen_s(&file, fileName, "wb");

    if (file == nullptr)
    {
        cout << "Ошибка! Не удалось открыть файл для сохранения!" << endl;
        return false;
    }

    fwrite(&party, sizeof(PartyList), 1, file);
    fclose(file);
    return true;
}

bool loadGroup(PartyList& party, const char* fileName) {
    FILE* file = nullptr;
    fopen_s(&file, fileName, "rb");

    if (file == nullptr)
    {
        cout << "Ошибка! Сохранение не доступно!" << endl;
        return false;
    }

    party.size = countCharacters(fileName);
    if (party.size != -1)
    {
        fread(&party.heroes, sizeof(Character), party.size, file);
        //for (int i = 0; i < party.size; i++)
        //{
        //    fread(&party.heroes, sizeof(Character), 1, file);
        //    cout << i + 1 << ". " << party.heroes[i].name << endl;
        //}
    }

    fclose(file);
    return true;
}

