#include <iostream>
#include <string>
#include <regex>
#include <locale>

using namespace std;
//      Tests
//      3sts.terrazas1sts.1.1847317 
//      1sts.1847317

int main() {
    setlocale(LC_ALL, "");
    string str;
    int p = 0;
    cout << "Nombre usado: Sebastian Terrazas Santillana \tMatricula usada: 1847317" << endl;
    cout << "Alfabeto = { 1, 3, 4, 7, 8, a, b, e, i, l, n, s, t, r, z, '.' }"; 
    cout << "Ingrese una cadena de caracteres: ";
    fflush(stdin);
    getline(cin, str);
    regex e("[13478][13478abeilnstrz\.]*\.1847317");
    regex f("sts.", regex_constants::icase);

    bool match1 = regex_match(str, e);
    bool match2 = regex_search(str, f);
    bool match;

    if (match1 == true)
        if (match2 == true)
            match = true;
        else
            match = false;
    else
        match = false;
        
    cout << (match ? "Matched" : "Not Matched") << endl;

}

