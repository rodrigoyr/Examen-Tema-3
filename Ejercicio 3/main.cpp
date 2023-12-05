#include <iostream>
#include <map>
#include <string>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {
    }

    void insertSymbol(const std::string& name, int value) {
        auto result = symbolTable.insert({name, value});

        if (result.second) {
            std::cout << "Símbolo '" << name << "' insertado correctamente." << std::endl;
        } else {
            std::cerr << "Advertencia: El símbolo '" << name << "' ya existe en el entorno. No se ha realizado la inserción." << std::endl;
        }
    }

    int lookupSymbol(const std::string& name) const {
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Advertencia: El símbolo '" << name << "' no está definido en el entorno. Se devuelve el valor predeterminado 0." << std::endl;
            return 0; // Valor predeterminado si el símbolo no está definido
        }
    }
};

int main() {
    Environment env;

    env.insertSymbol("x", 10);
    env.insertSymbol("y", 20);
    env.insertSymbol("z", 30);

    std::cout << "Valor de x: " << env.lookupSymbol("x") << std::endl;
    std::cout << "Valor de y: " << env.lookupSymbol("y") << std::endl;
    std::cout << "Valor de z: " << env.lookupSymbol("z") << std::endl;

    std::cout << "Valor de w: " << env.lookupSymbol("w") << std::endl;

    return 0;
}
