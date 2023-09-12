#include <iostream>
#include <string>

// NOMBRE DE LA EMPRESA: LuxeHeJos SA

class Empleado {
public:
    // ATRIBUTOS BASICOS DEL EMPLEADO
    std::string nombre, apellido, tipoContrato; // TIPO DE CONTRATO PUEDE SER HORA O JORNADA COMPLETA
    int edad;

    // ATRIBUTOS PARA EL CALCULO DEL SALARIO
    float salarioBase, complementosSalariales;

    // ATRIBUTOS RELACIONADOS CON EL TRABAJO
    std::string categoria, sector;

    // PUNTERO JEFE
    Empleado *jefe;
    Empleado *inicio;

public:
    // Constructor
    Empleado(std::string _nombre, std::string _apellido, int _edad, std::string _tipoContrato, float _salarioBase,
            float _complementosSalariales, std::string _categoria, std::string _sector, Empleado* _jefe){

                nombre = _nombre;
                apellido = _apellido;
                edad = _edad;
                tipoContrato = _tipoContrato;
                salarioBase = _salarioBase;
                complementosSalariales = _complementosSalariales;
                categoria = _categoria;
                sector = _sector;
                jefe = _jefe;
            }

    // METODO IMPRIMIR INFORMACION DEL EMPLEADO
    void imprimirInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Apellido: " << apellido << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Tipo de Contrato: " << tipoContrato << std::endl;
        std::cout << "Salario Base: $" << salarioBase << std::endl;
        std::cout << "Complementos Salariales: $" << complementosSalariales << std::endl;
        std::cout << "Categoria: " << categoria << std::endl;
        std::cout << "Sector: " << sector << std::endl;
        if (jefe != nullptr) {
            std::cout << "Jefe: " << jefe->nombre << std::endl;
        } else {
            std::cout << "No tiene jefe." << std::endl;
        }
    }

    // METODO PARA ACTUALIZAR LOS DATOS DEL EMPLEADO;
    void actualizarEmpleado(const Empleado& nuevoEmpleado) {
        nombre = nuevoEmpleado.nombre;
        apellido = nuevoEmpleado.apellido;
        edad = nuevoEmpleado.edad;
        tipoContrato = nuevoEmpleado.tipoContrato;
        salarioBase = nuevoEmpleado.salarioBase;
        complementosSalariales = nuevoEmpleado.complementosSalariales;
        categoria = nuevoEmpleado.categoria;
        sector = nuevoEmpleado.sector;
        jefe = nuevoEmpleado.jefe;
    }

    // PUNTERO SIGUIENTE
    Empleado *sig = nullptr;
};

class ListEmpleados {
private:
    Empleado* inicio;

public:
    ListEmpleados() : inicio(nullptr) {}

    // METODO PARA INSERTAR EMPLEADOS
    void agregarEmpleados(std::string nombre, std::string apellido, int _edad, std::string _tipoContrato, float _salarioBase,
        float _complementosSalariales, std::string _categoria, std::string _sector, Empleado* _jefe) {

            Empleado* nuevo = new Empleado(nombre, apellido, _edad, _tipoContrato, _salarioBase, _complementosSalariales, _categoria, _sector, _jefe);
                if (inicio == nullptr) {
                    inicio = nuevo;
                } else {
                    Empleado* aux = inicio;
                    while (aux->sig != nullptr) {
                        aux = aux->sig;
                    }
                    aux->sig = nuevo;
                }
    }

    // IMPRIMIR INFORMACION DE LA LISTA DE EMPLEADOS;
    void imprimirInformacion() {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            aux->imprimirInformacion();
            aux = aux->sig;
            std::cout << "\n";
        }
    }

    // METODO PARA MODIFICAR EMPLEADOS;
    void modificarEmpleado(std::string nombre, std::string apellido, const Empleado& nuevoEmpleado) {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            if (aux->nombre == nombre && aux->apellido == apellido) {
                aux->actualizarEmpleado(nuevoEmpleado); // SE LLAMA AL METODO PARA CAMBIAR LA INFORMACION DEL EMPLEADO;
                std::cout << "Empleado " << nombre << " " << apellido << " modificado exitosamente." << std::endl;
                return;
            }
            aux = aux->sig;
        }
        std::cout << "Empleado con nombre " << nombre << " y apellido: " << apellido << " no encontrado." << std::endl;
    }

    // METODO PARA ELIMINAR EMPLEADOS;
    void eliminarEmpleado(std::string nombre, std::string apellido) {
        Empleado* aux = inicio;
        Empleado* anterior = nullptr;

        while (aux != nullptr) {
            if (aux->nombre == nombre && aux->apellido == apellido) {
                if (anterior == nullptr) {
                    inicio = aux->sig;
                } else {
                    anterior->sig = aux->sig;
                }

                std::cout << "Empleado " << nombre << " " << apellido << " eliminado exitosamente." << std::endl;
                return;
            }

            anterior = aux;
            aux = aux->sig;
        }
    }

    // METODO ORDENAR POR EDAD;
    void ordenarPorEdad() {
        Empleado* actual = inicio;
        Empleado* siguiente = nullptr;

        if (inicio == nullptr) {
            return;
        }

        bool intercambio = true;

        while (intercambio) {
            intercambio = false;
            actual = inicio;

            while (actual->sig != nullptr) {
                siguiente = actual->sig;

                if (actual->edad > siguiente->edad) {
                    // Intercambiar los valores de los nodos
                    std::string temp_nombre = actual->nombre;
                    std::string temp_apellido = actual->apellido;
                    int temp_edad = actual->edad;
                    std::string temp_tipoContrato = actual->tipoContrato;
                    float temp_salarioBase = actual->salarioBase;
                    float temp_complementosSalariales = actual->complementosSalariales;
                    std::string temp_categoria = actual->categoria;
                    std::string temp_sector = actual->sector;
                    Empleado* temp_jefe = actual->jefe;

                    actual->nombre = siguiente->nombre;
                    actual->apellido = siguiente->apellido;
                    actual->edad = siguiente->edad;
                    actual->tipoContrato = siguiente->tipoContrato;
                    actual->salarioBase = siguiente->salarioBase;
                    actual->complementosSalariales = siguiente->complementosSalariales;
                    actual->categoria = siguiente->categoria;
                    actual->sector = siguiente->sector;
                    actual->jefe = siguiente->jefe;

                    siguiente->nombre = temp_nombre;
                    siguiente->apellido = temp_apellido;
                    siguiente->edad = temp_edad;
                    siguiente->tipoContrato = temp_tipoContrato;
                    siguiente->salarioBase = temp_salarioBase;
                    siguiente->complementosSalariales = temp_complementosSalariales;
                    siguiente->categoria = temp_categoria;
                    siguiente->sector = temp_sector;
                    siguiente->jefe = temp_jefe;

                    intercambio = true;
                }

                actual = siguiente;
            }
        }
    }

    // METODO PARA ORDENRA POR APELLIDOS;
    void ordenarPorApellidos() {
        Empleado* actual = inicio;
        Empleado* siguiente = nullptr;

        while (actual != nullptr) {
            siguiente = actual->sig;

            while (siguiente != nullptr) {
                if (actual->apellido[0] > siguiente->apellido[0]) {
                    // INTERCAMBIA LOS EMPLEADOS
                    std::swap(actual->nombre, siguiente->nombre);
                    std::swap(actual->apellido, siguiente->apellido);
                    std::swap(actual->edad, siguiente->edad);
                    std::swap(actual->tipoContrato, siguiente->tipoContrato);
                    std::swap(actual->salarioBase, siguiente->salarioBase);
                    std::swap(actual->complementosSalariales, siguiente->complementosSalariales);
                    std::swap(actual->categoria, siguiente->categoria);
                    std::swap(actual->sector, siguiente->sector);
                    std::swap(actual->jefe, siguiente->jefe);
                }
                siguiente = siguiente->sig;
            }
            actual = actual->sig;
        }
    }

};

int main() {
    // EMPLEADOS METIDOS POR MEDIO DE LA CLASE;
    Empleado empleado1("Juan", "Perez", 30, "Jornada Completa", 3000.0, 500.0, "Supervisor", "Produccion", nullptr);

    // FUNCION AGREGAR EMPLEADOS;
    ListEmpleados empleados;

    empleados.agregarEmpleados("Juan", "Perez", 30, "Jornada Completa", 3000.0, 500.0, "Supervisor", "Produccion", nullptr);
    empleados.agregarEmpleados("Ana", "Gomez", 47, "Hora", 15.0, 100.0, "Operario", "Produccion", &empleado1);
    empleados.agregarEmpleados("Pedro", "Gonzalez", 35, "Hora", 15.0, 100.0, "Operario", "Produccion", nullptr);
    empleados.agregarEmpleados("Maria", "Rodriguez", 12, "Jornada Completa", 3000.0, 500.0, "Supervisor", "Produccion", nullptr);

    // FUNCION IMPRIMIR INFORMACION DE LOS EMPLEADOS
    std::cout << "LISTA NORMAL CON TODO INSERTADO: \n";
    empleados.imprimirInformacion();
    std::cout << "\n";

    // BUSCANDO MODIFICAR UN EMPLEADO;
    std::cout << "LISTA CON UN EMPLEADO MODIFICADO: \n";
    Empleado nuevoEmpleado("Hector", "Caravaca", 70, "Jornada Completa", 3000.0, 500.0, "Supervisor", "Produccion", nullptr);
    empleados.modificarEmpleado("Juan", "Perez", nuevoEmpleado);

    // MOSTRAR LOS NUEVOS RESULTADOS
    empleados.imprimirInformacion();

    // ELIMINAR UN EMPLEADO
    std::cout << "LISTA CON UN EMPLEADO ELIMINADO: \n";
    empleados.eliminarEmpleado("Pedro", "Gonzalez");

    // MOSTRAR LOS NUEVOS RESULTADOS
    empleados.imprimirInformacion();

    // ORDENAR POR EDAD
    std::cout << "LISTA ORDENADA POR EDAD: \n";
    empleados.ordenarPorEdad();

    // MOSTRAR LA LISTA ORDENADA
    empleados.imprimirInformacion();

    // ORDENAR POR APELLIDOS
    std::cout << "LISTA ORDENADA POR APELLIDOS: \n";
    empleados.ordenarPorApellidos();

    // MOSTRAR LA LISTA ORDENADA
    empleados.imprimirInformacion();

    return 0;
}
