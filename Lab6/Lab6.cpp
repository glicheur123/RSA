// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>

#define MIN_VALUE 1000
#define ERROR_FACTEUR -1

using namespace std;

/// <summary>
/// Cette fonction permet de déterminer si un nombre est premier.
/// </summary>
/// <param name="n">le nombre à vérifier</param>
/// <returns>retourne si oui ou non le nombre est premier.</returns>
bool nombrePremier(int n) {
    int count = 0;
    // vésrifie combien de fois le nombre poss�de une division entière.
    for (int i = 2; i < n + 1; i++) {
        if ((n % i) == 0) {
            count++;
        }
    }

    // s'il y a plusieurs divisions possibles, le nombre n'est pas premier, sinon, oui.
    if (count > 1) {
        return false;
    }
    return true;
}

int nombrePremierFacteur(int n) {
    for (unsigned int i = 2; i < n + 1; i++) {
        if ((n % i) == 0) {
            if (nombrePremier(i)) {
                return i;
            }
        }
    }

    return ERROR_FACTEUR;
}


string to_format(const int number) {
    stringstream ss;
    ss << setw(2) << setfill('0') << number;
    return ss.str();
}

uint64_t modPow(uint64_t base, uint64_t exp, uint64_t modulus) {
    base %= modulus;
    uint64_t result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}


int main()
{

    int p, q, e,n;

    while (true) {
        cout << "Veuillez entrer P : ";
        cin >> p;

        if (!nombrePremier(p)) {
            cout << "ERREUR : P DOIT ETRE PREMIER!!" << endl;
            continue;
        }

        cout << "Veuillez entrer Q : ";
        cin >> q;

        if (!nombrePremier(q)) {
            cout << "ERREUR : Q DOIT ETRE PREMIER!!" << endl;
            continue;
        }

        n = p * q;
        if (n < MIN_VALUE) {
            cout << "ERREUR : VOUS DEVEZ ENTRER DEUX VALEURS AVEC DE GRAND NOMBRE!!" << endl;
            continue;
        }

        cout << "Valeur e : ";
        cin >> e;

        if (!nombrePremier(e)) {
            cout << "ERREUR : LE FACTEUR A MAL ÉTÉ CALCULÉ... REPRISE EN COURS.." << endl;
            continue;
        }
        break;

    }

    cout << "Veuillez entrer votre message : ";
    string m;
    cin >> m;

    string numbers;

    for (char c : m) {
        numbers += to_format((int)(c- '@'));
    }

    cout << "Nombre du message : " << numbers << endl;

    reverse(numbers.begin(), numbers.end());
    cout << "Reversed" << endl;
    vector<int> chunk = vector<int>(0);

    while (true) {
        if ((numbers.length() % 3) != 0) {
            numbers.push_back('0');
        }else{
            break;
        }
    }

    for (char t : numbers) {
        cout << t;
    }

    cout << endl;

    unsigned int dive = (int)numbers.length() / 3;

    cout << "div entiere :" << dive << endl;

    reverse(numbers.begin(), numbers.end());

    for (unsigned int i = 0; i < dive; i++) {
        string value = "";
        for (unsigned int j = 0; j < 3; j++) {
            value += numbers[3*i + j];
         }

        chunk.push_back(stoi(value));

    }

    cout << "Chunk : ";
    for (int ch : chunk) {
        cout << "-" << ch;
    }
    cout << endl;

    vector<long> RSA = vector<long>(0);

    for (int ch : chunk) {
        cout << "Ch : " << ch << endl;
        //double c1 = ;
        //cout << "POW :" << c1 << endl;
        uint64_t test = modPow(ch, e, n);
        RSA.push_back(test);
    }

    cout << "Message encode : ";
    for (int r : RSA) {
        cout << r << "-";
    }

    cout << endl;
    system("pause");



    return 0;
}