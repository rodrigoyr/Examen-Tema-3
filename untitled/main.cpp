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

    int getSymbolValue(const std::string& name) const {
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {

            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0; // Valor predeterminado en caso de error
        }
    }
};

int main() {

    Environment env;

    env.insertSymbol("x", 10);
    env.insertSymbol("y", 20);
    env.insertSymbol("z", 30);
    env.insertSymbol("x", 50);

    std::cout << "Valor de x: " << env.getSymbolValue("x") << std::endl; // Debería imprimir 10
    std::cout << "Valor de y: " << env.getSymbolValue("y") << std::endl; // Debería imprimir 20
    std::cout << "Valor de z: " << env.getSymbolValue("z") << std::endl; // Debería imprimir 30

    return 0;
}
