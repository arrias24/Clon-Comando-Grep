#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//FUNCIONES 

void transformarMinuscula(string &cadena){
    for(int i = 0; i < cadena.length(); i++){
        cadena[i] = tolower(cadena[i]);
    }
}

void resaltarPalabra(const string& palabra, const string& palabra_buscada, int color_texto, int& coincidencias) {
    size_t posicion = palabra.find(palabra_buscada);
    size_t inicio = 0;

    while (posicion != string::npos) {
        cout << palabra.substr(inicio, posicion - inicio);
        SetConsoleTextAttribute(hConsole, color_texto);
        cout << palabra.substr(posicion, palabra_buscada.length());
        SetConsoleTextAttribute(hConsole, 7);
        inicio = posicion + palabra_buscada.length();
        posicion = palabra.find(palabra_buscada, inicio);
        coincidencias++;
    }
    cout << palabra.substr(inicio) << " ";
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
    int coincidencias = 0;
    int numero_lineas = 0;

    //COLOR PARA RESALTAR TEXTOS

    string numero_color = args[3];
    int color_texto = std::stoi(numero_color);

    //MOSTRAMOS LINEA DE COINCIDENCIA Y RESALTAMOS PALABRA BUSCADA

    string linea;
    while (getline(archivo, linea)) {
        transformarMinuscula(linea);
        if (linea.find(palabra_buscada) != string::npos) {
            resaltarPalabra(linea, palabra_buscada, color_texto, coincidencias);
            cout << endl;
            numero_lineas++;
        }
    }
    cout << coincidencias << " coincidencias en " << numero_lineas << " lineas.";

    return 0;
}