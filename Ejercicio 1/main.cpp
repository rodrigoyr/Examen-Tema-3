#include <iostream>
#include <map>
#include <string>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {
    }

    void addSymbol(const std::string& name, int value) {
        symbolTable[name] = value;
    }

    int getSymbolValue(const std::string& name) const {
        // Verifica si el símbolo está en la tabla
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El simbolo '" << name << "' no esta definido." << std::endl;
            return 0; // Valor predeterminado en caso de error
        }
    }
};

int main() {
    Environment env;

    env.addSymbol("x", 10);
    env.addSymbol("y", 20);

    std::cout << "Valor de x: " << env.getSymbolValue("x") << std::endl; // Debería imprimir 10
    std::cout << "Valor de y: " << env.getSymbolValue("y") << std::endl; // Debería imprimir 20
    std::cout << "Valor de z: " << env.getSymbolValue("z") << std::endl; // Debería imprimir un mensaje de error y 0 por defecto

    return 0;
}
