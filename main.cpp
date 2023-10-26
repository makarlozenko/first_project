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

            bool senasnaujas;
            while(true){
                try{
                    cout << "Naudosim sena '0' arba nauja '1' faila: ";
                    cin >> senasnaujas;

                    if(cin.fail() || (senasnaujas != 0 && senasnaujas != 1)){
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
            string naujasFailas;
            int sKiekis;
            int ndKiekis;

            if (senasnaujas==0){

                cout << "Iveskite seno failo pavadinima: ";
                cin >> naujasFailas;
            } else {
                cout << "Iveskite naujo failo pavadinima: ";
                cin >> naujasFailas;

                cout<<"Kiek norite studentu? ";
                cin>>sKiekis;

                cout<<"Kiek norite namu darbu? ";
                cin>>ndKiekis;
            }

            string rusiuoti;
            cout <<"Rusiuoti pagal pasirnkta parametra: v - varda, p-pavarde, gp - galutini pazymi: ";
            cin >> rusiuoti;

            double suma=0;
            double sumaNusk=0;
            double sumaRus=0;
            double sumaKiet=0;
            double sumaVarg=0;

            for (int t=1; t<=testuSk; t++){
                list<Studentas> studentai; //-------------------------------------//

                auto start = high_resolution_clock::now();

                if (checkFile(naujasFailas+to_string(t)+".txt")){
                    string egzfailas = naujasFailas+to_string(t)+".txt";
                    cout << "Failas jau egzistuoja"<<endl;

                    for (int t=1; t<=testuSk; t++){
                        auto end = high_resolution_clock::now();
                        duration<double> diff = start-start;
                        rusiuotiDuomenisIsEgzistFailo(egzfailas, sKiekis,  diff, t, suma, rusiuoti, sumaNusk,sumaRus,sumaKiet,sumaVarg);
                    }
                    break;
                }else{
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
                        studentas.paz.push_front(pazymysF);//-------------------//
                    }
                    studentas.egz = GetRandomPaz(1, 10);

                    studentai.push_front(studentas);//----------------//
                }


                nFailas <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde";
                for (int j=1; j<=ndKiekis; j++){
                    nFailas << left << setw(5) << "ND"+to_string(j);
                }
                nFailas << left << setw(20) << "Egzaminas"<<endl ;

                for (Studentas student : studentai) {
                    nFailas << left << setw(30) << student.var << left << setw(30)  << student.pav ;
                    for (int paz : student.paz){
                        nFailas << left << setw(5) << paz;
                    }
                    nFailas << left << setw(20) << student.egz<<endl;
                }
                nFailas.close();

                auto end = high_resolution_clock::now();
                duration<double> diff = end-start;
                cout << sKiekis << " elementu uzpildymas uztruko: "<< diff.count() << " s\n";

                rusiuotiDuomenisIsGeneruotoFailo(naujasFailas, sKiekis,  diff, t, suma,rusiuoti,sumaNusk,sumaRus,sumaKiet,sumaVarg);
                }


            }
            cout<<"Padarytu testu laiko vidurkis: "<<suma/testuSk<< " s"<<endl;
            cout<<"Failu nuskaitymu laiko vidurkis: "<<sumaNusk/testuSk<< " s"<<endl;
            cout<<"Failu rusiavimo laiko vidurkis: "<<sumaRus/testuSk<< " s"<<endl;
            cout<<"Kietakiu irasymo laiko vidurkis: "<<sumaKiet/testuSk<< " s"<<endl;
            cout<<"Vargsiuku irasymo laiko vidurkis: "<<sumaVarg/testuSk<< " s"<<endl;



        }else{
            list <Studentas> studentai;
            string failoPavadinimas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            nuskaitytiDuomenisIsFailo(failoPavadinimas, studentai);
            int eil=kiekEiluciu(failoPavadinimas);
            bool naudotiMediana;
            for (auto it = studentai.begin(); it != studentai.end(); ++it) { //auto it = studentai.begin(); it != studentai.end(); ++it
                naudotiMediana=1;
                (*it).rezm = skaiciuotiGalutiniBala((*it), naudotiMediana);
                naudotiMediana=0;
                (*it).rezv = skaiciuotiGalutiniBala((*it), naudotiMediana);
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

        list <Studentas> studentai(studentuSkaicius);
        int i=0;

        for (auto it = studentai.begin(); it != studentai.end(); ++it) {
            cout << "Iveskite " << i + 1 << " studento varda: ";
            cin >> (*it).var;

            cout << "Iveskite " << i + 1 << " studento pavarde: ";
            cin >> (*it).pav;

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
                            (*it).paz.push_front(pazymys);
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
                        cin >> (*it).egz;

                        if (cin.fail() || (*it).egz<1 ||(*it).egz>10) {
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
                    (*it).paz.push_back(pazymys);
                    cout << pazymys << " ";
                }
                cout << endl;
                (*it).egz = GetRandomPaz(1, 10);
                cout << "Egzaminas: " << (*it).egz <<endl;

            }
            (*it).rez = skaiciuotiGalutiniBala((*it), naudotiMediana);
            i=+1;
        }
        spausdintiDuomenis(studentai, naudotiMediana,naudotiFaila);
    }
    return 0;
}
