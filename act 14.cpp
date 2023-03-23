/*
Nombre: Mateo Gonzalez Serna
Fecha: 21/03/2023
Programa: Ejercicio 14.
Centro universitario de los altos / Universidad de Guadalajara
Ingenieria en computacion / segundo semestre
Prof: Sergio.
programa para las operaciones de conjuntos
*/
#include <iostream>
#include <string> //libreria para string
#include <fstream>
#include <limits>

using namespace std;

struct datos
{
    string nombre;
    string apellido;
    string estado;
    string municipio;
    string calle;
    int edad;
    int estatura;
};

int n, opca, opcb;

int main(){
    do{
        fstream archivo("registros.txt");

        cout << "----------------bienvenido----------------" << endl;
        cout << "-[1] llenar nuevo registro\n-[2] salir del programa" << endl;
        while (!(cin >> opca)) {//validacion de que e valor ingresado no es una letra
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "este valor no es valido, ingresa solo numeros" << endl;
                }//fin de validacion

            if(opca==1){
                system("clear");
                cout << "cuantos registros deseas crear" << endl;
                while (!(cin >> n)) {//validacion de que e valor ingresado no es una letra
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "este valor no es valido, ingresa solo numeros" << endl;
                }//fin de validacion
                cin.ignore();
                datos array[n];

                if(!archivo.is_open()){
                    archivo.open("registro.txt", ios::out);
                }
                    for (int i = 0; i < n; i++){
                        system("clear");
                        cout << "ingresa solamente el nombre" << endl;
                        getline(cin, array[i].nombre);
                        archivo << array[i].nombre << endl;
                        cout << "ingresa los apellidos" << endl;
                        getline(cin, array[i].apellido);
                        archivo<<array[i].apellido<<endl;
                        cout << "ingresa el estado" << endl;
                        getline(cin, array[i].estado);
                        archivo<<array[i].estado<<endl;
                        cout << "ingresa el municipo" << endl;
                        getline(cin, array[i].municipio);
                        archivo<<array[i].municipio<<endl;
                        cout << "ingresa la calle" << endl;
                        getline(cin, array[i].calle);
                        archivo<<array[i].calle<<endl;
                        cout << "ingresa la edad" << endl;
                        cin >> array[i].edad;
                        archivo<< array[i].edad<<endl;
                        cout << "ingresa tu estatura" << endl;
                        cin >> array[i].estatura;
                        archivo<<array[i].estatura<<endl;
                        cin.ignore();
                    } // fin del for para campturar datos

                    cout<<"para guardar estos registros, presione 1\npara regresar presione 2"<<endl;
                        while (!(cin >> opcb)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;
                        }//fin de validacion
                        if(opcb==1){
                            cout<<"archivo guardado con exito"<<endl;
                            system("pause");
                            }//fin del if para guardar o hacer mas registros
                        archivo.close();

                }//fin del if para iniciar a guardar registros

                        else if(opca>1){
                            cout << "bye" << endl;
                        }

    } while (opca != 2);//fin del while del menu
    return 0;
} // fin del main