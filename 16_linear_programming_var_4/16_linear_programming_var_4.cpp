#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char* argv[]) {
    static int lol = 0;
    int a, b, d, key_row, key_str, baz[10], f, g = 0, i, j, l = 0, q = 0, z = 0, y = 0, xx, z1[10];
    float m, elements[10][10], min = 1000, c[10], kek1[10][10], x = 1000;
    setlocale(LC_ALL, "rus");
    cout << "Введите количество строки и количество столбцов:";
    cin >> a >> b;
    for (i = 0; i < a; i++) {

        for (j = 0; j < b; j++) {
            cout << "Введите [" << i << "][" << j << "] элемент таблицы\n";
            cin >> elements[i][j];
        }
    }
    cout << "первая итерация\n";
    for (i = 0; i < a; i++) {

        for (j = 0; j < b; j++) { cout << elements[i][j] << " "; }cout << endl;
        break;
    }
k:
    l = 0;
    for (i = 0; i < b; i++) {
        if (elements[a - 1][i] < 0) {
            l = l + 1;
        }
        break;
    }
    if (l == 0) {
        for (j = 1; j < b - a + 1; j++) {
            int kol = 0, nol = 0, ind;
            for (i = 0; i < a - 1; i++) {
                if (elements[i][j] == 1) {
                    kol++; ind = i;
                }
                else
                    nol++;
            }
            if ((kol == 1) && (a - nol == 2)) {
                cout << "x" << j << "=" << elements[ind][0] << endl;
                cout << "Решение оптимально" << endl;
                system("pause");
                return 0;
            }
        }

        for (i = 0; i < a; i++) {
            for (j = 0; j < b; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
        cout << "F(x)=" << elements[a - 1][0];
    }
    x = 1000;
    for (i = 1; i < b; i++) {
        if (elements[a - 1][i] <= x) {
            x = elements[a - 1][i];
            key_row = i;
        }
    }
    for (j = 0; j < a - 1; j++) {
        if (elements[j][key_row] > 0)
            c[j] = elements[j][0] / elements[j][key_row];
        else
            c[j] = 1000;
    }
    cout << "\nМассив для нахождения ключевой строки:" << endl;

    for (j = 0; j < a - 1; j++) {
        cout << c[j] << " ";
    }
    cout << endl;
    for (i = 0; i < (a - 1); i++)
        if (c[i] < min) {
            min = c[i];
            key_str = i;
        }
    cout << "\nKлючевой столбец и ключевая строка" << endl;
    cout << key_row << " " << key_str << " " << endl;
    cout << "\nКлючевой элемент:" << elements[key_str][key_row] << endl;
    cout << endl;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            kek1[i][j] = elements[i][j] - (elements[i][key_row] * elements[key_str][j] / elements[key_str][key_row]);
            kek1[i][key_row] = 0;
            kek1[key_str][key_row] = 1;
            kek1[key_str][j] = elements[key_str][j] / elements[key_str][key_row];
        }
        break;
    }
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            elements[i][j] = kek1[i][j];
        }
        break;
    }
    lol++;
    if (lol == 5) {
        ;
        return 0;
    }
    goto k;
    return 0;
}