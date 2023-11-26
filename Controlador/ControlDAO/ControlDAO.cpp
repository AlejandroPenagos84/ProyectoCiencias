#include "ControlDAO.h"

ControlDAO::ControlDAO(Controlador *ctrl) : control(ctrl) {
    //Arboles con llaves secundarias y los datos completos
    hijosLlaveF = new RBTree<int,Hijo>;
    empleadosLlaveF = new RBTree<int,Empleado>;
    sucurcalesLlaveF = new RBTree<int,Sucursal>;
    ciudadesLlaveF = new RBTree<int, Ciudad>;
    paises = new RBTree<int,Pais>;
    pos = 0;
}

bool intToBool(int value) {
    // Convierte cualquier valor distinto de cero a true, y cero a false
    return (value != 0);
}

// Function to read CSV file and return a vector of CsvRow
void ControlDAO::LeerHijosDAO(const std::string &filename){
    hijosLlaveF;
    pos = 0;
    // Open the CSV file
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        //return data; // Return an empty vector since there was an error
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Split the line into columns using a comma as the delimiter
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Create a CsvRow and populate it with the values
        Hijo row;
        if (columns.size() >= 5) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.fechaNacimiento = column[3];
                row.estado = intToBool(std::stoi(columns[4]));

                // Add the row to the data vector
                hijosLlaveF->Insert(hijosLlaveF,hijosLlaveF->createNodo(row.pk,row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error converting column values to integers: " << e.what() << std::endl;
            }
        }
    }
    // Close the file
    file.close();
    //return data;
}


void ControlDAO::LeerEmpleadosDAO(const std::string &filename){
    pos=0;
    // Open the CSV file
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        //return data; // Return an empty vector since there was an error
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Split the line into columns using a comma as the delimiter
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Create a CsvRow and populate it with the values
        Empleado row;
        if (columns.size() >= 21) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.apellido = columns[3];
                row.tipoIdentificacion = columns[4];
                row.numIdentificacion = columns[5];
                row.sexo = columns[6][0];;
                row.telefonoCelular = columns[7];
                row.telefonoFijo = columns[8];
                row.email = columns[9];
                row.ciudadNacimiento = columns[10];
                row.paisNacimiento = columns[11];
                row.ciudadResidencia = columns[12];
                row.direccion = columns[13];
                row.tieneHijos = columns[14][0];
                row.actividadLaboral = columns[15];
                row.sucursalTrabajo = columns[16];
                row.barrio = columns[17];
                row.numHijos = std::stoi(columns[18]);
                row.fechaNacimiento = columns[19];
                row.estado = intToBool(std::stoi(columns[20]));


                // Add the row to the data vector
                empleadosLlaveF->Insert(empleadosLlaveF,empleadosLlaveF->createNodo(row.pk,row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error converting column values to integers: " << e.what() << std::endl;
            }
        }
    }

    // Close the file
    file.close();

    //return data;
}


void ControlDAO::LeerSucursalesDAO(const std::string &filename)
{
    pos=0;
    // Open the CSV file
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        //return data; // Return an empty vector since there was an error
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Split the line into columns using a comma as the delimiter
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Create a CsvRow and populate it with the values
        Sucursal row;
        if (columns.size() >= 7) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.direccion = (columns[3]);
                row.barrio = (columns[4]);
                row.nombreGerente = (columns[5]);
                row.estado = intToBool(std::stoi(columns[6]));

                // Add the row to the data vector
                sucurcalesLlaveF->Insert(sucurcalesLlaveF,sucurcalesLlaveF->createNodo(row.pk,row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error converting column values to integers: " << e.what() << std::endl;
            }
        }
    }
    // Close the file
    file.close();
    //return data;
}

void ControlDAO::LeerCiudadesDAO(const std::string &filename)
{
    pos=0;
    // Open the CSV file
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        //return data; // Return an empty vector since there was an error
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Split the line into columns using a comma as the delimiter
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Create a CsvRow and populate it with the values
        Ciudad row;
        if (columns.size() >= 4) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.estado = intToBool(std::stoi(columns[3]));

                // Add the row to the data vector
                ciudadesLlaveF->Insert(ciudadesLlaveF,ciudadesLlaveF->createNodo(row.pk,row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error converting column values to integers: " << e.what() << std::endl;
            }
        }
    }
    // Close the file
    file.close();
    //return data;
}


void ControlDAO::LeerPaisesDAO(const std::string &filename)
{
    pos=0;
    // Open the CSV file
    std::ifstream file(filename);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        //return data; // Return an empty vector since there was an error
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Split the line into columns using a comma as the delimiter
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Create a CsvRow and populate it with the values
        Pais row;
        if (columns.size() >= 3) {
            try {
                row.pk = std::stoi(columns[0]);
                row.nombre = (columns[1]);
                row.estado = intToBool(std::stoi(columns[2]));

                // Add the row to the data vector
                paises->Insert(paises,paises->createNodo(row.pk,row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error converting column values to integers: " << e.what() << std::endl;
            }
        }
    }
    // Close the file
    file.close();
    //return data;
}

RBTree<int, Hijo> *ControlDAO::getHijosLlaveF() const {
    return hijosLlaveF;
}

RBTree<int, Empleado> *ControlDAO::getEmpleadosLlaveF() const {
    return empleadosLlaveF;
}

RBTree<int, Sucursal> *ControlDAO::getSucurcalesLlaveF() const {
    return sucurcalesLlaveF;
}

RBTree<int, Ciudad> *ControlDAO::getCiudadesLlaveF() const {
    return ciudadesLlaveF;
}

RBTree<int, Pais> *ControlDAO::getPaises() const {
    return paises;
}


