#include <iostream>
#include "windows.h" 
#include <locale.h>
#include <vector>

using namespace std;

class Kalkulator
{
private:
    int operacja = 0;
    double wynik = 0;
    vector<double> liczby;
    bool dokonano_dzialania = false;
    vector<double> wykladnik_potegi()
    {
        int typ = 0;
        vector<double>temps;
        cout << "Wybór wykładnika potęgi:\n1.Liczba całkowita\n2.Liczba wymierna\n";
        while (typ < 1 || typ>2)
        {
            cout << "Podaj numer interesującego cię typu wykładnika potęgi:";
            cin >> typ;
        }
        if (typ == 1)
        {
            double temp = 0;
            cout << "Wprowadź wykładnik: ";
            cin >> temp;
            temps.push_back(temp);
        }
        else
        {
            double licznik = 0;
            double mianownik = 0;
            cout << "Wprowadź licznik wykładnika: ";
            cin >> licznik;
            cout << "Wprowadź mianownik wykładnika: ";
            cin >> mianownik;
            while (mianownik == 0)
            {
                cout << "Mianownik nie może być równy 0!\n";
                cout << "Wprowadź mianownik wykładnika: ";
                cin >> mianownik;
            }
            if (licznik > 0 && mianownik < 0)
            {
                licznik = -licznik;
                mianownik = -mianownik;
            }
            temps.push_back(licznik);
            temps.push_back(mianownik);
        }
        return temps;
    }
    double wprowadzUlamekZwykly()
    {
        double licznik = 0;
        double mianownik = 0;
        cout << "Wprowadź licznik: ";
        cin >> licznik;
        cout << "Wprowadź mianownik: ";
        cin >> mianownik;
        while (mianownik == 0)
        {
            cout << "Mianownik nie może być równy 0!\n";
            cout << "Wprowadź mianownik: ";
            cin >> mianownik;
        }
        return licznik/mianownik;
    }
    vector<double> wprowadz_liczby(int ilosc, string dzialanie="")
    {
        double sprawdzenie = 0;
        vector<double> w;
        vector<string> pytania;
        pytania.clear();
        for (int i = 0; i < ilosc+1; i++)
        {
            pytania.push_back("");
        }
        if (dzialanie == "dodawanie")
        {
            pytania[0] = "Wprowadź pierwszy składnik sumy: ";
            pytania[1] = "Wprowadź drugi składnik sumy: ";
        }
        else if (dzialanie == "odejmowanie")
        {
            pytania[0] = "Wprowadź odjemną różnicy: ";
            pytania[1] = "Wprowadź odjemnik różnicy: ";
        }
        else if (dzialanie == "mnozenie")
        {
            pytania[0] = "Wprowadź pierwszy czynnik iloczynu: ";
            pytania[1] = "Wprowadź drugi czynnik iloczynu: ";
        }
        else if (dzialanie == "dzielenie")
        {
            pytania[0] = "Wprowadź dzielną: ";
            pytania[1] = "Wprowadź dzielnik: ";
        }
        else if (dzialanie == "potegowanie")
        {
            pytania[0] = "Wprowadź podstawę potęgi: ";
            pytania[1] = "Wprowadź wykładnik potęgi: ";
        }
        else if (dzialanie == "pierwiastkowanie")
        {
            pytania[0] = "Wprowadź liczbę pod pierwiastkiem: ";
            pytania[1] = "Wprowadź stopień pierwiastka: ";
        }
        else if (dzialanie == "logarytm")
        {
            pytania[1] = "Wprowadź podstawę logarytmu: ";
        }
        else if (dzialanie == "rownanie_kwadratowe")
        {
            pytania[0] = "Wprowadź wartość współczynnika a (wartość przy niewiadomej x^2)";
            pytania[1] = "Wprowadź wartość współczynnika b (wartość przy niewiadomej x)";
            pytania[2] = "Wprowadź wartość współczynnika c (pozostała wartość równania)";
        }
        for (int i = 0; i < ilosc; i++)
        {
            vector<double> temps;
            double temp = 0;
            int wybor = 0;
            if (ilosc == 1)
            {
                cout << pytania[i + 1] << "\n";
            }
            else
            {
                cout << pytania[i]<<"\n";
            }
            if ((dzialanie=="pierwiastkowanie" && i==0 && ilosc==1) || (dzialanie == "pierwiastkowanie" && i == 1 && ilosc == 2))
            {
                cin >> temp;
                w.push_back(temp);
            }
            else
            {
                wybor = 0;
                cout << "Wybór sposób wprowadzania argumentu: \n1.Domyślny\n2.Ułamek zwykły\n";
                cin >> wybor;
                while (wybor != 1 && wybor != 2)
                {
                    cout << "Wybierz istniejący sposób!\n";
                    cin >> wybor;
                }
            }
            if (wybor == 1)
            {
                cin >> temp;
                w.push_back(temp);
            }
            else if (wybor==2)
            {
                w.push_back(wprowadzUlamekZwykly());
            }
        }
        return w;
    }
    void dodawanie()
    {
        if (dokonano_dzialania)
        {
            liczby = wprowadz_liczby(1, "dodawanie");
            double tempWynik = wynik + liczby[0];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "dodawanie");
                    tempWynik = wynik + liczby[0];
                }
            }
            wynik += liczby[0];
            cout << "Wynik działania: " << wynik<<"\n\n";
        }
        else
        {
            liczby = wprowadz_liczby(2, "dodawanie");
            double tempWynik = liczby[0] + liczby[1];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(2, "dodawanie");
                    tempWynik = wynik + liczby[0];
                }
            }
            wynik = liczby[0] + liczby[1];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    void odejmowanie()
    {
        if (dokonano_dzialania)
        {
            liczby = wprowadz_liczby(1, "odejmowanie");
            double tempWynik = wynik - liczby[0];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "odejmowanie");
                    tempWynik = wynik - liczby[0];
                }
            }
            wynik -= liczby[0];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        else
        {
            liczby = wprowadz_liczby(2, "odejmowanie");
            double tempWynik = liczby[0] - liczby[1];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(2, "odejmowanie");
                    tempWynik = liczby[0] - liczby[1];
                }
            }
            wynik = liczby[0] - liczby[1];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    void mnozenie()
    {
        if (dokonano_dzialania)
        {
            liczby = wprowadz_liczby(1);
            double tempWynik = wynik * liczby[0];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "mnozenie");
                    tempWynik = wynik * liczby[0];
                }
            }
            wynik *= liczby[0];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        else
        {
            liczby = wprowadz_liczby(2);
            double tempWynik = liczby[0] * liczby[1];
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "mnozenie");
                    tempWynik = liczby[0] * liczby[1];
                }
            }
            wynik = liczby[0] * liczby[1];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    void dzielenie()
    {
        if (dokonano_dzialania)
        {
            double tempWynik = 0;
            liczby = wprowadz_liczby(1, "dzielenie");
            if (liczby[0] != 0)
            {
                tempWynik = wynik / liczby[0];
            }
            while (liczby[0] == 0 || isnan(tempWynik) || isinf(tempWynik))
            {
                if (liczby[0] == 0)
                {
                    cout << "Nie można dzielić przez zero!\n";
                }
                else if (isnan(tempWynik) || isinf(tempWynik))
                {
                    cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                }
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "dzielenie");
                    if (liczby[0] != 0)
                    {
                        tempWynik = wynik / liczby[0];
                    }
                }
            }
            wynik /= liczby[0];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        else
        {
            double tempWynik = 0;
            liczby = wprowadz_liczby(2, "dzielenie");
            if (liczby[1] != 0)
            {
                tempWynik = liczby[0] / liczby[1];
            }
            while (liczby[1] == 0 || isnan(tempWynik) || isinf(tempWynik))
            {
                if (liczby[1] == 0)
                {
                    cout << "Nie można dzielić przez zero!\n";
                }
                else if (isnan(tempWynik) || isinf(tempWynik))
                {
                    cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                }
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(2, "dzielenie");
                    if (liczby[1] != 0)
                    {
                        tempWynik = liczby[0] / liczby[1];
                    }
                }
            }
            wynik = liczby[0] / liczby[1];
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    void potegowanie()
    {
        double tempWynik = 0;
        if (dokonano_dzialania)
        {
            liczby = wprowadz_liczby(1, "potegowanie");
            tempWynik = pow(wynik, liczby[0]);
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "potegowanie");
                    tempWynik = pow(wynik, liczby[0]);
                }
            }
            wynik = pow(wynik, liczby[0]);
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        else
        {
            liczby = wprowadz_liczby(2, "potegowanie");
            tempWynik = pow(liczby[0], liczby[1]);
            while (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(2, "potegowanie");
                    tempWynik = pow(liczby[0], liczby[1]);
                }
            }
            wynik = pow(liczby[0], liczby[1]);
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    double pierwiastkowanie(double podstawa=0, double stopien=-1)
    {
        double tempWynik = 0;
        if (podstawa == 0 && stopien == -1)
        {
            if (dokonano_dzialania)
            {
                liczby = wprowadz_liczby(1, "pierwiastkowanie");
                if (liczby[0]> 0)
                {
                    tempWynik = pow(wynik, 1.0 / liczby[0]);
                }
                while (liczby[0] <= 0 || isnan(tempWynik) || isinf(tempWynik))
                {
                    if (liczby[0] <= 0)
                    {
                        cout << "Stopień pierwiastka musi być liczbą całkowitą dodatnią!\n";
                    }
                    if (isnan(tempWynik) || isinf(tempWynik))
                    {
                        cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                    }
                    int temp = 0;
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                    while (temp != 0 && temp != 1)
                    {
                        cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                        cin >> temp;
                    }
                    if (temp == 0)
                    {
                        cout << "\n";
                        menu();
                    }
                    else
                    {
                        liczby = wprowadz_liczby(1, "pierwiastkowanie");
                        if (liczby[0] > 0)
                        {
                            tempWynik = pow(wynik, 1.0 / liczby[0]);
                        }
                    }
                }
                wynik = pow(wynik, 1.0 / liczby[0]);
                cout << "Wynik działania: " << wynik << "\n\n";
            }
            else
            {
                liczby = wprowadz_liczby(2, "pierwiastkowanie");
                if (liczby[1] > 0)
                {
                    tempWynik = pow(liczby[0], 1.0 / liczby[1]);
                }
                while (liczby[1] <= 0 || isnan(tempWynik) || isinf(tempWynik))
                {
                    if (liczby[1] <= 0)
                    {
                        cout << "Stopień pierwiastka musi być liczbą całkowitą dodatnią!\n";
                    }
                    if (isnan(tempWynik) || isinf(tempWynik))
                    {
                        cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                    }
                    int temp = 0;
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                    while (temp != 0 && temp != 1)
                    {
                        cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                        cin >> temp;
                    }
                    if (temp == 0)
                    {
                        cout << "\n";
                        menu();
                    }
                    else
                    {
                        liczby = wprowadz_liczby(2, "pierwiastkowanie");
                        if (liczby[1] > 0)
                        {
                            tempWynik = pow(liczby[0], 1.0 / liczby[1]);
                        }
                    }
                }
                wynik = pow(liczby[0], 1.0/liczby[1]);
                cout << "Wynik działania: " << wynik << "\n\n";
            }
            dokonano_dzialania = true;
            menu();
            return 0;
        }
        else
        {
            return pow(podstawa, 1.0 / stopien);
        }
    }
    void logarytm()
    {
        double tempWynik = 0;
        if (dokonano_dzialania)
        {
            if (wynik <= 0)
            {
                cout << "Liczba logarytmowana przy logarytmie o podstawie 10 musi być dodatnia!\n\n";
                menu();
            }
            else
            {
                tempWynik = log10(wynik);
            }
            if (isnan(tempWynik) || isinf(tempWynik))
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n\n";
                menu();
            }
            else
            {
                wynik = log10(wynik);
                cout << "Wynik działania: " << wynik << "\n\n";
            }
        }
        else
        {
            liczby = wprowadz_liczby(1, "logarytm");
            while (liczby[0] <= 0 || isnan(tempWynik) || isinf(tempWynik))
            {
                if (liczby[0] <= 0)
                {
                    cout << "Liczba logarytmowana przy logarytmie o podstawie 10 musi być dodatnia!\n";
                }
                else
                {
                    tempWynik = log10(liczby[0]);
                }
                if (isnan(tempWynik) || isinf(tempWynik))
                {
                    cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
                }
                int temp = 0;
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
                while (temp != 0 && temp != 1)
                {
                    cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                    cin >> temp;
                }
                if (temp == 0)
                {
                    cout << "\n";
                    menu();
                }
                else
                {
                    liczby = wprowadz_liczby(1, "logarytm");
                    if (liczby[0] > 0)
                    {
                        tempWynik = log10(liczby[0]);
                    }
                }
            }
            wynik = log10(liczby[0]);
            cout << "Wynik działania: " << wynik << "\n\n";
        }
        dokonano_dzialania = true;
        menu();
    }
    vector<double> obliczPierwiastki(vector<double> argumenty)
    {
        double delta = argumenty[1] * argumenty[1] - 4 * argumenty[0] * argumenty[2];
        vector<double> wynik;
        if (delta > 0)
        {
            double x1 = (-argumenty[1] - pierwiastkowanie(delta, 2)) / (2 * argumenty[0]);
            double x2 = (-argumenty[1] + pierwiastkowanie(delta, 2)) / (2 * argumenty[0]);
            if (isnan(x1) || isinf(x1) || isnan(x2) || isinf(x2))
            {
                return { 0,0,0 };
            }
            else
            {
                wynik.push_back(x1);
                wynik.push_back(x2);
                return wynik;
            }
        }
        else if (delta == 0)
        {
            double x = -argumenty[1] / (2 * argumenty[0]);
            if (isnan(x) || isinf(x))
            {
                return { 0,0,0 };
            }
            else
            {
                wynik.push_back(x);
                return wynik;
            }
        }
        else
        {
            return wynik;
        }
    }
    void rownanie_kwadratowe()
    {
        liczby = wprowadz_liczby(3, "rownanie_kwadratowe");
        vector<double> tempPierwiastki;
        if (liczby[0] != 0)
        {
            tempPierwiastki = obliczPierwiastki(liczby);
        }
        while (liczby[0] <= 0 || tempPierwiastki.size()==3)
        {
            if (liczby[0] <= 0)
            {
                cout << "Wartość przy niewiadomej x^2 nie może być równa 0!\n";
            }
            else
            {
                tempPierwiastki = obliczPierwiastki(liczby);
            }
            if (tempPierwiastki.size()==3)
            {
                cout << "Przy podanych argumentach nie jest możliwe uzyskanie wyniku lub nie mieści się on w pamięci\n";
            }
            int temp = 0;
            cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
            cin >> temp;
            while (temp != 0 && temp != 1)
            {
                cout << "Wprowadź 1 aby spróbować ponownie wprowadzić argumenty lub 0 aby powrócić do menu: ";
                cin >> temp;
            }
            if (temp == 0)
            {
                cout << "\n";
                menu();
            }
            else
            {
                liczby = wprowadz_liczby(3, "rownanie_kwadratowe");
                if (liczby[0] > 0)
                {
                    tempPierwiastki = obliczPierwiastki(liczby);
                }
            }
        }
        tempPierwiastki = obliczPierwiastki(liczby);
        if (tempPierwiastki.size() == 2)
        {
            cout << "Podane równanie kwadratowe posiada 2 rozwiązania:\n1." << tempPierwiastki[0] << "\n2." << tempPierwiastki[1]<<"\n\n";
        }
        else if (tempPierwiastki.size() == 1)
        {
            cout << "Podane równanie kwadratowe posiada jedno rozwiązanie: " << tempPierwiastki[0]<< "\n\n";
        }
        else
        {
            cout << "Podane równanie kwadratowe nie posiada rozwiązań\n\n";
        }
        menu();
    }
public:
    void menu()
    {
        cout << "---------------MENU---------------";
        cout << "\n";
        operacja = 0;
        liczby.clear();
        if (dokonano_dzialania)
        {
            cout << "Aktualny wynik: " << wynik << "\n";
        }
        cout << "Dostępne operacje: \n1.Dodawanie\n2.Odejmowanie\n3.Mnożenie\n4.Dzielenie\n5.Potęgowanie\n6.Pierwiastkowanie\n7.Logarytm dziesiętny\n8.Równanie kwadratowe\n9.Wyzerowanie wyniku\n10.Opuść\n";
        while (operacja < 1 || operacja>10)
        {
            cout << "Wpisz numer operacji: ";
            cin >> operacja;
            switch (operacja)
            {
            case 1:
                dodawanie();
                break;
            case 2:
                odejmowanie();
                break;
            case 3:
                mnozenie();
                break;
            case 4:
                dzielenie();
                break;
            case 5:
                potegowanie();
                break;
            case 6:
                pierwiastkowanie();
                break;
            case 7:
                logarytm();
                break;
            case 8:
                rownanie_kwadratowe();
                break;
            case 9:
                wynik = 0;
                dokonano_dzialania = false;
                cout << "\n";
                menu();
                break;
            case 10:
                break;
            default:
                cout << "Nie znaleziono takiej operacji!\n";
                operacja = 0;
                break;
            }
        }
    }
};

int main()
{
    setlocale(LC_CTYPE, "Polish");
    Kalkulator main;
    std::cout << "Witam w kalkulatorze matematycznym!\n";
    Sleep(600);
    main.menu();
}

