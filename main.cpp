#include "mylib.h"

int main() {
    int studentuSkaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studentuSkaicius;

    bool naudotiMediana;
    cout << "Naudoti mediana ar vidurki (0 - vidurkis, 1 - mediana): ";
    cin >> naudotiMediana;

    vector <Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; i++) {
        cout << "Iveskite " << i + 1 << " studento varda: ";
        cin >> studentai[i].var;

        cout << "Iveskite " << i + 1 << " studento pavarde: ";
        cin >> studentai[i].pav;

        int pazymys;
        cout << "Iveskite " << i + 1 << " studento namu darbu rezultatus (baigti su -1): ";
        while (cin >> pazymys) {
            if (pazymys == -1) {
                break;
            }
            studentai[i].paz.push_back(pazymys);
        }

        cout << "Iveskite " << i + 1 << " studento egzamino rezultata: ";
        cin >> studentai[i].egz;

        studentai[i].rez = skaiciuotiGalutiniBala(studentai[i], naudotiMediana);
    }

    spausdintiDuomenis(studentai, naudotiMediana);

    return 0;
}

