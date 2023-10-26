#include "mylib.h"

float vidurkis(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float mediana(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0f;

    vector<int> sortedPazymiai = pazymiai;
    sort(sortedPazymiai.begin(), sortedPazymiai.end());

    int n = sortedPazymiai.size();
    if (n % 2 == 0) {
        int vid1 = sortedPazymiai[n / 2 - 1];
        int vid2 = sortedPazymiai[n / 2];
        return static_cast<float>(vid1 + vid2) / 2.0f;
    } else {
        return static_cast<float>(sortedPazymiai[n / 2]);
    }
}


float skaiciuotiGalutiniBala(Studentas studentas, bool naudotiMediana) {
    if (naudotiMediana==1){
        return 0.4 * mediana(studentas.paz) + 0.6 * studentas.egz;
    }else{
        return 0.4 * vidurkis(studentas.paz) + 0.6 * studentas.egz;
    }

}


int GetRandomPaz(int minimum, int maximum){
    int num = minimum + rand() % (maximum - minimum + 1);
    return num;
}


int kiekEiluciu(string failoPavadinimas){
    ifstream F(failoPavadinimas);
    int eilkiekis = 0;
    char buffer[1000];
    while (!F.eof()){
        eilkiekis++;
        F.getline(buffer, 1000);
    }
    F.close();
    return eilkiekis;
}


int kiekStulp(string failoPavadinimas){
    int stulp = 0;
    ifstream F(failoPavadinimas);
    string line;
    if (getline(F, line)){
        stringstream ss(line);
        string item;
        while (ss >> item){
            stulp++;
        }
    }
    F.close();
    return stulp;
}


void nuskaitytiDuomenisIsFailo(string failoPavadinimas, vector<Studentas>& studentai){
    ifstream failas(failoPavadinimas);
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }
    string pirmojiEilute;
    getline(failas, pirmojiEilute);

    int stulp=kiekStulp(failoPavadinimas);
    int eil=kiekEiluciu(failoPavadinimas);

    for (int i=0; i<eil-1; i++){
        Studentas studentas;
        failas >> studentas.var >> studentas.pav;
        int pazymys;

        for (int i = 0; i < stulp-3; i++){
            failas >> pazymys;
            if (pazymys>0 && pazymys<11) {
                studentas.paz.push_back(pazymys);
            }else{
                cout<<"Pazymys blogai ivestas. Jis buvo praleistas"<<endl;
            }
        }

        failas >> studentas.egz;
        studentai.push_back(studentas);
    }
    failas.close();
}

bool palygStudentByKat(Studentas a, Studentas b) {
    return a.kategorija < b.kategorija;
}

bool palygStudentByPav(Studentas a, Studentas b) {
    return a.pav < b.pav;
}

bool palygStudentByGp(Studentas a, Studentas b) {
    return a.rezv < b.rezv;
}



void rusiuotiDuomenisIsGeneruotoFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg){
    vector<Studentas> studentai;

    auto startS = high_resolution_clock::now();

    ifstream failas(failoPavadinimas+to_string(t)+".txt");
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }
    string pirmojiEilute;
    getline(failas, pirmojiEilute);

    int stulp=kiekStulp(failoPavadinimas+to_string(t)+".txt");
    int eil=kiekEiluciu(failoPavadinimas+to_string(t)+".txt");

    for (int i=0; i<eil-2; i++){
        Studentas studentas;
        failas >> studentas.var >> studentas.pav;
        int pazymys;

        for (int k = 0; k < stulp-3; k++){
            failas >> pazymys;
            if (pazymys>0 && pazymys<11) {
                studentas.paz.push_back(pazymys);
            }else{
                cout<<"Pazymys blogai ivestas. Jis buvo praleistas"<<endl;
            }
        }

        failas >> studentas.egz;

        bool naudotiMediana=1;
        studentas.rezm = skaiciuotiGalutiniBala(studentas, naudotiMediana);

        naudotiMediana=0;
        studentas.rezv = skaiciuotiGalutiniBala(studentas, naudotiMediana);

        if (studentas.rezv < 5.0) {
            studentas.kategorija = "Vargsiukas";
        } else {
            studentas.kategorija = "Kietakis";
        }
        studentai.push_back(studentas);
    }

    auto endS = high_resolution_clock::now();
    duration<double> diffS = endS-startS;
    cout << "Failo is " << sKiekis << " elementu nuskaitymas uztruko: "<< diffS.count() << " s\n";
    sumaNusk+=diffS.count();


    auto startR = high_resolution_clock::now();

    if (rusiuoti=="v"){
        sort(studentai.begin(), studentai.end(),palygStudentByVar);
    }else if (rusiuoti=="p"){
        sort(studentai.begin(), studentai.end(),palygStudentByPav);
    }else if (rusiuoti=="gp"){
        sort(studentai.begin(), studentai.end(),palygStudentByGp);
    }else {
        cout << "Neteisingai ivesta. Nebuvo surusiuota."<<endl;
    }

    auto endR = high_resolution_clock::now();
    duration<double> diffR = endR-startR;
    cout << "Failo is " << sKiekis << " elementu rusiavimas su sort funkcija uztruko: "<< diffR.count() << " s\n";
    sumaRus+=diffR.count();

    failas.close();

    auto startK = high_resolution_clock::now();

    ofstream failasRusK(failoPavadinimas+to_string(t)+"Kietakiai.txt");
    failasRusK <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde"<< left << setw(30) << "Galutinis vidurkis"<< left << setw(30) << "Galutine mediana"<< endl;
    for (Studentas student : studentai) {
        if (student.rezv > 5.0) {
            failasRusK << left << setw(30) << student.var << left << setw(30)  << student.pav << left << setw(30)  << student.rezv << left << setw(30)  << student.rezm << endl;
        }else{
            continue;
        }
    }
    failasRusK.close();

    auto endK = high_resolution_clock::now();
    duration<double> diffK = endK-startK;
    cout << "Failo is " << sKiekis << " elementu kietakiu irasymas i nauja faila uztruko: "<< diffK.count() << " s\n";
    sumaKiet+=diffK.count();

    auto startV = high_resolution_clock::now();

    ofstream failasRusV(failoPavadinimas+to_string(t)+"Vargsiukai.txt");
    failasRusV <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde"<< left << setw(30) << "Galutinis vidurkis"<< left << setw(30) << "Galutine mediana"<< endl;
    for (Studentas student : studentai) {
        if (student.rezv < 5.0) {
            failasRusV << left << setw(30) << student.var << left << setw(30)  << student.pav << left << setw(30)  << student.rezv << left << setw(30)  << student.rezm << endl;
        }else{
            continue;
        }
    }
    failasRusV.close();

    auto endV = high_resolution_clock::now();
    duration<double> diffV = endV-startV;
    cout << "Failo is " << sKiekis << " elementu vargsiuku irasymas i nauja faila uztruko: "<< diffV.count() << " s\n";
    sumaVarg+=diffV.count();

    double overall = diffV.count()+diff.count()+diffK.count()+diffR.count()+diffS.count();

    cout << "Failo is " << sKiekis << " elementu testo bendras laikas: "<< overall << " s\n";
    cout <<"-------------------------------------------------------------------------------------------"<<endl;
    suma+=overall;
}

void rusiuotiDuomenisIsEgzistFailo(string egzfailas, int sKiekis, duration<double> diff, int t, double &suma,string rusiuoti,double &sumaNusk,double &sumaRus,double &sumaKiet,double &sumaVarg){
    vector<Studentas> studentai;

    auto startS = high_resolution_clock::now();

    ifstream failas(egzfailas);
    if (!failas.is_open()){
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }
    string pirmojiEilute;
    getline(failas, pirmojiEilute);

    int stulp=kiekStulp(egzfailas);
    int eil=kiekEiluciu(egzfailas);

    for (int i=0; i<eil-2; i++){
        Studentas studentas;
        failas >> studentas.var >> studentas.pav;
        int pazymys;

        for (int k = 0; k < stulp-3; k++){
            failas >> pazymys;
            if (pazymys>0 && pazymys<11) {
                studentas.paz.push_back(pazymys);
            }else{
                cout<<"Pazymys blogai ivestas. Jis buvo praleistas"<<endl;
            }
        }

        failas >> studentas.egz;

        bool naudotiMediana=1;
        studentas.rezm = skaiciuotiGalutiniBala(studentas, naudotiMediana);

        naudotiMediana=0;
        studentas.rezv = skaiciuotiGalutiniBala(studentas, naudotiMediana);

        if (studentas.rezv < 5.0) {
            studentas.kategorija = "Vargsiukas";
        } else {
            studentas.kategorija = "Kietakis";
        }
        studentai.push_back(studentas);
    }

    auto endS = high_resolution_clock::now();
    duration<double> diffS = endS-startS;
    cout << "Failo is " << sKiekis << " elementu nuskaitymas uztruko: "<< diffS.count() << " s\n";
    sumaNusk+=diffS.count();



    auto startR = high_resolution_clock::now();

    if (rusiuoti=="v"){
        sort(studentai.begin(), studentai.end(),palygStudentByVar);
    }else if (rusiuoti=="p"){
        sort(studentai.begin(), studentai.end(),palygStudentByPav);
    }else if (rusiuoti=="gp"){
        sort(studentai.begin(), studentai.end(),palygStudentByGp);
    }else {
        cout << "Neteisingai ivesta. Nebuvo surusiuota."<<endl;
    }

    auto endR = high_resolution_clock::now();
    duration<double> diffR = endR-startR;
    cout << "Failo is " << sKiekis << " elementu rusiavimas su sort funkcija uztruko: "<< diffR.count() << " s\n";
    sumaRus+=diffR.count();

    failas.close();

    auto startK = high_resolution_clock::now();

    ofstream failasRusK(egzfailas+to_string(t)+"Kietakiai.txt");
    failasRusK <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde"<< left << setw(30) << "Galutinis vidurkis"<< left << setw(30) << "Galutine mediana"<< endl;
    for (Studentas student : studentai) {
        if (student.rezv > 5.0) {
            failasRusK << left << setw(30) << student.var << left << setw(30)  << student.pav << left << setw(30)  << student.rezv << left << setw(30)  << student.rezm << endl;
        }else{
            continue;
        }
    }
    failasRusK.close();

    auto endK = high_resolution_clock::now();
    duration<double> diffK = endK-startK;
    cout << "Failo is " << sKiekis << " elementu kietakiu irasymas i nauja faila uztruko: "<< diffK.count() << " s\n";
    sumaKiet+=diffK.count();

    auto startV = high_resolution_clock::now();

    ofstream failasRusV(egzfailas+to_string(t)+"Vargsiukai.txt");
    failasRusV <<left << setw(30) << "Vardas"<< left << setw(30) << "Pavarde"<< left << setw(30) << "Galutinis vidurkis"<< left << setw(30) << "Galutine mediana"<< endl;
    for (Studentas student : studentai) {
        if (student.rezv < 5.0) {
            failasRusV << left << setw(30) << student.var << left << setw(30)  << student.pav << left << setw(30)  << student.rezv << left << setw(30)  << student.rezm << endl;
        }else{
            continue;
        }
    }
    failasRusV.close();

    auto endV = high_resolution_clock::now();
    duration<double> diffV = endV-startV;
    cout << "Failo is " << sKiekis << " elementu vargsiuku irasymas i nauja faila uztruko: "<< diffV.count() << " s\n";
    sumaVarg+=diffV.count();

    double overall = diffV.count()+diff.count()+diffK.count()+diffR.count()+diffS.count();

    cout << "Failo is " << sKiekis << " elementu testo bendras laikas: "<< overall << " s\n";
    cout <<"-------------------------------------------------------------------------------------------"<<endl;
    suma+=overall;
}



bool palygStudentByVar(Studentas a, Studentas b) {
    return a.var < b.var;
}


void spausdintiDuomenis(vector<Studentas> studentai, bool naudotiMediana, bool naudotiFaila){
    printf("\nStudentu duomenys:\n");
    printf("---------------------------------------------------------------------------------------\n");

    sort(studentai.begin(), studentai.end(),palygStudentByVar);

    if (naudotiFaila==0){
        printf("%-25s%-25s%-20s%-20s\n", "Vardas","Pavarde","Galutinis(Vid.)","Galutinis(Med.)");
        printf("---------------------------------------------------------------------------------------\n");
        for (Studentas studentas : studentai) {
            printf("%-25s%-25s%-20.2f%-20.2f\n", studentas.var.c_str(), studentas.pav.c_str(), studentas.rezv,studentas.rezm);
        }
    }else if (naudotiMediana==1){
        printf("%-25s%-25s%-20s\n", "Vardas","Pavarde","Galutinis(Med.)");
        printf("--------------------------------------------------------------------------------------\n");
        for (Studentas studentas : studentai) {
            printf("%-25s%-25s%-20.2f\n", studentas.var.c_str(), studentas.pav.c_str(), studentas.rez);
        }
    }else{
        printf("%-25s%-25s%-20s\n", "Vardas","Pavarde","Galutinis(Vid.)");
        printf("--------------------------------------------------------------------------------------\n");
        for (Studentas studentas : studentai) {
            printf("%-25s%-25s%-20.2f\n", studentas.var.c_str(), studentas.pav.c_str(), studentas.rez);
        }
    }
    printf("----------------------------------------------------------------------------------------\n");


  }

    bool checkFile(string file_name) {
        ifstream file;
        file.open(file_name);
        if(!file){
            return false;
        }else{
            return true;
        }
    }
