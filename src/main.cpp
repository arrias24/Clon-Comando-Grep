#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//FUNCION 

void transformarMinuscula(string &cadena){
    for(int i = 0; i < cadena.length(); i++){
        cadena[i] = tolower(cadena[i]);
    }
}


int main(int argc, char** args){

    //ABRIMOS EL ARCHIVO

    fstream archivo;
    archivo.open(args[1]);

    if (!archivo.is_open()) {
        cout << "El archivo no se pudo abrir" << endl; 
        return 0;
    }

    //GUARDAMOS PALABRA A BUSCAR Y LA TRANSFORMAMOS EN MINUSCULA
    
    string palabra_buscada = args[2];
    transformarMinuscula(palabra_buscada);

    //COLOR PARA RESALTAR TEXTOS

    string numero_color = args[3];
    int color_texto = std::stoi(numero_color);


    return 0;
}