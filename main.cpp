#include "mylib.h"

int main() {
    int studentuSkaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studentuSkaicius;

    bool naudotiMediana;
    cout << "Naudoti mediana ar vidurki (0 - vidurkis, 1 - mediana): ";
    cin >> naudotiMediana;

    bool generuotiPaz;
    cout << "Sugeneruoti pazymius atsitiktinai(0 - NE, 1 - TAIP): ";
    cin >> generuotiPaz;

    vector <Studentas> studentai(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; i++) {
        cout << "Iveskite " << i + 1 << " studento varda: ";
        cin >> studentai[i].var;

        cout << "Iveskite " << i + 1 << " studento pavarde: ";
        cin >> studentai[i].pav;

        if (generuotiPaz==0){
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
        }else{
            srand(time(NULL));
            int ndkiekis;
            int pazymys;
            cout << "Kiek norite pazymiu? ";
            cin >> ndkiekis;
            cout << "Atsitiktinai sugeneruoti " << i + 1 << " studento namu darbu pazymiai:" ;
            for(int i = 0; i < ndkiekis; i++) {
                pazymys = GetRandomPaz(1, 10);
            studentai[i].paz.push_back(pazymys);
            cout << pazymys << " ";
            }
            cout << endl;
            studentai[i].egz = GetRandomPaz(1, 10);
            cout << "Egzaminas: " << studentai[i].egz <<endl;
        }

        studentai[i].rez = skaiciuotiGalutiniBala(studentai[i], naudotiMediana);
    }

    spausdintiDuomenis(studentai, naudotiMediana);

    return 0;
}

