#include <iostream>
#include <string>
#include <regex>
#include <locale>

using namespace std;

//      Tests
//      3sts.terrazas1sts.1.1847317    -     Caso Valido
//      3sts.terrazas1.1.1847317       -     Caso Valido
//      1sts.1847317                   -     Caso Valido
//      3.terrazas1.1.1847317          -     Caso Invalido
//      3.terrstsazas1.1.1847317       -     Caso Valido
//      sts.1847317                    -     Caso Invalido

int main() {
    setlocale(LC_ALL, "");
    string str, cont;
    int p = 0;

    do{
        system("cls");
        cout << "Nombre: Sebastian Terrazas Santillana \tMatricula: 1847317" << endl;
        cout << "Alfabeto = { 1, 3, 4, 7, 8, a, b, e, i, l, n, s, t, r, z, '.' }" << endl << endl; 
        cout << "Ingrese una cadena de caracteres: ";
        fflush(stdin);
        getline(cin, str);
        regex e("[13478][13478abeilnstrz\.]*\.1847317");
        regex f("sts.", regex_constants::icase);
        regex g("^(?!.*[.]{2})", regex_constants::icase);

        bool match1 = regex_match(str, e);
        bool match2 = regex_search(str, f);
        bool match3 = regex_search(str, g);
        bool match;

        if (match1 == true)
            if (match2 == true)
                if (match3 == true)
                    match = true;
                else
                    match = false;
            else
                match = false;
        else
            match = false;
        
        if (match == true)
            cout << "Caso Valido" << endl;
        else
            cout << "Caso Invalido" << endl;

        do {
            cout << "¿Desea continuar ingresando cadenas? [S/N]" << endl;
            fflush(stdin);
            getline(cin, cont);
            cont[0] = toupper(cont[0]);
            if (cont != "S" && cont != "N") {
                cout << "Por favor, ingrese una respuesta valida" << endl << endl;
            }
        }while (cont != "S" && cont != "N");
    }while (cont == "S");


    cout << "Gracias por probar el programa" << endl;
    getchar();

}

