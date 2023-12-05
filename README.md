# Examen-Tema-3
https://github.com/rodrigoyr/Examen-Tema-3.git

_Para completar mi código he utilizado el Copilot de Github en la versión de VSCode, ya que esta ofrece el chat, lo que me ha permitido interactuar con la ia y así completar mi codigo de la mejor manera posible, además para completar y resolver los errores que el codigo me ha ofrecido he usado el Copilot de Github en Clion, el cuál ofrece una alterantiva al codigo recibido y así maneja los errores, también he usado el ChatGPT para diferentes arreglos. Para el markdown del readme he utilizado el documento que ofrece Github acerca de su sintáxis._
## Parte 1: Preguntas de elección múltiple
**1. ¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?**
b) Representar cualquier tipo de dato Lisp

**2. ¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?**
a) Una cadena de texto que representa una instancia de Variant

**3. ¿Qué función cumple el método to_json_string() en la clase Variant?**
b) Convierte un objeto Variant a una cadena JSON

**4. ¿Qué función cumple el método from_json_string() en la clase Variant?**
c) Parsea un objeto JSON a un objeto Variant

## Parte 2: Pregunta de desarrollo de código: Sistema de Scripting para Motor de Videojuegos Indie
**Ejercicio 1.**
Este código implementa una clase environment con una tabla de símbolos que asigna nombres a numeros enteros. El programa  crea un entorno, agrega símbolos con numeros y luego imprime esos numeros. Si se intenta obtener el valor de un símbolo que no existe , se imprime un mensaje de error y se devuelve 0.

**Ejercicio 2.**
Esn este código también se implementa la clase environment con una tabla de símbolos que asigna nombres a numeros. Este programa crea un entorno, agrega símbolos  con numeros y luego los imprime. Si se inserta dos numeros iguales, salta una advertencia.

**Ejercicio 3.**
Este código implementa la misma con los mismos símbolos y números que antes. El programa crea un entorno, agrega símbolos con numeros y luego imprime esos numeroscon la función lookupSymbol. Si un símbolo no está, salta una advertencia y se devuelve un valor predeterminado (0 de normal).

**Ejercicio 4.** 
Este código implementa la clase environment con los símbolos y numeros. En el codigo , se crea un entorno, se agregan símbolos con números y se imprime esos numeros con la función lookupSymbol. Si se mete un símbolo que ya existe, salta una excepción de tipo std::invalid_argument y un bloque catch para imprimir un error. Si se intenta buscar un símbolo que no está, se lanza una excepción de tipo std::out_of_range` y salta el mensaje de error.

**Ejercicio 5.** 
En este código se implementa la clase Enviroment con un contenedor que nombra variables que pueden ser de tipo entero, doble o cadena. En el programa, se crea el entorno, se establecen variables con diferentesvalores y luego se obtienen y se imprimen los valores con std::get y getVariable.

**Ejercicio 6.**
Este código implementa la clase  que gestiona un entorno de variables con valores enteros, dobles o de cadena. En el programa , se crea lentorno, se establecen las variables, se imprime y luego se elimina una variable (doubleVar), se verifica si existe y se vuelve a imprimir el entorno.

**Ejercicio 7.** 
En este código se crea un minijuego de aventuras. El juego permite personalizar el entorno, encuentros con enemigos y descubrimientos de tesoros, y finalmente, muestra la información del jugador y lo felicita por ganar.

**Ejercicio 8.** 
En este ejercicio simplemente realizo mejoras el los demás códigos como así pide el enunciado.

**Ejercicio final.** 
En este codigo final uno todos los códigos realizados utilizando las partes importantes de cada codigo dentro de la clase envoronment y el entorno, finalmente realizo mejoras al darme el codigo errores al unirlo todo a la vez. Este codigo muestra  un Sistema de Scripting para Motor de Videojuegos Indie con sus estructura basica de la clase, el insertar y buscar símbolos, la gestión de errores, la integración con variant, las funcionalidades, los usos y las mejoras finales como así indico en la descripción de cada ejercicio.
