#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char** args){

    //ABRIMOS EL ARCHIVO

    fstream archivo;
    archivo.open(args[1]);

    if (!archivo.is_open()) {
        cout << "El archivo no se pudo abrir" << endl; 
        return 0;
    }

    //CREAMOS BUCLE PARA GUARDAR EL TEXTO Y CONTAMOS LAS PALABRAS  

    string texto_completo[1000] = {};
    int numero_palabras = 0;

    while (archivo.good())
    {
        archivo>>texto_completo[numero_palabras];
        numero_palabras++;
    }

    return 0;
}