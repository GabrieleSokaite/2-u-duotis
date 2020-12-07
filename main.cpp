#include "headers/main_header.h"
#include "headers/studentas.h"

int main() {

	std::vector<Studentas> stud;
	std::vector<Studentas> vargsiukaii;

	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	int VAR = 0, PAV = 0;
	static const int N = 100;

	start_c(start);
	generuotiFaila(N);
	end_c(end);
	std::chrono::duration<double> time1 = end - start;
	cout << "Failo generavimas uztruko: " << time1.count() << "sec." << endl;
	skaityti(stud, VAR, PAV, N);
	start_c(start);
	vargsiukaii = vargsiukai(stud);
	end_c(end);
	std::chrono::duration<double> time2 = end - start;
	cout << "Vector rusiavimas uztruko: " << time2.count() << "sec." << endl;
	start_c(start);
	spausdinti(stud, vargsiukaii, VAR, PAV);
	end_c(end);
	std::chrono::duration<double> time3 = end - start;
	cout << "Vector spausdinimas uztruko: " << time3.count() << "sec." << endl;
	stud.resize(1);

    Studentas a;
    Studentas b;
    cin >> a;
    b = a;
    cout << a;
    cout << b;
    cin >> b;
    cout << a;
    cout << b;
    if(a == b) cout << a.get_name() << " vienodas balas su  " << b.get_name() << endl;
    if(a != b) cout << a.get_name() << " kitoks balas nei " << b.get_name() << endl;
    if(a > b) cout << a.get_name() << " didesnis balas uz " << b.get_name() << endl;
    else if (b > a) cout << b.get_name() << " didesnis balas uz " << a.get_name() << endl;
    if(b < a) cout << b.get_name() << " mazesnis balas uz " << a.get_name() << endl;
    else if (a < b) cout << a.get_name() << " mazesnis balas uz " << b.get_name() << endl;

    return 0;
}