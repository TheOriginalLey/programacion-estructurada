/*
Nombre: Mateo Gonzalez Serna
Fecha: 18/03/2023
Programa: Ejercicio 7.
Centro universitario de los altos / Universidad de Guadalajara
Ingenieria en computacion / segundo semestre
Prof: Sergio.
programa para las operaciones de conjuntos
*/
#include <iostream>
#include <limits>
#include <vector>
#include <set>
#include <string>
#include <array>
#include <iterator>
#include <algorithm>
#include <cstring>

using namespace std;

char opca, opcb, i, tam;
char conjuntoa [10], conjuntob [10], conjuntofinal [40];
int seleccion, seleccionb, b=0, n=4;

int main(){
    do{
        cout<<"bienvenido a las operaciones de conjuntos"<<endl;
        cout<<"-[1] insertar valores a los conjuntos\n-[2] borrar o editar elementos\n-[3] ver conjuntos\n-[4] operaciones de conjuntos\n-[5] vaciar conjuntos\n-[6] salir del programa"<<endl;
            while (!(cin >> opca)) {//validacion de que e valor ingresado no es una letra
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "este valor no es valido, ingresa solo numeros" << endl;
                }//fin de validacion
        switch (opca){
            case '1':
                cout<<"a que conjunto deseas ingrasar datos\n-[1] conjunto 1\n-[2] conjunto 2"<<endl;
                while (!(cin >> seleccion)) {//validacion de que e valor ingresado no es una letra
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "este valor no es valido, ingresa solo numeros" << endl;}//fin de validacion
                cin.ignore();

                    if (seleccion==1){
                        cout<<"ingresaras valores al conjunto 1"<<endl;
                         for (int i=0; i <= 10; i++){
                            cout<<i<<" ingresa los valores"<<endl;
                            cin>>conjuntoa [i];
                         }
                    system("clear");
                        
                    }//if para seleccionar el conjunto 1
                    else if(seleccion>1){
                            cout<<"ingresaras valores al conjunto 2"<<endl;
                            for (int i=0; i <= 10; i++){
                            cout<<i<<" ingresa los valores"<<endl;
                            cin>>conjuntob [i];
                            }
                    system("clear");
                    }//else para seleccionar el conjunto 2
                seleccion=0;
                break;

            case '2':
                cout<<"deseas borrar [1] o editar los elementos [2]"<<endl;
                    while (!(cin >> seleccion)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;}

                    if(seleccion==1){
                        cout<<"de que conjunto deseas eliminar los elementos\n-[1] conjunto 1\n-[2] conjunto2"<<endl;

                            while (!(cin >> seleccionb)) {//validacion de que e valor ingresado no es una letra
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "este valor no es valido, ingresa solo numeros" << endl;}
                            system("clear");
                        
                        if(seleccionb==1){
                            cout<<"eliminando valores al conjunto a"<<endl;
                             
                        }

                        else if(seleccionb>1){
                            cout<<"eliminando valores al conjunto b"<<endl;
                            
                        }
                    seleccionb=0;
                    }

                    else if (seleccion>1){
                        cout<<"de que conjunto deseas editar los elementos\n-[1] conjunto 1\n-[2] conjunto2"<<endl;
                        while (!(cin >> seleccionb)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;}
                            if(seleccionb==1){

                        }
                        else if(seleccionb>1){

                        }
                    }
                seleccion=0;
                seleccionb=0;
                break;

            case '3':
                cout<<"de que conjunto deseas ver los elementos\n-[1] conjunto 1\n-[2] conjunto 2"<<endl;
                cin>>seleccion;
                if (seleccion==1){
                    for(i=0;i<=9;i++){
                    cout<<"["<<conjuntoa[i]<<"]";
                    }//for para mostrar los elementos del conjuntos
                    cout<<endl;
                }//fin del if de vista de elementos del conjunto 1
                else if (seleccion==2){
                    for(i=0;i<=9;i++){
                    cout<<"["<<conjuntob[i]<<"]";
                    }//for para mostrar los elementos del conjuntos
                    cout<<endl;
                }
                else if (seleccion==3){
                    for ( i = 0; i < 20; i++)   {
                        cout<<"["<<conjuntofinal<<"]"<<endl;
                    }
                    
                }
                seleccion=0;
                break;
            
            case '4':
            system("clear");
                do {
                    cout << "Menu de operaciones" << endl;
                    cout << "-[1] union\n-[2] diferencia\n-[3] interseccion\n-[4] regresar al menu principal" << endl;
                    cin >> opcb;

                    switch(opcb) {
                        case '1':
                                for (int i = 0; i < 10; i++) {
                                    if (i < n) {
                                        // Agregar elementos del conjuntoa
                                        for (int j = 0; j < n; j++) {
                                            if (conjuntoa[j] == conjuntoa[i]) {
                                                break;
                                            }
                                            if (j == n - 1) {
                                                conjuntoa[n] = conjuntofinal[i];
                                                n++;
                                            }
                                        }
                                    } 
                                    else {
                                        // Agregar elementos del conjunto2
                                        for (int j = 0; j < n; j++) {
                                            if (conjuntob[i-n] == conjuntoa[j]) {
                                                break;
                                            }
                                            if (j == n - 1) {
                                                conjuntofinal[n] = conjuntob[i-n];
                                                n++;
                                            }
                                        }
                                    }
                                }

                                // Imprimiendo la unión
                                for (int i = 0; i < n; i++) {
                                    cout << conjuntoa[i] << " ";
                                }
                            break;
                        case '2':
                                cout << "deseas hacer la diferencia de -[1] el conjunto A a B-[2] el conjunto B a A" << endl;
                                cin>>seleccion;
                                if(seleccion==1){
                                    cout << "la diferencia de A a B es:" << endl;
                                }
                                else if(seleccion>1){
                                    cout << "la diferencia de B a A es:" << endl;
                                }
                            seleccion=0;
                            break;
                        case '3':
                            cout << "la interseccion de los conjuntos es:" << endl;
                            break;
                        case '4':
                        cout << "Volviendo al menu principal..." << endl;
                        system("clear");
                            break;
                        default:
                            cout << "Opcion invalida. Intentalo de nuevo." << endl;
                    }
                } while(opcb !='4');
                break;
            
            case '5':
                        cout<<"de que conjunto deseas eliminar los elementos\n-[1] conjunto 1\n-[2] conjunto 2"<<endl;
                        while (!(cin >> seleccionb)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;}
                        system("clear");
                        
                        if(seleccionb==1){
                            cout<<"eliminando valores al conjunto 1"<<endl;
                          
                            }

                        else if(seleccionb>1){
                            cout<<"eliminando valores al conjunto 2"<<endl;
                        }
                    seleccionb=0;
                
                break;
            
            case '6':
                exit(EXIT_SUCCESS);
                break;     
            default:
                cout<<"opcion invalida, intentalo de nuevo"<<endl;
                break;
                
        
        }   //fin del swicht del primer menu
    }  while (true);//fin del while
    return 0;
}//fin del main