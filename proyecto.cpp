/*
Nombre: Mateo Gonzalez Serna, Luis Eduardo Maciel de la Mora
Fecha: 16/05/2023
Programa: proyecto final
Centro universitario de los altos / Universidad de Guadalajara
Ingenieria en computacion / segundo semestre
Prof: Sergio.
un mini siau y guardarlo en un archivo txt
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Materia {//estructura de las materias
    string nombre;
    double calificacion;
};

struct Alumno {//estructura del alumno
    string nombre;
    string carrera;
    vector<Materia> materias;
};

vector<Alumno> alumnos;




void agregarAlumno() {
    Alumno alumno;
    cout << "Nombre del alumno: ";
    cin >> alumno.nombre;
    cout << "Carrera del alumno: ";
    cin >> alumno.carrera;
    alumnos.push_back(alumno);
    cout << "Alumno agregado exitosamente." << endl;
}

void agregarMateria(int indice) {
    if (indice >= 0 && indice < alumnos.size()) {//verificacion de si exixte el alumno
        Materia materia;
        cout << "Nombre de la materia: ";
        cin >> materia.nombre;//agregar materia
        cout << "Calificacion de la materia: ";
        cin >> materia.calificacion;//agregar calificacion
        alumnos[indice].materias.push_back(materia);
        cout << "Materia agregada exitosamente." << endl;
    } else {
        cout << "Índice de alumno inválido." << endl;
    }
}

void mostrarPromedio(int indice) {
    if (indice >= 0 && indice < alumnos.size()) {//verificar que exista el alumno
        double sumaCalificaciones = 0.0;
        for (const auto& materia : alumnos[indice].materias) {
            sumaCalificaciones += materia.calificacion;
        }//funcion que promedia la calificacion
        double promedio = sumaCalificaciones / alumnos[indice].materias.size();
        cout << "El promedio del alumno " << alumnos[indice].nombre << " es: " << promedio << endl;
        if (promedio <= 59) {//mensajes de el estado de su calificacion
            cout << "Estado: Reprobado" << endl;
        } else if (promedio >= 60 && promedio <= 79) {
            cout << "Estado: Regular" << endl;
        } else if (promedio >= 80 && promedio <= 89) {
            cout << "Estado: Muy bien" << endl;
        } else {
            cout << "Estado: Excelente" << endl;
        }
    } else {
        cout << "Índice de alumno inválido." << endl;
    }
}

void borrarAlumno(int indice) {
    if (indice >= 0 && indice < alumnos.size()) {
        alumnos.erase(alumnos.begin() + indice);//borrado del alumno de la estructura
        cout << "Alumno eliminado exitosamente." << endl;
    } else {
        cout << "Índice de alumno inválido." << endl;
    }
}

void editarAlumno(int indice) {
    if (indice >= 0 && indice < alumnos.size()) {
        cout << "Nuevo nombre del alumno: ";
        cin >> alumnos[indice].nombre;//agregado del alumno a la estructura
        cout << "Nueva carrera del alumno: ";
        cin >> alumnos[indice].carrera;//agregado de la carrera a la estructura
        cout << "Alumno editado exitosamente." << endl;
    } else {
        cout << "Índice de alumno inválido." << endl;
    }
}

void mostrarMenu() {//menu principal
    cout << "========== Menú ==========" << endl;
    cout << "1. Agregar alumno" << endl;
    cout << "2. Agregar materia a un alumno" << endl;
    cout << "3. Mostrar promedio de un alumno" << endl;
    cout << "4. Borrar alumno" << endl;
   
cout << "5. Editar alumno" << endl;
cout << "6. Guardar" << endl;
cout << "7. Salir"<< endl;
cout << "Ingrese el número de la opción deseada: \n";
cout<<"nota: los indices de los alumnos son almacenados del 0 al n numero\n";
}

void guardarDatosEnArchivo() {//funcion para guardar el archivo
ofstream archivo("datos.txt");
if (archivo.is_open()) {
for (const auto& alumno : alumnos) {//funcion de guardar todos los alumnos
archivo << alumno.nombre << " " << alumno.carrera << endl;
for (const auto& materia : alumno.materias) {//funcion para guardar las materias
archivo << materia.nombre << " " << materia.calificacion << endl;
}
archivo << endl;
}
archivo.close();
cout << "Datos guardados exitosamente en el archivo 'datos.txt'." << endl;//mensaje de verificacion
} else {
cout << "Error al abrir el archivo." << endl;//mensaje de error
}
}

void leerDatosDelArchivo() {
ifstream archivo("datos.txt");//abrir el archivo
if (archivo.is_open()) {
alumnos.clear();
Alumno alumno;//tomar los archivos del documento
string linea;
while (getline(archivo, linea)) {
if (linea.empty()) {
alumnos.push_back(alumno);//guardado de el archivo
alumno.materias.clear();
} else if (alumno.nombre.empty()) {
alumno.nombre = linea;
} else if (alumno.carrera.empty()) {
alumno.carrera = linea;
} else {
Materia materia;//leer las matrias del archivo
size_t pos = linea.find(' ');
materia.nombre = linea.substr(0, pos);
materia.calificacion = stod(linea.substr(pos + 1));
alumno.materias.push_back(materia);
}
}
archivo.close();
cout << "Datos cargados exitosamente del archivo 'datos.txt'." << endl;//mensaje de confirmacion
} else {
cout << "El archivo 'datos.txt' no existe o no se pudo abrir." << endl;//mensaje de error
}
}

int main() {//inicio main
system("clear");
leerDatosDelArchivo();//cargar archivo

int opcion;
do {
    mostrarMenu();
    cin >> opcion;

    switch (opcion) {//switch del menu
        case 1://agregar alumno
        system("clear");
            agregarAlumno();
            break;
        case 2://agregar materia al alumno
         system("clear");
            int indice;
            cout << "Índice del alumno: ";
            cin >> indice;
            agregarMateria(indice);
            break;
        case 3://mostrar promedio
         system("clear");
            cout << "Índice del alumno: ";
            cin >> indice;
            mostrarPromedio(indice);
            break;
        case 4://borrar alumno
         system("clear");
            cout << "Índice del alumno: ";
            cin >> indice;
            borrarAlumno(indice);
            break;
        case 5://editar datos del alumno
         system("clear");
            cout << "Índice del alumno: ";
            cin >> indice;
            editarAlumno(indice);
            break;
        case 6://guardando archivo
         system("clear");
            guardarDatosEnArchivo();
            break;
        case 7://cerrar programa sin guardar
         system("clear");
            cout << "Saliendo del programa..." << endl;
            break;
        default://opcion equivocada
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
    }

    cout << endl;

} while (opcion != 7);//ciclo para repetir el programa

return 0;
}

