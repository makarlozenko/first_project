#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;




struct Studentas{
    string var, pav;
    vector <int> paz;
    int egz;
    float rez;
    float vidurkis;
};

float vidurkis(const vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float skaiciuotiGalutiniBala(const Studentas studentas) {
    return 0.4 * vidurkis(studentas.paz) + 0.6 * studentas.egz;
}

void spausdintiDuomenis(const vector<Studentas> studentai){
    printf("\nStudentu duomenys:\n");
    printf("----------------------------------------------------------\n");
    printf("%10s%10s%20s\n", "Vardas","Pavarde","Galutinis(Vid.)\n");
    printf("----------------------------------------------------------\n");
    for (const Studentas studentas : studentai) {
        printf("%10s%10s%20.2f\n", studentas.var.c_str(), studentas.pav.c_str(), studentas.rez);
    }

}
#endif // MYLIB_H_INCLUDED
