#include "../headers/main_header.h"
#include "../headers/studentas.h"
#include "../headers/deque_header.h"

void skaityti(std::deque<studentas>& stud, int& VAR, int& PAV)
{
	std::ifstream df(data);
	if (!df) throw "Failas su duomenimis nerastas.";
	int i = 0, eil = 0, n = ndSk(df);
	stud.emplace_back(studentas());
	while (true)
	{

		if (df.eof() == 1) break;
		eil++;
		df >> stud[i].vardas >> stud[i].pavarde;
		if (stud[i].vardas.length() > VAR) VAR = stud[i].vardas.length();
		if (stud[i].pavarde.length() > PAV) PAV = stud[i].pavarde.length();
		int q, sum = 0;
		for (int u = 0; u < 6; u++)
		{
			df >> q;
			stud[i].nd.emplace_back(q);
			sum = sum + q;
		}
		df >> stud[i].egzaminas;
		stud[i].vidG = 0.4 * sum / n + 0.6 * stud[i].egzaminas;
		if (df.eof() == 1) break;
		i++;
		stud.emplace_back(studentas());
	}
	df.seekg(0);
	df.clear();
	stud.shrink_to_fit();
};

void rusiuoti(std::deque<studentas>& stud)
{
	sort(stud.begin(), stud.end(), [](const studentas& lhs, const studentas& rhs)
		{
			return (lhs.vidG > rhs.vidG);
		});
};

void skirstyti(std::deque<studentas>& stud, std::deque<studentas>& vargsiukai, int x)
{
	rusiuoti(stud);
	int i = x, k = 0;
	while (stud[i].vidG < 5)
	{
		k++;
		i--;
	}
	std::move(stud.end() - k, stud.end(), std::back_inserter(vargsiukai));
	stud.erase(stud.end() - k, stud.end());
}

void skirstyti2(std::deque<studentas>& stud, std::deque<studentas>& vargsiukai, std::deque<studentas>& galvociai, int x)
{
	rusiuoti(stud);
	int i = x, k = 0;
	while (stud[i].vidG < 5)
	{
		k++;
		i--;
	}
	std::move(stud.begin(), stud.end() - k - 2, std::back_inserter(galvociai));
	std::move(stud.end() - k, stud.end(), std::back_inserter(vargsiukai));
}

void spausdinti(std::deque<studentas> stud, std::deque<studentas> vargsiukai, int VAR, int PAV)
{
	std::ofstream gs("galvociai.txt");
	std::ofstream bs("vargsiukai.txt");

	gs << std::left << std::setw(VAR + 3) << "vardas";
	gs << std::setw(VAR + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   " << endl;
	for (int w = 0; w < (VAR + PAV + 6 + 14); w++) gs << "-"; gs << endl;
	for (auto& i : stud)
	{
		gs << std::left << std::setw(VAR + 3) << i.vardas << std::setw(PAV + 3) << i.pavarde;
		gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
	}
	gs.close();
	bs << std::left << std::setw(VAR + 3) << "vardas";
	bs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   " << endl;
	for (int w = 0; w < (VAR + PAV + 6 + 14); w++) bs << "-"; bs << endl;
	for (auto& i : vargsiukai)
	{
		bs << std::left << std::setw(VAR + 3) << i.vardas << std::setw(PAV + 3) << i.pavarde;
		bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
	}
	bs.close();
};