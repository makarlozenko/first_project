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
