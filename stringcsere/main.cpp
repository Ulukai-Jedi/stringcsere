#include <iostream>
#include <string>

/*1. Bek�rsz egy sz�veget, bek�rsz egy sz�t (keresett), 
bek�rsz m�g egy m�sik sz�t (csere) �s lecser�led a 
sz�vegben az �sszes megtal�lt keresett sz� el�fordul�st a 
cser�lend� sz�ra. [nem haszn�lva substringet, meg egyebeket, 
csak mint karaktert�mb kezelve a stringet]*/

/*a feladat esetleges r�szegys�gei
- keress meg egy karaktert egy sz�vegben
- cser�lj le egy karaktert egy sz�vegben
- cser�lj le egy karakter �sszes el�fordul�s�t egy sz�vegben
- keress meg egy karakter sorozatot egy sz�vegben
- cser�lj le egy karakter sorozatot egy sz�vegben
- cser�ljed le az �sszes el�fordul�s�t egy karakter sorozatnak egy sz�vegben
*/

/*
int main() {
	std::string nev;
	std::cout << "Irj be egy nevet: ";
	std::cin >> nev;
	std::cout << "Hello " << nev << "!" << std::endl;
}*/

/*
int main()
{
	std::string szoveg;
	char keresett;
	unsigned keresettdarab = 0;
		
	std::cout << "Kerlek add meg a hasznalni kivant szoveged: ";
	std::getline(std::cin, szoveg);

	std::cout << "Kerlek ird be a keresett karaktert: ";
	std::cin >> keresett;

	int meret = szoveg.length();
		for (int i = 0; i < meret; i++) {
		if ( szoveg[i] == keresett ) {
			keresettdarab = keresettdarab + 1;
		}
	}
		std::cout << keresettdarab;
}*/
// lecser�led a megtal�lt karaktereket egy m�sik karakterre, �s a v�g�n ki�rod az �j sz�veget, amit kapt�l
/*int main()
{
	std::string szoveg;
	char keresett;
	char ujkarakter{};
	
	std::cout << "Kerlek add meg a hasznalni kivant szoveged: ";
	std::getline(std::cin, szoveg);

	std::cout << "Kerlek ird be a keresett karaktert: ";
	std::cin >> keresett;

	int meret = szoveg.length();
	for (int i = 0; i < meret; i++) {
		if (szoveg[i] == keresett) {
			std::cout << "Adj meg egy uj karaktert a keresett helyere: " << std::endl;
			std::cin >> ujkarakter;
			szoveg[i] = ujkarakter;
		}
	}
	std::cout << "A keresed szerint modositott szoveg a kovetkezo: " << szoveg << std::endl;
}

int main()
{
	std::string szoveg;
	char keresett [20];
	char ujkarakter [20];

	std::cout << "Kerlek add meg a hasznalni kivant szoveged: ";
	std::getline(std::cin, szoveg);

	std::cout << "Kerlek ird be a keresett karaktersorozatot: ";
	std::cin >> keresett;

	int meret = szoveg.length();
	for (int i = 0; i < meret; i++) {
		if (szoveg[i] == keresett[i]) {
			std::cout << "Adj meg egy uj karaktersorozatot a keresett helyere: " << std::endl;
			std::cin >> ujkarakter;
			szoveg[i] = ujkarakter[i];
		}
	}
	std::cout << "A keresed szerint modositott szoveg a kovetkezo: " << szoveg << std::endl;
}

int abszolut(const int szam) {
	if (szam < 0) {
		std::cout << "negativ" << std::endl;
		return szam * -1;
	}
	else {
		return szam;
	}
	std::cout << "almafa" << std::endl;
}
*/

bool charequals(const char aktualis, const char keresett) {
	return aktualis == keresett;
}

bool stringequals(const std::string& szoveg, const int pozicio, const std::string& keresett) {
	if (szoveg.length() - keresett.length() < pozicio) {
		return false;
	}
	for (int i = 0; i < keresett.length(); i++) {
		if (!charequals(szoveg[pozicio+i], keresett[i])) {
			return false;
		}
	}
	return true;
}


int main()
{
	std::string szoveg;
	std::string keresett;
	std::string ujszoveg;

	std::cout << "Kerlek add meg a hasznalni kivant szoveged: ";
	std::getline(std::cin, szoveg);

	std::cout << "Kerlek ird be a keresett karaktert: ";
	std::cin >> keresett;

	std::cout << "Adj meg egy uj karaktert a keresett helyere: " << std::endl;
	std::cin >> ujszoveg;

	int meret = szoveg.length();
	for (int i = 0; i < meret; i++) {
		if (stringequals(szoveg, i, keresett)) {
			for (int k = 0; k < ujszoveg.length(); k++) {
				szoveg[i+k] = ujszoveg[k];
			}
		}
	}
	std::cout << "A keresed szerint modositott szoveg a kovetkezo: " << szoveg << std::endl;
}