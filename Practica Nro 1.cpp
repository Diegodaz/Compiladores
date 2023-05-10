/* 1. Leer toda una instrucción por consola (Ejemplo: “int temp;”) y mostrar en
pantalla letra por letra */

/*
#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    printf("Ingrese frase: ");
    fgets(frase, 100, stdin);
    for (int i = 0; i < strlen(frase); i++) {
        printf("%c\n", frase[i]);
    }
    return 0;
}
*/
/* 2. Leer un archivo de texto plano (archivo con un pseudocódigo) y muestre en
pantalla letra por letra*/


/*
#include <stdio.h>

int main() {
    FILE *archivo;
    char caracter;
    archivo = fopen("Practica Nro 1.txt", "r"); 
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    while ((caracter = fgetc(archivo)) != EOF) { 
        printf("%c\n", caracter);
    }
    fclose(archivo); 
    return 0;
}

*/

/* 3. Crear un programa que cifre un pseudocódigo y otro que lo descifre, según la técnica
del cifrado de César. El seudocódigo se encuentra en un archivo de texto plano. El
cifrado de César consiste en mover cada letra un determinado número de espacios en
el alfabeto (puede ser 3 espacios)*/

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cifrar(string mensaje, int clave) {
    string cifrado = "";
    int n = mensaje.length();
    for (int i = 0; i < n; i++) {
        if (isalpha(mensaje[i])) {
            char letra = (mensaje[i] + clave - 'A') % 26 + 'A';
            cifrado += letra;
        } else {
            cifrado += mensaje[i];
        }
    }
    return cifrado;
}

string descifrar(string mensaje, int clave) {
    string descifrado = "";
    int n = mensaje.length();
    for (int i = 0; i < n; i++) {
        if (isalpha(mensaje[i])) {
            char letra = (mensaje[i] - clave - 'A' + 26) % 26 + 'A';
            descifrado += letra;
        } else {
            descifrado += mensaje[i];
        }
    }
    return descifrado;
}

int main() {
    string nombre_archivo = "Practica Nro 1.txt";
    string linea, cifrado, descifrado;
    int clave = 3; 
    ifstream archivo_entrada(nombre_archivo.c_str());
    if (!archivo_entrada) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    while (getline(archivo_entrada, linea)) {
        cifrado = cifrar(linea, clave);
        descifrado = descifrar(cifrado, clave);
        cout << "Mensaje original: " << linea << endl;
        cout << "Mensaje cifrado: " << cifrado << endl;
        cout << "Mensaje descifrado: " << descifrado << endl;
    }
    archivo_entrada.close();
    return 0;
}

*/

/* 4. Leer un archivo de texto plano, letra por letra hasta encontrar un separador (espacio,
tabulador o salto de línea) y mostrar en pantalla si el vocablo se trata de un número
entero, una palabra o un caracter especial (“+”,”-“,”*”,”/”)*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string nombre_archivo = "Practica Nro 1.txt";
    ifstream archivo_entrada(nombre_archivo.c_str());
    if (!archivo_entrada) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    char caracter;
    while (archivo_entrada.get(caracter)) {
        if (isdigit(caracter)) {
            cout << caracter << " = es un número entero." << endl;
        } else if (isalpha(caracter)) {
            cout << caracter << " = es una palabra." << endl;
        } else if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') {
            cout << caracter << " = es un caracter especial." << endl;
        } 
        if (caracter == ' ' || caracter == '\t' || caracter == '\n') {
            cout << " = separador" << endl;
        }
    }
    archivo_entrada.close();
    return 0;
}





