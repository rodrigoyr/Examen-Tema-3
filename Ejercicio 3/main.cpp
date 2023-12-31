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
            std::cout << "Simbolo '" << name << "' insertado correctamente." << std::endl;
        } else {
            std::cerr << "Advertencia: El simbolo '" << name << "' ya existe en el entorno. No se ha realizado la insercion." << std::endl;
        }
    }

    int lookupSymbol(const std::string& name, int defaultValue = 0) const {
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Advertencia: El simbolo '" << name << "' no esta definido en el entorno. Se devuelve el valor predeterminado: " << defaultValue << "." << std::endl;
            return defaultValue;
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
    std::cout << "Valor de w: " << env.lookupSymbol("w", 100) << std::endl;
    return 0;
}
