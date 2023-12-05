#include <iostream>
#include <map>
#include <variant>

class Environment {
public:

    using SymbolTable = std::map<std::string, std::variant<int, double, std::string>>;


    void insert(const std::string& name, const std::variant<int, double, std::string>& value) {

        auto it = symbols.find(name);
        if (it != symbols.end()) {

            if (it->second != value) {
                throw std::runtime_error("Error: El símbolo ya existe con un valor diferente.");
            }
        } else {

            symbols[name] = value;
        }
    }

    std::variant<int, double, std::string> lookup(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Error: El símbolo no existe en el entorno.");
        }
    }

    void remove(const std::string& name) {
        symbols.erase(name);
    }

    bool exists(const std::string& name) const {
        return symbols.find(name) != symbols.end();
    }


    void printSymbols() const {
        std::cout << "Tabla de Símbolos:\n";
        for (const auto& entry : symbols) {
            std::cout << entry.first << ": ";
            std::visit([](const auto& value) {
                std::cout << value;
            }, entry.second);
            std::cout << std::endl;
        }
    }

    void customizeGameEnvironment() {
        insert("enemyHealth", 100);
        insert("playerCoins", 50);
        insert("gameDifficulty", "Normal");
    }

private:
    SymbolTable symbols;
};


void gameExample() {
    Environment env;

    env.insert("playerName", "John");
    env.insert("playerLevel", 5);

    if (env.exists("playerName")) {
        std::cout << "playerName existe en el entorno.\n";
    }

    try {
        auto playerName = std::get<std::string>(env.lookup("playerName"));
        std::cout << "Valor de playerName: " << playerName << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
    }

    try {
        env.insert("playerLevel", 10);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
    }

    env.printSymbols();

    env.customizeGameEnvironment();

    env.printSymbols();
}

int main() {
    gameExample();

    return 0;
}
