#include <iostream>
#include <exception>
#include <map>
#include <string>
#include <stdexcept>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {
    }

    void insertSymbol(const std::string& name, int value) {
        auto result = symbolTable.insert({name, value});

        if (!result.second) {
            throw std::invalid_argument("Error: El símbolo '" + name + "' ya existe en el entorno.");
        }

        std::cout << "Símbolo '" << name << "' insertado correctamente." << std::endl;
    }

    int lookupSymbol(const std::string& name, int defaultValue = 0) const {
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::out_of_range("Error: El simbolo '" + name + "' no esta definido en el entorno.");
        }
    }
};

int main() {
    Environment env;

    try {
        env.insertSymbol("x", 10);
        env.insertSymbol("y", 20);
        env.insertSymbol("z", 30);

        std::cout << "Valor de x: " << env.lookupSymbol("x") << std::endl;
        std::cout << "Valor de y: " << env.lookupSymbol("y") << std::endl;
        std::cout << "Valor de z: " << env.lookupSymbol("z") << std::endl;

        std::cout << "Valor de w: " << env.lookupSymbol("w") << std::endl;

        env.insertSymbol("x", 50);
    } catch (const std::exception& e) {
        std::cerr << "Excepcion: " << e.what() << std::endl;
    }

    return 0;
}
