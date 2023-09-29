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


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::max;
using std::ifstream;
using std::getline;
using std::stringstream;




struct Studentas{
    string var, pav;
    vector <int> paz;
    int egz;
    float rez;
};








float vidurkis(const vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}







float mediana(const vector<int> pazymiai) {
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






float skaiciuotiGalutiniBala(const Studentas studentas, bool naudotiMediana) {
    if (naudotiMediana==1){
        return 0.4 * mediana(studentas.paz) + 0.6 * studentas.egz;
    }else{
        return 0.4 * vidurkis(studentas.paz) + 0.6 * studentas.egz;
    }

}








int GetRandomPaz(int min, int max){
  int num = min + rand() % (max - min + 1);
  return num;
}





int CountLinesInFile(string filename)
{
  ifstream F(filename);
  if (!F)
  {
    return -1;
  }
  int count = 0;
  char buffer[1000];
  while (!F.eof())
  {
    count++;
    F.getline(buffer, 1000);
  }
  F.close();
  return count;
}
int countColumns(string failoPavadinimas) {
    int cols = 0;

    ifstream file(failoPavadinimas);
    if (file.is_open()) {
        string line;
        if (getline(file, line)) {
            stringstream ss(line);
            string item;
            while (ss >> item) {
                cols++;
            }
        }
        file.close();
    }

    return cols;
}







void nuskaitytiDuomenisIsFailo(string failoPavadinimas, vector<Studentas>& studentai) {
    ifstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return;
    }
    string pirmojiEilute;
    getline(failas, pirmojiEilute);

    int cols;
    cols=countColumns(failoPavadinimas);
    cout<<cols<<endl;
    int k=CountLinesInFile(failoPavadinimas);
    cout<<k<<endl;
    for (int i=0; i<k-1; i++){
        Studentas studentas;
        failas >> studentas.pav >> studentas.var;
        int pazymys;

        for(int i = 0; i < cols-3; i++){
            failas >> pazymys;
            studentas.paz.push_back(pazymys);
        }

        failas >> studentas.egz;


    studentai.push_back(studentas);
    }

    //for (Studentas stud: studentai) {
      //      cout << "NEXT STUD" << "\n";

        //    cout<< "\n" << stud.var << " " << stud.pav << "\n";
          //  for(int ocenka : stud.paz){
            //    cout << ocenka << " ";
            //}
            //cout << "egz = " << stud.egz << "\n\n";
        //}





}










void spausdintiDuomenis(const vector<Studentas> studentai, bool naudotiMediana){
    printf("\nStudentu duomenys:\n");
    printf("----------------------------------------------------------\n");
    if (naudotiMediana==1){
        printf("%10s%20s%20s\n", "Vardas","Pavarde","Galutinis(Med.)");
    }else{
        printf("%10s%20s%20s\n", "Vardas","Pavarde","Galutinis(Vid.)");
    }
    printf("----------------------------------------------------------\n");
    for (const Studentas studentas : studentai) {
        printf("%10s%20s%20.2f\n", studentas.var.c_str(), studentas.pav.c_str(), studentas.rez);
    }

}
#endif // MYLIB_H_INCLUDED
