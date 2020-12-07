#include "../headers/main_header.h"
#include "../headers/studentas.h"
#include "../headers/list_header.h"

void skaityti(std::list<studentas> &stud, int &VAR, int &PAV)
{
    std::list<studentas>::iterator it;
    std::ifstream df (data);
    if (!df) throw "Failas su duomenimis nerastas.";
    int i=0, eil=0, n = ndSk(df);
    stud.emplace_back(studentas());
    it = stud.begin();
    int a=0;
    while(true)
	{
        if (df.eof() == 1) break;
        eil++;
        df >> it->vardas >> it->pavarde;
        if (it->vardas.length() > VAR) VAR = it->vardas.length();
        if (it->pavarde.length() > PAV) PAV = it->pavarde.length();
        int q, sum=0;
        for(int u=0; u<6; u++)
		{
            df >> q;
            it->nd.emplace_back(q);
            sum = sum + q;
        }
        df >> it->egzaminas;
        it->vidG =  0.4 * sum/n + 0.6 * it->egzaminas;
        if(it->vidG>=5)a++;
        if (df.eof() == 1) break;
        i++;
        stud.emplace_back(studentas());
        it++;
    }
};

void rusiuoti(std::list<studentas>& stud)
{
    stud.sort([](const studentas &lhs, const studentas &rhs)
	{
        return ( lhs.vidG > rhs.vidG );
    });
};

void skirstyti(std::list<studentas>& stud, std::list<studentas>& vargsiukai)
{
    rusiuoti(stud);
    std::list<studentas>::iterator it;
    it = stud.begin();
    for(auto l : stud)
	{
        if(l.vidG >= 5) it++;
    }
    vargsiukai.splice(vargsiukai.begin(), stud, it, stud.end() );
}

void skirstyti2(std::list<studentas>& stud, std::list<studentas>& vargsiukai, std::list<studentas>& galvociai)
{
    rusiuoti(stud);
    std::list<studentas>::iterator it;
    it = stud.begin();
    for(auto l : stud)
	{
        if(l.vidG >= 5) it++;
    }
    galvociai.splice(galvociai.begin(), stud, stud.begin(), it);
    vargsiukai.splice(vargsiukai.begin(), stud, it, stud.end());
}

void spausdinti( std::list<studentas> stud, std::list<studentas> vargsiukai, int VAR, int PAV)
{
    std::ofstream gs ("galvociai.txt");
    std::ofstream bs ("vargsiukai.txt");

    gs << std::left << std::setw(VAR + 3) << "vardas";
    gs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   "  << endl;
    for(int w=0; w<(VAR + PAV + 6 + 14); w++) gs << "-"; gs <<endl;
    for (auto &i : stud)
	{
        gs << std::left <<  std::setw(VAR + 3) << i.vardas << std::setw(PAV + 3) << i.pavarde;
        gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    gs.close();
    bs << std::left << std::setw(VAR + 3) << "vardas";
    bs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   " << endl;
    for(int w=0; w<(VAR + PAV + 6 + 14); w++) bs << "-"; bs <<endl;
    for (auto &i : vargsiukai)
	{
        bs << std::left <<  std::setw(VAR + 3) << i.vardas << std::setw(PAV + 3) << i.pavarde;
        bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    bs.close();
};