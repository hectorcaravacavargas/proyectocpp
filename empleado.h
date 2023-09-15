#include <iostream>
#include <string>

// NOMBRE DE LA EMPRESA: LuxeHeJos SA

struct ConsultarSalario {
    int horasLaboradas, diasTrabajados;
    bool feriados, turnoEspecial, horarioRegular;
    std::string categoria, tipoContrato;

    // CONSTRUCTOR DE LA ESTRUCTURA CONSULTARSALARIO
    ConsultarSalario(int _horasLaboradas, int _diasTrabajados, bool _feriados, bool _turnoEspecial, bool _horarioRegular, std::string _categoria, std::string _tipoContrato) {
        horasLaboradas = _horasLaboradas;
        feriados = _feriados;
        turnoEspecial = _turnoEspecial;
        categoria = _categoria;
        diasTrabajados = _diasTrabajados;
        horarioRegular = _horarioRegular;
        tipoContrato = _tipoContrato;
    }
};

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
    Empleado *inicio;

public:
    // CONSTRUCTOR
    Empleado(std::string _nombre, std::string _apellido, int _edad, std::string _tipoContrato, float _salarioBase,
    float _complementosSalariales, std::string _categoria, std::string _sector, Empleado* _jefe) {

        nombre = _nombre;
        apellido = _apellido;
        edad = _edad;
        tipoContrato = _tipoContrato;
        salarioBase = _salarioBase;
        complementosSalariales = _complementosSalariales;
        categoria = _categoria;
        sector = _sector;
        jefe = _jefe;
        inicio = nullptr; // ASIGNAR INICIO A NULL
    }

    // METODOS GETTERS
    std::string getNombre() const {
        return nombre;
    }

    std::string getApellido() const {
        return apellido;
    }

    int getEdad() const {
        return edad;
    }

    std::string getTipoContrato() const {
        return tipoContrato;
    }

    float getSalarioBase() const {
        return salarioBase;
    }

    float getComplementosSalariales() const {
        return complementosSalariales;
    }

    std::string getCategoria() const {
        return categoria;
    }

    std::string getSector() const {
        return sector;
    }

    Empleado* getJefe() const {
        return jefe;
    }

    Empleado* getInicio() const {
        return inicio;
    }

    Empleado* getSig() const {
        return sig;
    }

    // METODOS SETTERS
    void setNombre(const std::string& _nombre) {
        nombre = _nombre;
    }

    void setApellido(const std::string& _apellido) {
        apellido = _apellido;
    }

    void setEdad(int _edad) {
        edad = _edad;
    }

    void setTipoContrato(const std::string& _tipoContrato) {
        tipoContrato = _tipoContrato;
    }

    void setSalarioBase(float _salarioBase) {
        salarioBase = _salarioBase;
    }

    void setComplementosSalariales(float _complementosSalariales) {
        complementosSalariales = _complementosSalariales;
    }

    void setCategoria(const std::string& _categoria) {
        categoria = _categoria;
    }

    void setSector(const std::string& _sector) {
        sector = _sector;
    }

    void setJefe(Empleado* _jefe) {
        jefe = _jefe;
    }

    void setInicio(Empleado* _inicio) {
        inicio = _inicio;
    }

    void setSig(Empleado* _sig) {
        sig = _sig;
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

        Empleado* nuevo = new Empleado("", "", 0, "", 0.0, 0.0, "", "", nullptr); // Crear una instancia de Empleado

        // Usar los setters para asignar valores
        nuevo->setNombre(nombre);
        nuevo->setApellido(apellido);
        nuevo->setEdad(_edad);
        nuevo->setTipoContrato(_tipoContrato);
        nuevo->setSalarioBase(_salarioBase);
        nuevo->setComplementosSalariales(_complementosSalariales);
        nuevo->setCategoria(_categoria);
        nuevo->setSector(_sector);
        nuevo->setJefe(_jefe);

        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Empleado* aux = inicio;
            while (aux->getSig() != nullptr) {
                aux = aux->getSig();
            }
            aux->setSig(nuevo);
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
            if (aux->getNombre() == nombre && aux->getApellido() == apellido) {
                // Utilizar setters para actualizar la información del empleado
                aux->setNombre(nuevoEmpleado.getNombre());
                aux->setApellido(nuevoEmpleado.getApellido());
                aux->setEdad(nuevoEmpleado.getEdad());
                aux->setTipoContrato(nuevoEmpleado.getTipoContrato());
                aux->setSalarioBase(nuevoEmpleado.getSalarioBase());
                aux->setComplementosSalariales(nuevoEmpleado.getComplementosSalariales());
                aux->setCategoria(nuevoEmpleado.getCategoria());
                aux->setSector(nuevoEmpleado.getSector());
                aux->setJefe(nuevoEmpleado.getJefe());

                std::cout << "Empleado " << nombre << " " << apellido << " modificado exitosamente." << std::endl;
                return;
            }
            aux = aux->getSig();
        }
        std::cout << "Empleado con nombre " << nombre << " y apellido: " << apellido << " no encontrado." << std::endl;
    }

    // METODO PARA ELIMINAR EMPLEADOS;
    void eliminarEmpleado(std::string nombre, std::string apellido) {
        Empleado* aux = inicio;
        Empleado* anterior = nullptr;

        while (aux != nullptr) {
            if (aux->getNombre() == nombre && aux->getApellido() == apellido) {
                if (anterior == nullptr) {
                    inicio = aux->getSig();
                } else {
                    anterior->setSig(aux->getSig());
                }

                std::cout << "Empleado " << nombre << " " << apellido << " eliminado exitosamente." << std::endl;

                // Eliminar la instancia de empleado para liberar memoria
                delete aux;

                return;
            }

            anterior = aux;
            aux = aux->getSig();
        }

        std::cout << "Empleado con nombre " << nombre << " y apellido: " << apellido << " no encontrado." << std::endl;
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

            while (actual->getSig() != nullptr) {
                siguiente = actual->getSig();

                if (actual->getEdad() > siguiente->getEdad()) {
                    // INTERCAMBIAR LOS EMPLEADOS CON EL MÉTODO SWAP
                    Empleado temp = *actual;  // Copia temporal para el intercambio
                    actual->actualizarEmpleado(*siguiente);
                    siguiente->actualizarEmpleado(temp);

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
            siguiente = actual->getSig();

            while (siguiente != nullptr) {
                if (actual->getApellido()[0] > siguiente->getApellido()[0]) {
                    // INTERCAMBIA LOS EMPLEADOS CON EL MÉTODO SWAP
                    Empleado temp = *actual;  // Copia temporal para el intercambio
                    actual->actualizarEmpleado(*siguiente);
                    siguiente->actualizarEmpleado(temp);
                }
                siguiente = siguiente->getSig();
            }
            actual = actual->getSig();
        }
    }

    // METODO CONSULTAR SALARIO
    void consultarSalario(const ConsultarSalario& consulta) {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            if (aux->getCategoria() == consulta.categoria) {
                float salario = aux->getSalarioBase();

                // CALCULAR SALARIO BASE
                if (consulta.tipoContrato == "Hora") {
                    salario *= consulta.horasLaboradas;
                } else if (consulta.tipoContrato == "Jornada Completa") {
                    salario *= consulta.diasTrabajados;
                }

                // APLICAR FACTORES ADICIONALES
                if (consulta.horasLaboradas > 40) {
                    salario += (consulta.horasLaboradas - 40) * aux->getSalarioBase() * 1.5;
                }

                if (consulta.feriados) {
                    salario *= 2.0; // DOBLE SALARIOS EN FERIADOS
                }

                // IMPRIMIR EL SALARIO CALCULADO
                std::cout << "Salario de " << aux->getNombre() << " " << aux->getApellido() << ": $" << salario << std::endl;
            }
            aux = aux->sig;
        }
    }

};
