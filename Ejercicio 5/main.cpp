#include <iostream>
#include <variant>
#include <unordered_map>

class Environment {
public:
    Environment() = default;

    void setVariable(const std::string& name, const std::variant<int, double, std::string>& value) {
        variables[name] = value;
    }

    std::variant<int, double, std::string> getVariable(const std::string& name) const {
        auto it = variables.find(name);
        if (it != variables.end()) {
            return it->second;
        } else {
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

    // Obtener valores de variables
    std::cout << "integerVar: " << std::get<int>(env.getVariable("integerVar")) << std::endl;
    std::cout << "doubleVar: " << std::get<double>(env.getVariable("doubleVar")) << std::endl;
    std::cout << "stringVar: " << std::get<std::string>(env.getVariable("stringVar")) << std::endl;

    return 0;
}
