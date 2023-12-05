#include <iostream>
#include <variant>
#include <unordered_map>
#include <string>

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

class AdventureGame {
public:
    AdventureGame(const Environment& env) : environment(env) {}

    void startAdventure() {
        std::cout << "¡Bienvenido a la aventura!\n";
        std::string playerName = getPlayerName();
        environment.setVariable("playerName", playerName);

        customizeGameEnvironment();

        std::cout << "¡Comencemos, " << playerName << "!\n";
        displayGameInfo();
    }

    void customizeGameEnvironment() {
        environment.setVariable("enemyHealth", 100);
        environment.setVariable("playerCoins", 50);
        environment.setVariable("gameDifficulty", "Normal");
    }

    void displayGameInfo() const {
        std::cout << "Información del jugador:\n";
        std::cout << "Nombre: " << std::get<std::string>(environment.getVariable("playerName")) << "\n";
        std::cout << "Monedas: " << std::get<int>(environment.getVariable("playerCoins")) << "\n";
        std::cout << "Dificultad: " << std::get<std::string>(environment.getVariable("gameDifficulty")) << "\n";
    }

private:
    Environment environment;

    std::string getPlayerName() const {
        std::string playerName;
        std::cout << "Ingrese su nombre de jugador: ";
        std::cin >> playerName;
        return playerName;
    }
};

int main() {
    Environment globalEnvironment;

    AdventureGame game(globalEnvironment);
    game.startAdventure();

    return 0;
}
