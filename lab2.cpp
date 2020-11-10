#include <iostream>
using namespace std;

class wektor
{
public:
    wektor(int n)
    {
        tab = new double[n];
        for (int i = 0; i < n; i++) {
            tab[i] = 0.0;
        }
        dlugosc   = n;
        pojemnosc = n;
    };
    ~wektor()
    {
        delete[] tab;
        cout << "i cyk nie ma tablicy" << endl;
    };
    void zmienDlugosc(int d)
    {
        if (d <= dlugosc) {
            for (int i = d; i < dlugosc; i++) {
                tab[i] = 0.0;
            }
            dlugosc = d;
        }
        else {
            double* tab2 = tab;
            tab          = new double[d];
            for (int i = 0; i < dlugosc; i++) {
                tab[i] = tab2[i];
            }
            for (int i = dlugosc; i < d; i++) {
                tab[i] = 0.0;
            }
            pojemnosc = d;
            dlugosc   = d;
            delete[] tab2;
        }
    };

    void getterDlugosc() { cout << "dlugosc rowna sie= " << dlugosc << endl; }
    void getterPojemnosc() { cout << "pojemnosc rowna sie= " << pojemnosc << endl; }
    void print()
    {
        cout << "kolejne argumenty wektora" << endl;
        for (int i = 0; i < dlugosc; i++) {
            cout << tab[i] << endl;
        };
    };
    double& operator[](int index)
    {
        if (index >= dlugosc) {
            zmienDlugosc(index);
        }
        return tab[index];
    }

private:
    double* tab;
    int     dlugosc;
    int     pojemnosc;
};
struct Kokardka
{
    Kokardka() { dlugosc = 42; }
    Kokardka(int d) { dlugosc = d; }

    int dlugosc;
};

struct Prezent
{
    Prezent(int dk)
    {
        cout << k.dlugosc << endl;

        k.dlugosc = dk;
        cout << k.dlugosc << endl;
    }

    Kokardka k;
    // Inne pola ...
};

int main()
{
    Prezent p1(1);

    /* wektor f1(5);
     cout << "czy to juz? " << endl;
     f1.getterDlugosc();
     f1.getterPojemnosc();
     f1.print();
     f1.zmienDlugosc(3);
     f1.print();
     f1.getterDlugosc();
     f1.getterPojemnosc();
     cout << "czy to juz? " << endl;
     f1.print();
     f1.zmienDlugosc(8);
     f1.getterDlugosc();
     f1.getterPojemnosc();
     f1.print();
     cout << "czy to juz? " << endl;
     */
}
