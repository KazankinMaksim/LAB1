#include "RouteCipher.h"

// Конструктор класса RouteCipher
RouteCipher::RouteCipher(int k) {
    key = k;
}

// Функция для шифрования текста
string RouteCipher::encrypt(const string& text) {
    int row = key, col = text.length();
    vector<vector<char>> matrix(row, vector<char>(col, ' '));

    int direction = 0;
    int row_index = 0, col_index = 0;

    // Заполнение матрицы символами текста по диагонали
    for (int i = 0; i < col; i++) {
        if (row_index == 0 || row_index == row - 1)
            direction = 1 - direction;
        matrix[row_index][col_index++] = text[i];
        if (direction)
            row_index++;
        else
            row_index--;
    }

    string cipher_text;
    // Считывание элементы матрицы построчно для создания зашифрованного текста
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] != ' ')
                cipher_text += matrix[i][j];

    return cipher_text;
}

// Функция для дешифрования текста
string RouteCipher::decrypt(const string& cipher_text) {
    int row = key, col = cipher_text.length();
    vector<vector<char>> matrix(row, vector<char>(col, ' '));

    int direction;
    int row_index = 0, col_index = 0;

    // Заполнение матрицы символами '*' по диагонали
    for (int i = 0; i < col; i++) {
        if (row_index == 0)
            direction = 1;
        if (row_index == row - 1)
            direction = 0;
        matrix[row_index][col_index++] = '*';
        if (direction)
            row_index++;
        else
            row_index--;
    }

    int index = 0;
    // Замена символов '*' на символы зашифрованного текста построчно
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] == '*' && index < col)
                matrix[i][j] = cipher_text[index++];

    string text;
    row_index = 0, col_index = 0;
    // Считывание матрицы по диагонали для восстановления исходного текста
    for (int i = 0; i < col; i++) {
        if (row_index == 0)
            direction = 1;
        if (row_index == row - 1)
            direction = 0;
        if (matrix[row_index][col_index] != '*')
            text += matrix[row_index][col_index++];
        if (direction)
            row_index++;
        else
            row_index--;
    }

    return text;
}
