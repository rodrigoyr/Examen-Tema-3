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
        auto it = symbolTable.find(name);

        if (it != symbolTable.end()) {
            return it->second;
        } else {

            std::cerr << "Error: El símbolo '" << name << "' no está definido." << std::endl;
            return 0;
