/*
 * EJERCICIO CLASE 1 - PUNTEROS Y STRUCTS
 * ======================================
 *
 * ENUNCIADO SIMPLIFICADO:
 * Implementar un programa que permita:
 * 1. Crear una escuela con arreglos dinamicos de estudiantes y materias
 * 2. Llenar estudiantes y materias con datos del usuario
 * 3. Mostrar la escuela en formato de tabla
 * 4. Encontrar el estudiante con mejor promedio
 * 5. Calcular el promedio general de la escuela
 * 6. Buscar un estudiante por su id
 * 7. Liberar la memoria correctamente
 *
 * REQUISITOS OBLIGATORIOS:
 * - Usar punteros y memoria dinamica (new/delete[])
 * - Usar structs para representar escuela, estudiantes y materias
 * - La escuela debe tener punteros a estudiantes y materias
 * - Validar entrada del usuario (cantidad > 0)
 * - Liberar toda la memoria asignada y asignar nullptr
 * - Usar paso por referencia cuando sea apropiado
 *
 * FUNCIONES QUE DEBE IMPLEMENTAR:
 * 1. void crearEscuela(Escuela& escuela, int cantEst, int cantMat)
 * 2. void llenarEstudiantes(Escuela& escuela)
 * 3. void llenarMaterias(Escuela& escuela)
 * 4. void mostrarEscuela(const Escuela& escuela)
 * 5. int buscarMejorPromedio(const Escuela& escuela)
 * 6. float calcularPromedioGeneral(const Escuela& escuela)
 * 7. int buscarEstudiantePorId(const Escuela& escuela, int id)
 * 8. void liberarEscuela(Escuela& escuela)
 *
 * MENU SIMPLE:
 * 1. Crear y llenar escuela
 * 2. Mostrar escuela
 * 3. Estudiante con mejor promedio
 * 4. Promedio general
 * 5. Buscar por id
 * 6. Salir
 *
 * NOTAS IMPORTANTES:
 * - Validar que la cantidad sea positiva
 * - Verificar punteros antes de usar
 * - Manejar el caso de lista vacia
 * - Usar buenas practicas de programacion
 *
 * CRITERIOS DE EVALUACION:
 * - Correcta implementacion de punteros (40%)
 * - Uso de structs y manejo de memoria (40%)
 * - Funcionalidad y validaciones (20%)
 *
 * TIEMPO ESTIMADO: 1-2 horas
 * DIFICULTAD: Media
 */

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct Materia {
    int codigo;
    char nombre[40];
    int creditos;
};

struct Estudiante {
    int id;
    char nombre[40];
    float promedio;
    int codigoMateriaPrincipal;
};

struct Escuela {
    Estudiante* estudiantes;
    int cantidadEstudiantes;
    Materia* materias;
    int cantidadMaterias;
};

// Crea la escuela con arreglos dinamicos
void crearEscuela(Escuela& escuela, int cantEst, int cantMat) {
    if (cantEst <= 0 || cantMat <= 0){
        cout<<"Las cantidades deben ser positivas."<<endl;
        return;
    }
    escuela.estudiantes = new Estudiante[cantEst];
    escuela.materias = new Materia[cantMat];
    escuela.cantidadEstudiantes = cantEst;
    escuela.cantidadMaterias = cantMat;
    cout<<"Escuela: "<<cantEst<<" estudiantes, "<<cantMat<<" materias."<<endl;
    // TODO: Implementar esta funcion
    // - Validar que cantEst y cantMat sean positivos
    // - Crear arreglos dinamicos con new
    // - Asignar punteros y cantidades en la escuela
}

// Llena la lista de estudiantes
void llenarEstudiantes(Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.materias == nullptr){
        cout <<"No hay estudiantes o materias creadas."<<endl;
        return;
    }
    cout<<"\n== Llenando de estudiantes =="<<endl;
    for (int i = 0; i < escuela.cantidadEstudiantes; i++){
        cout<<"\nEstudiante #"<<i+1<<":"<<endl;
        cout<<"ID: ";
        cin>>escuela.estudiantes[i].id; //se llama asi pq dentro de la escuela accede al miembro estudiantes, y dentro del estudiante en la posicion i, accede al miembro id.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //se utiliza esta linea para borrar todo, mientras que el cin.ignore solo borra un caracter
        cout<<"Nombre: ";
        cin.getline(escuela.estudiantes[i].nombre, 40);
        cout<<"Promedio: ";
        cin>>escuela.estudiantes[i].promedio;
    
    while (escuela.estudiantes[i].promedio < 0.0 || escuela.estudiantes[i].promedio > 20.0) {
        cout << "Promedio invalido. Ingrese un valor entre 0.0 y 20.0: ";
        cin >> escuela.estudiantes[i].promedio;
    }
        bool materiaValida = false;
        do {
            cout << "Codigo de materia principal: ";
            cin >> escuela.estudiantes[i].codigoMateriaPrincipal;
            
            // Validar que el código exista en las materias
            for (int j = 0; j < escuela.cantidadMaterias; j++) {
                if (escuela.materias[j].codigo == escuela.estudiantes[i].codigoMateriaPrincipal) {
                    materiaValida = true;
                    break;
                }
            }
            
            if (!materiaValida) {
                cout << "Codigo de materia no existe." << endl;
            }
        } while (!materiaValida);  
    }  //ESTA LLAVE CIERRA EL for
    
    cout << "\nEstudiantes llenados correctamente." << endl;
}
    // TODO: Implementar esta funcion
    // - Verificar que escuela.estudiantes no sea nullptr
    // - Pedir id, nombre y promedio
    // - Pedir codigoMateriaPrincipal (debe existir en materias)
    // - Usar cin.getline para el nombre


// Llena la lista de materias
void llenarMaterias(Escuela& escuela) {
     if (escuela.materias == nullptr){
        cout<<"No hay materias creadas."<<endl;
        return;
    }

    cout<<"\n== Llenando de materias =="<<endl;
    for (int i = 0; i < escuela.cantidadMaterias; i++){
        cout<<"\nMateria #"<<i+1<<":"<<endl;
        cout<<"Codigo: ";
        cin>>escuela.materias[i].codigo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Nombre: ";
        cin.getline(escuela.materias[i].nombre, 40);
        cout<<"Creditos: ";
        cin>>escuela.materias[i].creditos;
    }
    cout << "\nMaterias llenadas correctamente." << endl;
    // TODO: Implementar esta funcion
    // - Verificar que escuela.materias no sea nullptr
    // - Pedir codigo, nombre y creditos
}

// Muestra la escuela completa
void mostrarEscuela(const Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.materias == nullptr){
        cout<<"No hay escuela creada."<<endl;
        return;
        }
    cout<<"\n== Mostrando Escuela =="<<endl;
    for (int i = 0; i < escuela.cantidadMaterias; i++){
        cout << left << setw(10) << "Codigo" << setw(10) << "Materia" << setw(10) << "Creditos" << endl;
        cout << left << setw(10) << escuela.materias[i].codigo 
             << setw(10) << escuela.materias[i].nombre 
             << setw(10) << escuela.materias[i].creditos << endl;
    }
    cout << "\n== Estudiantes ==" << endl;
    for (int i = 0; i < escuela.cantidadEstudiantes; i++){
        cout << left << setw(10) << "ID" << setw(10) << "Nombre" << setw(10) << "Promedio" << setw(20) << "Materia Principal" << endl;
        cout << left << setw(10) << escuela.estudiantes[i].id 
             << setw(10) << escuela.estudiantes[i].nombre 
             << setw(10) << fixed << setprecision(2) << escuela.estudiantes[i].promedio //dos decimales para el promedio
             << setw(20);
        
        // Buscar el nombre de la materia principal
        const char* nombreMateria = "Desconocida";
        for (int j = 0; j < escuela.cantidadMaterias; j++) {
            if (escuela.materias[j].codigo == escuela.estudiantes[i].codigoMateriaPrincipal) {
                nombreMateria = escuela.materias[j].nombre;
                break;
            }
        }
        cout << nombreMateria << endl;
    }

    // TODO: Implementar esta funcion
    // - Verificar que los punteros no sean nullptr
    // - Mostrar materias primero y luego estudiantes
    // - Usar tabla simple con setw
}

// Retorna el indice del estudiante con mejor promedio
int buscarMejorPromedio(const Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0){
        cout<<"No hay estudiantes en la escuela."<<endl;
        return -1;
    }
     int indiceMejor = 0;
    float mejorPromedio = escuela.estudiantes[0].promedio;
    
    for (int i = 1; i < escuela.cantidadEstudiantes; i++) {
        if (escuela.estudiantes[i].promedio > mejorPromedio) {
            mejorPromedio = escuela.estudiantes[i].promedio;
            indiceMejor = i;
        }
    }
    
    return indiceMejor;
}
// Calcula el promedio general de la escuela
float calcularPromedioGeneral(const Escuela& escuela) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0) {
        cout << "No hay estudiantes para calcular promedio." << endl;
        return 0.0;  // ← f indica float
    }
    float suma = 0.0;
    for (int i = 0; i < escuela.cantidadEstudiantes; i++) {
        suma += escuela.estudiantes[i].promedio;
    }
    
    return suma / escuela.cantidadEstudiantes;
}

// Busca un estudiante por id y retorna su indice
int buscarEstudiantePorId(const Escuela& escuela, int id) {
    if (escuela.estudiantes == nullptr || escuela.cantidadEstudiantes <= 0){
        cout<<"No hay estudiantes en la escuela."<<endl;
        return -1;
    }
     for (int i = 0; i < escuela.cantidadEstudiantes; i++) {
        if (escuela.estudiantes[i].id == id) {
            return i; // Retorna el id del estudiante encontrado
        }
    }
     return -1; // No se encontró un estudiante con ese id
    // TODO: Implementar esta funcion
    // - Verificar que escuela.estudiantes no sea nullptr
    // - Recorrer estudiantes y comparar id
    // - Retornar indice o -1 si no existe
}

// Libera la memoria de la escuela
void liberarEscuela(Escuela& escuela) {
    cout << "Liberando memoria de la escuela..." << endl;
    if (escuela.estudiantes != nullptr) {
        delete[] escuela.estudiantes;
        escuela.estudiantes = nullptr;
        cout << "Memoria de estudiantes liberada." << endl;
    }
    if (escuela.materias != nullptr) {
        delete[] escuela.materias;
        escuela.materias = nullptr;
        cout << "Memoria de materias liberada." << endl;
    }
    escuela.cantidadEstudiantes = 0;
    escuela.cantidadMaterias = 0;

    cout << "Memoria de escuela liberada." << endl;
    // TODO: Implementar esta funcion
    // - Liberar estudiantes y materias con delete[]
    // - Asignar nullptr a ambos punteros
    // - Poner cantidades en 0
}

// Muestra el menu principal
void mostrarMenu() {
    cout << "\n=== GESTION DE ESTUDIANTES ===" << endl;
    cout << "1. Crear y llenar escuela" << endl;
    cout << "2. Mostrar escuela" << endl;
    cout << "3. Estudiante con mejor promedio" << endl;
    cout << "4. Promedio general" << endl;
    cout << "5. Buscar por id" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Escuela escuela;
    escuela.estudiantes = nullptr;
    escuela.materias = nullptr;
    escuela.cantidadEstudiantes = 0;
    escuela.cantidadMaterias = 0;

    cout << "=== GESTION DE ESTUDIANTES ===" << endl;
    cout << "Implemente las funciones marcadas con TODO para completar el ejercicio." << endl;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int cantEst = 0;
                int cantMat = 0;
                cout << "Ingrese la cantidad de estudiantes: ";
                cin >> cantEst;
                cout << "Ingrese la cantidad de materias: ";
                cin >> cantMat;

                liberarEscuela(escuela);
                crearEscuela(escuela, cantEst, cantMat);

                if (escuela.estudiantes != nullptr && escuela.materias != nullptr) {
                    llenarMaterias(escuela);
                    llenarEstudiantes(escuela);
                    cout << "Escuela creada y llenada correctamente." << endl;
                } else {
                    cout << "Error al crear la escuela." << endl;
                }
                break;
            }

            case 2: {
                if (escuela.estudiantes != nullptr && escuela.materias != nullptr) {
                    mostrarEscuela(escuela);
                } else {
                    cout << "No hay escuela creada. Use la opcion 1 primero." << endl;
                }
                break;
            }

            case 3: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    int indice = buscarMejorPromedio(escuela);
                    if (indice >= 0) {
                        cout << "Mejor promedio: " << escuela.estudiantes[indice].nombre
                             << " (" << fixed << setprecision(2)
                             << escuela.estudiantes[indice].promedio << ")" << endl;
                    } else {
                        cout << "No hay estudiantes en la lista." << endl;
                    }
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 4: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    float promedio = calcularPromedioGeneral(escuela);
                    cout << "Promedio general: " << fixed << setprecision(2)
                         << promedio << endl;
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 5: {
                if (escuela.estudiantes != nullptr && escuela.cantidadEstudiantes > 0) {
                    int idBuscado;
                    cout << "Ingrese el id a buscar: ";
                    cin >> idBuscado;
                    int indice = buscarEstudiantePorId(escuela, idBuscado);
                    if (indice >= 0) {
                        cout << "Encontrado: " << escuela.estudiantes[indice].nombre
                             << " (" << fixed << setprecision(2)
                             << escuela.estudiantes[indice].promedio << ")" << endl;
                    } else {
                        cout << "No se encontro un estudiante con ese id." << endl;
                    }
                } else {
                    cout << "No hay escuela creada o esta vacia." << endl;
                }
                break;
            }

            case 6: {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            default: {
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 6);

    liberarEscuela(escuela);
    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}

/*
 * PISTAS PARA LA IMPLEMENTACION:
 *
 * 1. crearEscuela(Escuela& escuela, int cantEst, int cantMat):
 *    - Verificar que cantEst y cantMat > 0
 *    - Crear arreglos con new
 *    - Asignar punteros y cantidades
 *
 * 2. llenarMaterias(Escuela& escuela):
 *    - Usar cin.ignore(numeric_limits<streamsize>::max(), '\n');
 *    - Leer nombre con cin.getline(escuela.materias[i].nombre, 40)
 *
 * 3. llenarEstudiantes(Escuela& escuela):
 *    - Pedir id, nombre, promedio y codigoMateriaPrincipal
 *
 * 4. mostrarEscuela(const Escuela& escuela):
 *    - Mostrar materias primero y luego estudiantes
 *
 * 5. buscarMejorPromedio(const Escuela& escuela):
 *    - Inicializar indiceMax = 0
 *    - Comparar estudiantes[i].promedio
 *
 * 6. calcularPromedioGeneral(const Escuela& escuela):
 *    - Acumular suma y dividir por cantidadEstudiantes
 *
 * 7. buscarEstudiantePorId(const Escuela& escuela, int id):
 *    - Recorrer estudiantes y comparar id
 *
 * 8. liberarEscuela(Escuela& escuela):
 *    - delete[] estudiantes; delete[] materias
 *    - Asignar nullptr a ambos y poner cantidades en 0
 */
