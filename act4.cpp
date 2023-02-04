/*presentacion:
Nombre:Mateo Gonzalez Serna
fecha:02/02/23
centro universitario de los altos
ingenieria en computacion/segundo semestre
profesor: sergio franco casillas
*/
#include <iostream> //librerias que utilizare 
#include <limits>

using namespace std;

int main (){//programa principal
    int limite; //variable para el limite de 
    int sumaa=1,nose=0;//variables para la operacion de la seria figonassi
    char opcion;//variable para switch

        while ('4'=='4'){//while para repetir el programa
        cout<<"bienvenido a la serie figonassi\nla serie se hara en:\n[1] For\n[2] while\n[3] do while\n[4] salir del programa"<<endl;//menu
        cin>>opcion;    
            switch (opcion){//switch para la eleccion del bucle
                case '1'://caso 1 con for
                    cout<<"ingresa el limite de la serie:";
                    while (!(cin >> limite)) {//validacion de que e valor ingresado no es una letra
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "este valor no es valido, ingresa solo numeros" << endl;
                    }//fin de validacion
                    for (;nose <=limite;){//operacion figonassi
                        cout<<nose<<endl;
                        sumaa+=nose;
                        nose = sumaa - nose;
                        }
                    sumaa=1;//reinicio de valores
                    nose=0;
                    break;//fin de caso 1
                
                case '2'://caso 2 con while
                    cout<<"ingresa el limite de la serie:";
                    cin>>limite;
                    while (!(cin >> limite)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;
                    }//fin de validacion  
                    while (nose<=limite){//operacion figonassi
                        cout<<nose<<endl;
                        sumaa+=nose;
                        nose = sumaa - nose;
                    }
                    sumaa=1;//reinicio de valores
                    nose=0;
                    break;//fin de caso 2
        
                case '3'://caso 3 con do while
                    cout<<"ingresa el limite de la serie:";
                    cin>>limite;
                    while (!(cin >> limite)) {//validacion de que e valor ingresado no es una letra
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "este valor no es valido, ingresa solo numeros" << endl;
                    }//fin de validacion  
                    do{
                        cout<<nose<<endl;//operacion figonassi
                        sumaa+=nose;
                        nose = sumaa - nose;
                    } 
                    while (nose<=limite);
                    sumaa=1;//reinicio de valores
                    nose=0;
                    break;//fin de caso 3
            
                case '4':
                    exit(EXIT_SUCCESS); //opcion 4 para cerrar el programa
                    break;
        
                default:
                    cout<<"opcion invalida"<<endl;//opcion invalida de dato incorrecto ingresado
                    break;
        }//fin del switch
        }//fin del while principal
return 0;
}//fin del main