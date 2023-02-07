/*
Nombre: Mateo Gonzalez Serna
Fecha: 07/02/2023
Programa: Ejercicio 5.
Centro universitario de los altos / Universidad de Guadalajara
Ingenieria en computacion / segundo semestre
Prof: Sergio.
*/
#include <iostream>// librerias que voy a usar
#include <limits>

using namespace std;

int i, a, b=0, posicion, num;// variables que usare
int vector [10];
char opcion;

int main(){

    while ('true'){//while para todo el programa
        cout<<"Elija la opcion a realizar"<<endl;
        cout<<"1. Insertar valores\n2. Mostrar lista de valore\n3. Mostrar sumatoria de valores\n4. Borrar valores\n5. editar valores\n6. Vaciar valores\n7. Salir"<<endl;//menu
            cin>>opcion;
        
                switch(opcion){//switch para el menu
                    case '1'://opcion para decir cuantos valores se van a ingresar los valores
                        cout<<"¿Cuantos valores desea agregar?"<<endl;
                        while (!(cin >> a)) {//validacion de que e valor ingresado no es una letra
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "este valor no es valido, ingresa solo numeros" << endl;
                            }//fin de validacion
                        a=a-1;
                        while(b<=a){
                            cout<<"Ponga un valor:"<<endl;//opcion para ingresar valores al vector
                            while (!(cin >> vector[b])) {//validacion de que e valor ingresado no es una letra
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "este valor no es valido, ingresa solo numeros" << endl;
                            }//fin de validacion
                            b=b+1;
                            }//fin de while de valores
                    break;//fin del caso 1

                    case '2'://se muestra los valores en el vector
                        for(i=0;i<=9;i++){
                        cout<<vector[i]<<" ";
                        }
                    break;//fin del caso 2

                    case '3'://se suman los valores del vector
                        for(i=0;i<=9;i++){
                        num=num+vector[i];
                        }
                        cout<<num<<endl;
                        num=0;
                    break;//fin del caso 3

                    case '4'://opcion para borrar los valores del vector
                        cout<<"caso4"<<endl;
                        cout<<"¿Cual es la posicion que desea borrar?"<<endl;
                        while (!(cin >> posicion)) {//validacion de que e valor ingresado no es una letra
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "este valor no es valido, ingresa solo numeros" << endl;
                            }//fin de validacion
                        posicion=posicion-1;
                        vector[posicion]=0;
                            for(i=0;i<=9;i++){
                            cout<<vector[i]<<" ";
                            }
                    break;//fin del caso 4
        
                    case '5'://editar valores
                        cout<<"¿A cual posicion decide editar su valor?"<<endl;
                        while (!(cin >> posicion)) {//validacion de que e valor ingresado no es una letra
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "este valor no es valido, ingresa solo numeros" << endl;
                            }//fin de validacion
                        posicion=posicion-1;
                        cout<<"Ingrese el nuevo valor"<<endl;
                        cin>>num;
                        vector[posicion]=num;
                            for(i=0;i<=9;i++){
                            cout<<vector[i]<<" ";
                            }
                    break;//fin del caso 5
            
                    case '6'://opcion para vaciar el while
                        for(i=0;i<=9;i++){
                        vector[i]=0;
                        cout<<vector[i]<<" ";
                        }
                    break;//fin del caso 6

                    case '7'://opcion para cerrar el programa
                        exit(EXIT_SUCCESS); //opcion 7 para cerrar el programa
                    break;//fin caso 7

                    default://opcion para casos no validos
                        cout<<"opcion invalida"<<endl;
                    break;
            }//fin del switch    
    }//fin del while principal
    return 0;
}//fin del main