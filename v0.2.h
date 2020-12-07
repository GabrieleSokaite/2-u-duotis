#ifndef UNTITLED_IOSTREAM_INPUT_H
#define UNTITLED_IOSTREAM_INPUT_H

#include "main_header.h"
#include "studentas.h"

void varT(std::vector<Studentas>& stud, int y);
void pavT(std::vector<Studentas>& stud, int y);
void fTikrinti(int &f);
void ivestiEgz(std::vector<Studentas>& stud, int y, int f);
void ivestiNd(std::vector<Studentas>& stud, int y, int f);
void generuoti( std::vector<Studentas>& stud, int &VAR, int &PAV );
bool blogasPav(const string a);
void ndGen(std::vector<Studentas>& stud, int x, int y);
void egGen(std::vector<Studentas>& stud, int y);
void galutinis(std::vector<Studentas>& stud, int x, int y);
void stringT (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,std::vector<Studentas> &stud, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<Studentas> &stud, int y, bool &fail, int eil);
void rikiuoti(std::vector<Studentas>& stud);

#endif //UNTITLED_IOSTREAM_INPUT_H
