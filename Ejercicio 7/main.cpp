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
            // Valor predeterminado si la variable no está definida
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

        performGameActions();

        std::cout << "¡Enhorabuena, has ganado!\n";
    }

private:
    Environment environment;

    std::string getPlayerName() const {
        std::string playerName;
        std::cout << "Ingrese su nombre de jugador: ";
        std::cin >> playerName;
        return playerName;
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

    void performGameActions() {
        performGameAction("Encuentro con un enemigo");
        performGameAction("Descubrimiento de un tesoro");
    }

    void performGameAction(const std::string& actionName) {
        std::cout << "\n" << actionName << "!\n";

        if (actionName == "Encuentro con un enemigo") {
            int enemyHealth = std::get<int>(environment.getVariable("enemyHealth"));
            // Realiza acciones de combate y actualiza la salud del enemigo
            // ...

            std::cout << "¡Enemigo derrotado! La salud restante del enemigo es: " << enemyHealth << "\n";
            // Actualiza la variable en el entorno
            environment.setVariable("enemyHealth", enemyHealth);
        } else if (actionName == "Descubrimiento de un tesoro") {
            int playerCoins = std::get<int>(environment.getVariable("playerCoins"));


            std::cout << "¡Has encontrado un tesoro! Monedas obtenidas: " << playerCoins << "\n";
            environment.setVariable("playerCoins", playerCoins);
        }

        displayGameInfo();
    }
};

int main() {
    Environment globalEnvironment;

    AdventureGame game(globalEnvironment);
    game.startAdventure();

    return 0;
}
