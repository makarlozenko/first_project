#include "mylib.h"

int main() {
    int studentuSkaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studentuSkaicius;

    vector <Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; i++) {
        cout << "Iveskite " << i + 1 << " studento varda: ";
        cin >> studentai[i].var;

        cout << "Iveskite " << i + 1 << " studento pavarde: ";
        cin >> studentai[i].pav;

        int namuDarbuSkaicius;
        cout << "Iveskite " << i + 1 << " studento namu darbu skaiciu: ";
        cin >> namuDarbuSkaicius;

        studentai[i].paz.resize(namuDarbuSkaicius);

        cout << "Iveskite " << i + 1 << " studento pazymius (tarpinius rezultatus): ";
        for (int j = 0; j < namuDarbuSkaicius; j++) {
            cin >> studentai[i].paz[j];
        }

        cout << "Iveskite " << i + 1 << " studento egzamino rezultata: ";
        cin >> studentai[i].egz;

        studentai[i].rez = skaiciuotiGalutiniBala(studentai[i]);
    }
    spausdintiDuomenis(studentai);

    return 0;
}

