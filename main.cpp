#include "mylib.h"

int main() {

    bool naudotiFaila;
    while (true) {
    cout << "Naudoti faila ar ranka (0 - failas, 1 - ranka): ";
    cin >> naudotiFaila;
    if (cin.fail() || (naudotiFaila != 0 && naudotiFaila != 1)) {
        cout << "Nevalidus pasirinkimas. Prasome ivesti 0 arba 1." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        break;
    }}


    bool naudotiMediana;
    while (true) {
    cout << "Naudoti mediana ar vidurki (0 - vidurkis, 1 - mediana): ";
    cin >> naudotiMediana;
    if (cin.fail() || (naudotiMediana != 0 && naudotiMediana != 1)) {
        cout << "Nevalidus pasirinkimas. Prasome ivesti 0 arba 1." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        break;
    }}


    if (naudotiFaila==0){
        vector <Studentas> studentai;
        string failoPavadinimas;
        cout << "Iveskite failo pavadinima: ";
        cin >> failoPavadinimas;
        nuskaitytiDuomenisIsFailo(failoPavadinimas, studentai);
        int eil=kiekEiluciu(failoPavadinimas);
        for (int m = 0; m < eil-1; m++) {
            studentai[m].rez = skaiciuotiGalutiniBala(studentai[m], naudotiMediana);
        }
        spausdintiDuomenis(studentai, naudotiMediana);
    }else{
        int studentuSkaicius;
        while (true) {
        cout << "Iveskite studentu skaiciu: ";
        cin >> studentuSkaicius;
        if (cin.fail()) {
            cout << "Nevalidus pasirinkimas. Prasome ivesti skaiciu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }}


        bool generuotiPaz;
        while (true) {
        cout << "Sugeneruoti pazymius atsitiktinai(0 - NE, 1 - TAIP): ";
        cin >> generuotiPaz;
        if (cin.fail() || (generuotiPaz != 0 && generuotiPaz != 1)) {
            cout << "Nevalidus pasirinkimas. Prasome ivesti 0 arba 1." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }}

        vector <Studentas> studentai(studentuSkaicius);

        for (int i = 0; i < studentuSkaicius; i++) {
            cout << "Iveskite " << i + 1 << " studento varda: ";
            cin >> studentai[i].var;

            cout << "Iveskite " << i + 1 << " studento pavarde: ";
            cin >> studentai[i].pav;

            if (generuotiPaz==0){
                cout << "Iveskite " << i + 1 << " studento namu darbu rezultatus (baigti su -1): ";
                while (true) {
                    int pazymys;
                    cin >> pazymys;
                    if (cin.fail()||pazymys<-1||pazymys>10) {
                        cout << "Nevalidus pazymys. Prasome ivesti pazymius." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (pazymys == -1) {
                        break;
                    } else {
                        studentai[i].paz.push_back(pazymys);
                    }
                }


                while (true) {
                cout << "Iveskite " << i + 1 << " studento egzamino rezultata: ";
                cin >> studentai[i].egz;
                if (cin.fail()||studentai[i].egz<1||studentai[i].egz>10) {
                    cout << "Nevalidus pasirinkimas. Prasome ivesti pazymi." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }}


            }else{
                srand(time(NULL));
                int ndkiekis;
                int pazymys;
                cout << "Kiek norite pazymiu? ";
                cin >> ndkiekis;
                cout << "Atsitiktinai sugeneruoti " << i + 1 << " studento namu darbu pazymiai:" ;
                for(int k = 0; k < ndkiekis; k++) {
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
    }
    return 0;
}

