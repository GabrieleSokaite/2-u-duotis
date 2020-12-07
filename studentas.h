#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H

#include "main_header.h"

class Studentas {
private:
	string vardas, pavarde;
	int egzaminas;
	double vidG;
	std::vector<int > nd;
public:
    Studentas() : vardas(" "), pavarde(" "), egzaminas(0), vidG(0){ };
    void set_vidG (double &a) { vidG = a; };
    double get_vidG() const { return vidG; };
    double medG = 0;
    void set_name(string &a){ vardas = a; };
    void set_lastname (string &a) {pavarde = a; };
    string get_name() const {return vardas; };
    string get_lastname() const {return pavarde; };
    void set_exam (int a);
    int get_exam() {return egzaminas; };
    void set_mark(int a);
    double ndSum(int x);
    double mediana(int x, int y);
    friend bool operator== (const Studentas &a, const Studentas &b) { return a.get_vidG() == b.get_vidG(); };
    friend bool operator!= (const Studentas &a, const Studentas &b) { return a.get_vidG() != b.get_vidG(); };
    friend std::ostream& operator << (std::ostream &out, const Studentas a)
	{
        out << std::left <<  std::setw(13+3) << a.get_name() << std::setw(14+3) << a.get_lastname();
        out << std::setw(17) << std::fixed << std::setprecision(2) << a.get_vidG() << endl;
        return out;
    };
    friend std::istream &operator >> (std::istream & in, Studentas & a) {
        cout << "Iveskite varda: " << endl;
        in >> a.vardas;
        cout << "Iveskite pavarde: " << endl;
        in >> a.pavarde;
        cout << "Iveskite nd skaiciu: ";
        int n;
        in >> n;
        int q, sum = 0;
        for(int u=0; u<n; u++)
		{
            cout << "Iveskite nd pazymi: " << endl;
            in >> q;
            if(!in.fail() && q >= 0 && q <= 10)
			{
                if(q!=0)
				{
                    a.set_mark(q);
                    sum = sum + q;
                }
            }
            else
			{
                cout << "Netinka pazymys, iveskite kita: " << endl;
                in.clear();
                in.ignore(256, '\n');
                u--;
                continue;
            }
        }
        while(true)
		{
            int eg = 0;
            cout << "Iveskite egzamino bala: " << endl;
            in >> eg;
            if( !in.fail() && eg>= 0 && eg <= 10)
			{
                if(eg!=0)
				{
                    a.egzaminas = eg;
                    break;
                }
            }
            else
			{
                cout << "Netinka pazymys, iveskite kita: " << endl;
                in.clear();
                in.ignore(256, '\n');
                continue;
            }
        }
        double galutinis;
        galutinis =  0.4 * sum/n + 0.6 * a.get_exam();
        a.set_vidG(galutinis);
        return in;
    };
    friend bool operator > (const Studentas &a, const Studentas &b) { return a.get_vidG() > b.get_vidG(); };
    friend bool operator < (const Studentas &a, const Studentas &b) { return a.get_vidG() < b.get_vidG(); };

    Studentas& operator= (const Studentas &a)
	{
        if(a == *this) return *this;
        vardas = a.get_name();
        pavarde = a.get_lastname();
        vidG = a.get_vidG();
        return *this;
    };
};

int ndSk(std::ifstream& df);
void generuoti(int x);
void skaityti(std::vector<Studentas>& stud, int& VAR, int& PAV, int N);
void rusiuoti(std::vector<Studentas>& stud);
bool neturiSkolos(const Studentas& s);
std::vector<Studentas> vargsiukai(std::vector<Studentas>& stud);
void spausdinti(std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int VAR, int PAV);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock>& start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock>& end);

#endif //UNTITLED_STUDENTAS_H
