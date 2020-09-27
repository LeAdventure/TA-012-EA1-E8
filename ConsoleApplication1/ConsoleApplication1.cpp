#include <iostream>
#include <string>
#include <regex>
#include <locale>

using namespace std;

//		[0-9]+[^a-rt-zA-RT-Z0-9][^a-su-zA-RT-Z0-9][^a-rt-zA-RT-Z0-9][.][^a-zA-Z02-9][^a-zA-Z0-79][^a-zA-Z0-35-9][^a-zA-Z0-689][^a-zA-Z0-24-9][^a-zA-Z02-9][^a-zA-Z0-689]
// 		[0-9]+[^a-rt-zA-RT-Z\d][^a-su-zA-RT-Z\d][^a-rt-zA-RT-Z\d][.][^a-zA-Z02-9][^a-zA-Z0-79][^a-zA-Z0-35-9][^a-zA-Z0-689][^a-zA-Z0-24-9][^a-zA-Z02-9][^a-zA-Z0-689]

// 		[0-9][13478A-Za-z.]*[.]1847317
//      [0-9][13478A-Za-z.]*\.1847317


//      3sts.terrazas1sts.1.1847317 
//      1sts.1847317
//      0sts.1847317

int main() {
    setlocale(LC_ALL, "");
    string str;
    int p = 0;
    cout << "Nombre usado: Sebastian Terrazas Santillana \tMatricula usada: 1847317" << endl << endl;
    cout << "Ingrese una cadena de caracteres: ";
    fflush(stdin);
    getline(cin, str);
    regex e("[13478][13478A-Za-z\.]*\.1847317");
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

