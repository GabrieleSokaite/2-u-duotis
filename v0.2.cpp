#include "../headers/main_header.h"
#include "../headers/v0.2.h"

void varT(std::vector<studentas>& stud, int y)
{
	cout << "Iveskite varda: " << endl;
	cin >> stud[y].vardas;
	while (!blogasPav(stud[y].vardas))
	{
		cout << "Netinka vardas, iveskite kita: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> stud[y].vardas;
	}
}

void pavT(std::vector<studentas>& stud, int y)
{
	cout << "Iveskite pavarde: " << endl;
	cin >> stud[y].pavarde;
	while (!blogasPav(stud[y].pavarde))
	{
		cout << "Netinka pavarde, iveskite kita: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> stud[y].pavarde;
	}
}

void fTikrinti(int& f)
{
	while (f != 0 && f != 1)
	{
		cout << "Ivestas neteisingas simbolis, bandykite dar karta: " << endl;
		cin >> f;
	}
}

void ivestiEgz(std::vector<studentas>& stud, int y, int f)
{
	if (f == 1)
	{
		while (true)
		{
			int eg = 0;
			cout << "Iveskite egzamino rezultata: " << endl;
			cin >> eg;
			if (!cin.fail() && eg >= 0 && eg <= 10)
			{
				if (eg != 0)
				{
					stud[y].egzaminas = eg;
					break;
				}
			}
			else
			{
				cout << "Netinkamas pazymys, iveskite kita: " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
		}
	}
	else if (f == 0)
	{
		egGen(stud, y);
	}
}

void ivestiNd(std::vector<studentas>& stud, int y, int f)
{
	int k = 0, q = 1;
	if (f == 1)
	{
		cout << "Iveskite namu darbu rezultatus (spauskite 0 ivedus visus): " << endl;
		while (q != 0)
		{
			cout << "Iveskite namu darbu pazymi: " << endl;
			cin >> q;
			if (!cin.fail() && q >= 0 && q <= 10)
			{
				if (q != 0)
				{
					stud[y].nd.push_back(q);
					k++;
				}
			}
			else
			{
				cout << "Netinkamas pazymys, iveskite kita: " << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				q = 1;
				continue;
			}
		}
		galutinis(stud, k, y);
	}
	else if (f == 0)
	{
		cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti: " << endl;
		int n = 0;
		while (true)
		{
			cin >> n;
			if (!cin.fail() && n != 0)
			{
				break;
			}
			else
			{
				cout << "Ivestas blogas simbolis, reikia ivesti skaiciu: " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
		}
		ndGen(stud, n, y);
		galutinis(stud, n, y);
	}
}

void generuoti(std::vector<studentas>& stud, int& VAR, int& PAV)
{
	int i = 0, st = 0;
	stud.reserve(100);
	while (true)
	{
		cout << "Prideti studenta spauskite 1, o norint uzbaigti 0: " << endl;
		cin >> st;
		if (st == 1)
		{
			stud.emplace_back(studentas());
			int f;
			varT(stud, i);
			pavT(stud, i);
			if (stud[i].vardas.length() > VAR) VAR = stud[i].vardas.length();
			if (stud[i].pavarde.length() > PAV) PAV = stud[i].pavarde.length();
			cout << "Ivesti egzamino pazymi ranka spauskite 1, o norint atsitiktinai sugeneruoti 0: " << endl;
			cin >> f;
			fTikrinti(f);
			ivestiEgz(stud, i, f);
			cout << "Ivesti nd pazymius ranka, spauskite 1, o norint atsitiktinai sugeneruoti 0: " << endl;
			cin >> f;
			fTikrinti(f);
			ivestiNd(stud, i, f);
			i++;
		}
		else break;
	}
	stud.shrink_to_fit();
};

bool blogasPav(const string a)
{
	for (char i : a)
	{
		if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) return false;
	}
	return true;
}

void ndGen(std::vector<Studentas>& stud, int x, int y)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random(1, 10);
	int a;
	for (int j = 0; j < x; j++)
	{
		a = random(gen);
		stud[y].set_mark(a);
	}
}

void egGen(std::vector<Studentas>& stud, int y)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random(1, 10);
	stud[y].set_exam(random(gen));
}

void galutinis(std::vector<Studentas>& stud, int x, int y)
{
	stud[y].vidG = 0.4 * stud[y].ndSum(x) / x + 0.6 * stud[y].get_exam();
	stud[y].medGs = 0.4 * stud[y].mediana(x, y) + 0.6 * stud[y].get_exam();
}

void stringT(std::ifstream& df, string a, bool& fail, int eil)
{
	if (!blogasPav(std::move(a)))
	{
		df.clear();
		df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		fail = true;
		cout << "Ivestas netinkamas vardas arba pavarde " << eil << " eiluteje. Todel studento duomenys nenuskaityti. " << endl;
	}
}

void nd(std::ifstream& df, std::vector<Studentas>& stud, int x, int y, bool& fail, int eil)
{
	int q = 0;
	for (int j = 0; j < x; j++)
	{
		df >> q;
		if (!df.fail() && q > 0 && q <= 10)
		{
			stud[y].set_mark(q);
		}
		else
		{
			df.clear();
			df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			fail = true;
			cout << "Ivestas netinkamas nd pazymys " << eil << " eiluteje. Todel studento duomenys nenuskaityti." << endl;
			break;
		}
	}
}

void egz(std::ifstream& df, std::vector<Studentas>& stud, int y, bool& fail, int eil)
{
	int q = 0;
	df >> q;
	if (!df.fail() && q > 0 && q <= 10)
	{
		stud[y].set_exam(q);
	}
	else
	{
		df.clear();
		df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		fail = true;
		cout << "Ivestas netinkamas egzamino pazymys " << eil << " eiluteje. Todel studento duomenys nenuskaityti." << endl;
	}

}

void tikiuoti(std::vector<Studentas>& stud)
{
	sort(stud.begin(), stud.end(), [](const Studentas& lhs, const Studentas& rhs)
		{
			if (lhs.vardas != rhs.vardas)
			{
				return lhs.vardas < rhs.vardas;
			}
			else
			{
				return lhs.pavarde < rhs.pavarde;
			}
		});
}