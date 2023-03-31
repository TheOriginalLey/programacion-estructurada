#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main() {
    string palabras[] = {"escuela", "mateo", "edy", "rebeca", "parangaricutirimicauaro", "patrañas", "veracruz", "jalostotitlan", "jalisco", "guadalajara", "vaina", "albertano", "mandarina", "invunerables", "teresa", "zapatillas", "enrique", "bunbury", "motocicleta", "amayrany"}; 
    
        srand(time(0));// Semilla para generar números aleatorios

            int indice_palabra = rand() % 20;// Seleccionar una palabra al azar del banco
            string palabra_secreta = palabras[indice_palabra];

            int longitud = palabra_secreta.length(); // Crear una cadena con guiones para representar la palabra secreta
            string cadena_espacios(longitud, '_');
   
            int intentos = 0; // Variables para contar intentos y penalizaciones
            int penalizacion = 0;
 
                while (cadena_espacios != palabra_secreta) {  // Ciclo principal del juego        
                    cout << "Palabra a adivinar: " << cadena_espacios << endl; // Mostrar la cadena de espacios y pedir una letra al usuario
                    cout << "Intentos: " << intentos << endl;
                    cout << "Penalizaciones: " << penalizacion << endl;
                    cout << "Ingrese una letra: ";
                    char letra;
                    cin >> letra;
                    system("clear");
        
                        bool letra_encontrada = false; // Verificar si la letra ingresada está en la palabra secreta
                        for (int i = 0; i < longitud; i++) {
                            if (palabra_secreta[i] == letra) {
                                cadena_espacios[i] = letra;
                                letra_encontrada = true;
                            }
                        }

                    if (!letra_encontrada) { // Aumentar el contador de intentos si la letra no está en la palabra secreta
                    intentos++;
            
                        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                            penalizacion++;// Penalizar si la letra es una vocal
                        }
                    }
        
                    if (intentos - penalizacion >= 6) { // Si el jugador ha agotado sus intentos, mostrar mensaje de derrota y salir del juego
                        cout << "¡Lo siento! Has perdido. La palabra era " << palabra_secreta << endl;
                        break;
                    }
                }//fin del while
   
            if (cadena_espacios == palabra_secreta) {  // Si el jugador ha adivinado la palabra, mostrar mensaje de victoria
                cout << "¡Felicidades! Has adivinado la palabra " << palabra_secreta << " en " << intentos << " intentos." << endl;
            }
    return 0;
}//fin del main