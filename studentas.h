#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H

#include "main_header.h"

class Studentas {
private:
    string vardas, pavarde;
    int egzaminas;
    std::vector<int > nd;
public:
    Studentas() : egzaminas(0) { };
    double vidG = 0;
    double medG = 0;
    void set_name(string &a){ vardas = a; };
    void set_lastname (string &a) {pavarde = a; };
    string get_name() {return vardas; };
    string get_lastname() {return pavarde; };
    void set_exam (int a);
    int get_exam() {return egz; };
    void set_mark(int a);
    double ndSum(int x);
    double mediana(int x, int y);

};

int ndSk(std::ifstream &df);
void generuoti(int x);
void skaityti(std::vector<Studentas> &stud, int &VAR, int &PAV, int N);
void rusiuoti(std::vector<Studentas>& stud);
bool neturiSkolos(const Studentas& s);
std::vector<Studentas> vargsiukai(std::vector<Studentas>& stud);
void spausdinti( std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int VAR, int PAV);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

#endif //UNTITLED_STUDENTAS_H
