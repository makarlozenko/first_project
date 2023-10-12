#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::sort;
using std::invalid_argument;
using std::cerr;
using std::to_string;
using std::left;
using std::setw;
using std::ios;

using namespace std::chrono;


struct Studentas{
    string var, pav, kategorija;
    vector <int> paz;
    int egz;
    float rez, rezv, rezm;
};


float vidurkis(vector<int> pazymiai);
float mediana(vector<int> pazymiai);
float skaiciuotiGalutiniBala(Studentas studentas, bool naudotiMediana);
int GetRandomPaz(int minimum, int maximum);
int kiekEiluciu(string failoPavadinimas);
int kiekStulp(string failoPavadinimas);
void nuskaitytiDuomenisIsFailo(string failoPavadinimas, vector<Studentas>& studentai);
bool palygStudentByKat(Studentas a, Studentas b);
void rusiuotiDuomenisIsGeneruotoFailo(string failoPavadinimas, int sKiekis, duration<double> diff, int t, double &suma);
bool palygStudentByVar(Studentas a, Studentas b);
void spausdintiDuomenis(vector<Studentas> studentai, bool naudotiMediana, bool naudotiFaila);

#endif // MYLIB_H_INCLUDED
