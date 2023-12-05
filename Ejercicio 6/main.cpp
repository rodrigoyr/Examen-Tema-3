#include <iostream>
#include <variant>
#include <unordered_map>

class Environment {
public:
    Environment() = default;

    void setVariable(const std::string& name, const std::variant<int, double, std::string>& value) {
        variables[name] = value;
    }

    void removeVariable(const std::string& name) {
        auto it = variables.find(name);
        if (it != variables.end()) {
            variables.erase(it);
        }
    }

    bool variableExists(const std::string& name) const {
        return variables.find(name) != variables.end();
    }

    void printEnvironment() const {
        std::cout << "Environment Variables:\n";
        for (const auto& entry : variables) {
            std::cout << entry.first << ": ";
            std::visit([](const auto& value) {
                std::cout << value;
            }, entry.second);
            std::cout << std::endl;
        }
    }

    std::variant<int, double, std::string> getVariable(const std::string& name) const {
        auto it = variables.find(name);
        if (it != variables.end()) {
            return it->second;
        } else {
            // Valor predeterminado si la variable no está definida
            return std::variant<int, double, std::string>{};
        }
    }

private:
    std::unordered_map<std::string, std::variant<int, double, std::string>> variables;
};

int main() {
    Environment env;

    env.setVariable("integerVar", 42);
    env.setVariable("doubleVar", 3.14);
    env.setVariable("stringVar", "Hello, World!");

    env.printEnvironment();

    env.removeVariable("doubleVar");

    if (env.variableExists("doubleVar")) {
        std::cout << "doubleVar exists.\n";
    } else {
        std::cout << "doubleVar does not exist.\n";
    }

    env.printEnvironment();

    return 0;
}
