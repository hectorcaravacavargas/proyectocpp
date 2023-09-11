#include <iostream>
#include <string>

// NOMBRE DE LA EMPRESA: LuxeHeJos SA

class Empleado {
private:
    // ATRIBUTOS BASICOS DEL EMPLEADO
    std::string nombre, apellido, tipoContrato; // TIPO DE CONTRATO PUEDE SER HORA O JORNADA COMPLETA
    int edad;

    // ATRIBUTOS PARA EL CALCULO DEL SALARIO
    float salarioBase, complementosSalariales;

    // ATRIBUTOS RELACIONADOS CON EL TRABAJO
    std::string categoria, sector;

    // PUNTERO JEFE
    Empleado *jefe;

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
};

int main() {
    // EJEMPLOS DEL USO DE EMPLEADOS
    Empleado empleado1("Juan", "Perez", 30, "Jornada Completa", 3000.0, 500.0, "Supervisor", "Produccion", nullptr);
    Empleado empleado2("Ana", "Gomez", 25, "Hora", 15.0, 100.0, "Operario", "Produccion", &empleado1);

    // FUNCION IMPRIMIR INFORMACION DE LOS EMPLEADOS
    empleado1.imprimirInformacion();
    std::cout << "\n";
    empleado2.imprimirInformacion();

    return 0;
}
