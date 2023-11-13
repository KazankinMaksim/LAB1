#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
using namespace std;
class RouteCipher
{
private:
    int key;
public:
    RouteCipher() = delete; //запретим конструктор без параметров
    RouteCipher(int k); //конструктор для установки ключа
    string encrypt(const string& text); //зашифрование
    string decrypt(const string& cipher_text); //расшифрование
};
