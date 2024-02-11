#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char** args){

    //VARIABLES

    fstream archivo;
    string texto[1200] = {};

    //ABRIMOS EL ARCHIVO DE TEXTO DESDE EL ARGUMENTO

    archivo.open(args[1]); 

    //ASEGURAMOS DE QUE SE ABRIO CORRECTAMENTE

    if (!archivo.is_open()) {
        cout << "El archivo no se pudo iniciar" << endl; 
        return 0;
    }

    return 0;
}