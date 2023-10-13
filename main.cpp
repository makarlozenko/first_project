#include "mylib.h"

int main() {

    bool naudotiFaila;
    while(true){
        try{
            cout << "Naudoti faila ar ranka (0 - failas, 1 - ranka): ";
            cin >> naudotiFaila;

            if(cin.fail() || (naudotiFaila != 0 && naudotiFaila != 1)){
                throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
            }else{
                break;
            }
        }catch (invalid_argument e){
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }



    if (naudotiFaila==0){
        bool generuotiFaila;
        while(true){
            try{
                cout << "Generuoti faila ar ne (0 - NE, 1 - TAIP): ";
                cin >> generuotiFaila;

                if(cin.fail() || (generuotiFaila != 0 && generuotiFaila != 1)){
                    throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
                }else{
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (generuotiFaila==1) {

            int testuSk;
            cout<<"Kiek norite padaryti testu? ";
            cin >>testuSk;

            string naujasFailas;
            cout << "Iveskite naujo failo pavadinima: ";
            cin >> naujasFailas;

            int sKiekis;
            cout<<"Kiek norite studentu? ";
            cin>>sKiekis;

            int ndKiekis;
            cout<<"Kiek norite namu darbu? ";
            cin>>ndKiekis;

            double suma=0;

            for (int t=1; t<=testuSk; t++){
                vector <Studentas> studentai;

                auto start = high_resolution_clock::now();

                ofstream nFailas (naujasFailas+to_string(t)+".txt");

                srand(time(NULL));
                bool naudotiMediana;
                int pazymysF;
                string baseVardas = "Vardas";
                string basePavarde = "Pavarde";
                for (int i=0; i < sKiekis; i++){
                    Studentas studentas;
                    string newName = baseVardas + to_string(i+1);
                    studentas.var=newName;
                    string newSurname = basePavarde + to_string(i+1);
                    studentas.pav=newSurname;


                    for(int k = 0; k < ndKiekis; k++) {
                        pazymysF = GetRandomPaz(1, 10);
                        studentas.paz.push_back(pazymysF);
                    }
                    studentas.egz = GetRandomPaz(1, 10);

                    naudotiMediana=1;
                    studentas.rezm = skaiciuotiGalutiniBala(studentas, naudotiMediana);

                    naudotiMediana=0;
                    studentas.rezv = skaiciuotiGalutiniBala(studentas, naudotiMediana);

                    studentai.push_back(studentas);
                }


                nFailas <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde";
                for (int j=1; j<=ndKiekis; j++){
                    nFailas << left << setw(5) << "ND"+to_string(j);
                }
                nFailas << left << setw(20) << "Egzaminas"<< left << setw(20) << "Mediana"<< left << setw(20) << "Vidurkis"<<endl ;

                for (Studentas student : studentai) {
                    nFailas << left << setw(30) << student.var << left << setw(30)  << student.pav ;
                    for (int paz : student.paz){
                        nFailas << left << setw(5) << paz;
                    }
                    nFailas << left << setw(20) << student.egz<< left << setw(20) << student.rezm<< left << setw(20) << student.rezv<<endl;
                }
                nFailas.close();

                auto end = high_resolution_clock::now();
                duration<double> diff = end-start;
                cout << sKiekis << " elementu uzpildymas uztruko: "<< diff.count() << " s\n";

                rusiuotiDuomenisIsGeneruotoFailo(naujasFailas, sKiekis,  diff, t, suma);
            }
            cout<<"Padarytu testu laiko vidurkis: "<<suma/testuSk<<endl;



        }else{
            vector <Studentas> studentai;
            string failoPavadinimas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            nuskaitytiDuomenisIsFailo(failoPavadinimas, studentai);
            int eil=kiekEiluciu(failoPavadinimas);
            bool naudotiMediana;
            for (int m = 0; m < eil-1; m++) {
                naudotiMediana=1;
                studentai[m].rezm = skaiciuotiGalutiniBala(studentai[m], naudotiMediana);
                naudotiMediana=0;
                studentai[m].rezv = skaiciuotiGalutiniBala(studentai[m], naudotiMediana);
            }
            spausdintiDuomenis(studentai, naudotiMediana,naudotiFaila);
        }


    }else{

        bool naudotiMediana;
        while (true) {
            try{
                cout << "Naudoti mediana ar vidurki (0 - vidurkis, 1 - mediana): ";
                cin >> naudotiMediana;

                if (cin.fail() || (naudotiMediana != 0 && naudotiMediana != 1)) {
                    throw invalid_argument( "Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
                } else {
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        int studentuSkaicius;
        while (true) {
            try{
                cout << "Iveskite studentu skaiciu: ";
                cin >> studentuSkaicius;

                if (cin.fail() || (studentuSkaicius < 1)) {
                    throw invalid_argument( "Nevalidus pasirinkimas. Prasome ivesti studentu skaiciu.");
                } else {
                    break;
                }
            }catch (invalid_argument e){
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }


        bool generuotiPaz;
        while(true){
        try{
            cout << "Sugeneruoti pazymius atsitiktinai(0 - NE, 1 - TAIP):";
            cin >> generuotiPaz;

            if(cin.fail() || (generuotiPaz != 0 && generuotiPaz != 1)){
                throw invalid_argument("Nevalidus pasirinkimas. Prasome ivesti 0 arba 1.");
            }else{
                break;
            }
        }catch (invalid_argument e){
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

        vector <Studentas> studentai(studentuSkaicius);

        for (int i = 0; i < studentuSkaicius; i++) {
            cout << "Iveskite " << i + 1 << " studento varda: ";
            cin >> studentai[i].var;

            cout << "Iveskite " << i + 1 << " studento pavarde: ";
            cin >> studentai[i].pav;

            if (generuotiPaz==0){
                 cout << "Iveskite " << i + 1 << " studento namu darbu rezultatus (baigti su -1): ";
                 while (true) {
                    try{
                        int pazymys;
                        cin >> pazymys;

                        if (cin.fail() || pazymys<-1 ||pazymys>10) {
                            throw invalid_argument( "Nevalidus pazymys. Prasome ivesti pazymius : ");
                        } else if (pazymys == -1) {
                            break;
                        } else {
                            studentai[i].paz.push_back(pazymys);
                        }
                    }catch (invalid_argument e){
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }


                while (true) {
                    try{
                        cout << "Iveskite " << i + 1 << " studento egzamino rezultata: ";
                        cin >> studentai[i].egz;

                        if (cin.fail() || studentai[i].egz<1 ||studentai[i].egz>10) {
                            throw invalid_argument( "Nevalidus rezultatas. Prasome ivesti pazymi.");
                        } else {
                            break;
                        }
                    }catch (invalid_argument e){
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }



            }else{
                srand(time(NULL));
                int ndkiekis;
                int pazymys;
                while (true) {
                    try{
                        cout << "Kiek norite pazymiu? ";
                        cin >> ndkiekis;

                        if (cin.fail() || (ndkiekis<0)) {
                            throw invalid_argument( "Nevalidus pasirinkimas. Prasome ivesti pazymiu kieki.");
                        } else {
                            break;
                        }
                    }catch (invalid_argument e){
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

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
        spausdintiDuomenis(studentai, naudotiMediana,naudotiFaila);
    }
    return 0;
}

