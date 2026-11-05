*Este proyecto ha sido creado como parte del currículo de 42 por svalero, niesteba.*

# Push_swap

## Descripción

**Push_swap** es un proyecto de algoritmia y estructuras de datos cuyo objetivo principal es ordenar una pila de números enteros utilizando un conjunto limitado de instrucciones, una pila auxiliar y el menor número de operaciones posible. 

El programa recibe por parámetro una lista de números enteros en la **pila A** (`stack[0]`), mientras que la **pila B** (`stack[1]`) comienza vacía. A través de operaciones de intercambio (*swap*), rotación (*rotate* y *reverse rotate*) y empuje entre pilas (*push*), el programa calcula y muestra por la salida estándar (`stdout`) la secuencia exacta de movimientos para dejar la pila A completamente ordenada de menor a mayor.

Además del comportamiento estándar, esta implementación incorpora un motor **adaptativo** que analiza el índice de desorden inicial de los datos y permite seleccionar manualmente distintas estrategias de ordenamiento mediante *flags* (`--simple`, `--medium`, `--complex`, `--adaptative`) junto con un modo de análisis de rendimiento (`--bench`) que muestra estadísticas detalladas por la salida de error (`stderr`).

---

## Instrucciones

### Compilación

El proyecto cuenta con un `Makefile` que compila automáticamente la librería auxiliar `libft` y los archivos fuente del proyecto utilizando `cc` con los flags `-Wall -Wextra -Werror`.

Para compilar el ejecutable `push_swap`:
```bash
make
```

**Reglas adicionales del Makefile:**
* `make clean`: Elimina todos los archivos objeto (`.o`) tanto del proyecto como de `libft`.
* `make fclean`: Ejecuta `clean` y elimina los binarios generados (`push_swap`, `checker` y `libft.a`).
* `make re`: Limpia el repositorio por completo y recompila desde cero.

### Ejecución y Uso

Puedes pasar los números como múltiples argumentos o como una única cadena de texto entrecomillada:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
./push_swap 1 2 3 "4 5 6"
```
Aquí unos ejemplos de error:
```bash
./push_swap
./push_swap 1 --simple
./push_swap --complex
./push_swap 1 2 3 1
./push_swap "--medium -- bench" 2 3 1 4
./push_swap 1 -2 1 - 4
```

#### Flags de Estrategia y Benchmark

El programa admite banderas opcionales al inicio de los argumentos, y solo una por rgumento para forzar un algoritmo específico o activar las métricas de rendimiento:

* `--simple`: Fuerza el algoritmo de extracción de mínimos $O(n^2)$.
* `--medium`: Fuerza el algoritmo por bloques/chunks $O(n\sqrt{n})$.
* `--complex`: Fuerza el algoritmo Quick Sort adaptado $O(n \log n)$.
* `--adaptative`: Selecciona automáticamente la estrategia según el desorden (comportamiento por defecto si no se especifica flag de estrategia).
* `--bench`: Imprime en `stderr` el porcentaje de desorden inicial, la estrategia empleada, el número total de operaciones y el desglose individual de cada instrucción ejecutada.

**Ejemplos con flags:**
```bash
./push_swap --bench 4 67 3 87 23
./push_swap --complex --bench "4 67 3 87 23"
```

---

## Explicación y Justificación de los Algoritmos

### 1. Preprocesamiento e Indexación (`set_target_position`)
Antes de ejecutar cualquier estrategia de ordenación, los valores de entrada se normalizan asignando a cada nodo su **índice objetivo (`target`)** en el rango $[0, n - 1]$. Para ello, se vuelcan los números en un array temporal, se ordenan mediante *Insertion Sort* y se asocia cada valor con su posición final. 
* **Justificación:** Trabajar con rangos continuos de índices en lugar de valores arbitrarios (que pueden ir desde `INT_MIN` hasta `INT_MAX`) simplifica el cálculo de medianas y particiones, evitando desbordamientos aritméticos y mejorando la precisión al dividir bloques.

### 2. Estrategia Adaptativa (`adaptive_sort`)
Cuando el programa se ejecuta por defecto o con `--adaptative`, calcula primero el **índice de desorden** contando el número de inversiones en la pila A respecto al total de pares posibles $\frac{n(n - 1)}{2}$:

$$\text{Desorden} = \frac{\text{Inversiones}}{\frac{n(n-1)}{2}}$$

En función de este ratio (entre `0.0` y `1.0`), elige la estrategia óptima:
* **Desorden $< 0.2$ (20%):** Ejecuta la estrategia **Simple**.
* **$0.2 \le$ Desorden $< 0.5$ (50%):** Ejecuta la estrategia **Medium**.
* **Desorden $\ge 0.5$ (50%):** Ejecuta la estrategia **Complex**.

* **Justificación:** Un algoritmo complejo como *Quick Sort* realiza particiones agresivas que pueden generar movimientos innecesarios si la lista ya está casi ordenada. Evaluar el desorden permite aprovechar la baja sobrecarga de algoritmos simples en listas casi ordenadas y reservar la potencia asintótica de $O(n \log n)$ para listas altamente desordenadas.

### 3. Estrategias de Ordenamiento

* **Simple ($O(n^2)$) — Extracción de Mínimos (`min_extraction_sort`):**
  Recorre la pila A buscando el elemento con el valor mínimo actual, calcula si es más corto llevarlo a la cima mediante rotaciones normales (`ra`) o inversas (`rra`), y lo empuja a la pila B (`pb`). Este proceso se repite hasta que el bloque restante en A ya está ordenado. Finalmente, se devuelven todos los elementos de B a A con `pa`.
  * *Justificación:* Es un enfoque determinista sin sobrecarga de estructuras adicionales, óptimo para conjuntos muy pequeños de datos o listas con un nivel de desorden inferior al 20%.

* **Medium:**

* **Complex ($O(n \log n)$) — Quick Sort de 3 Vías en Pilas (`quick_sort`):**
  Implementa un algoritmo recursivo de tipo *Divide y Vencerás* adaptado a dos pilas. En cada llamada sobre un bloque de tamaño `block_size`:
  1. Si el bloque tiene 3 elementos o menos (o ya está ordenado), se resuelve directamente en el sitio con funciones específicas de bajo coste (`sort_3`, `handle_block`).
  2. Si es mayor, se calcula el pivote central, que es la mediana (`med`) a partir del mínimo y máximo del bloque actual.
  3. **Partición con pre-división:** Cuando se divide desde la pila A (`curr_stack == 0`), los elementos mayores que la mediana se mantienen en A (`ra`) y los menores o iguales se envían a B (`pb`). Además, para bloques de tamaño $\ge 6$, se aplica una optimización de 3 vías: si el número enviado a B es menor que $\text{med} - \frac{\text{size} + 1}{4}$, se rota hacia el fondo de B (`rb`), separando simultáneamente los elementos en tres tercios (altos en A, medios arriba de B, bajos en el fondo de B).
  4. Tras restaurar las posiciones relativas de las pilas (`restore_stack`) para no alterar bloques previos, se aplican llamadas recursivas a cada sub-bloque hasta completar la ordenación.
  * *Justificación:* El particionamiento recursivo en 3 vías reduce drásticamente la profundidad del árbol de recursión y el número de rotaciones necesarias al minimizar la distancia que recorren los elementos extremos, logrando el mejor rendimiento para entradas grandes (100 a 500+ números) con alto grado de desorden.

---

## Operaciones Disponibles

| Código | Instrucción | Acción |
| :--- | :--- | :--- |
| `sa` | Swap A | Intercambia los dos primeros elementos en la cima de la pila A. |
| `sb` | Swap B | Intercambia los dos primeros elementos en la cima de la pila B. |
| `ss` | Swap A y B | Ejecuta `sa` y `sb` simultáneamente. |
| `pa` | Push A | Toma el primer elemento de la pila B y lo coloca en la cima de la pila A. |
| `pb` | Push B | Toma el primer elemento de la pila A y lo coloca en la cima de la pila B. |
| `ra` | Rotate A | Desplaza hacia arriba todos los elementos de la pila A (el primero pasa a ser el último). |
| `rb` | Rotate B | Desplaza hacia arriba todos los elementos de la pila B (el primero pasa a ser el último). |
| `rr` | Rotate A y B | Ejecuta `ra` y `rb` simultáneamente. |
| `rra` | Reverse Rotate A | Desplaza hacia abajo todos los elementos de la pila A (el último pasa a ser el primero). |
| `rrb` | Reverse Rotate B | Desplaza hacia abajo todos los elementos de la pila B (el último pasa a ser el primero). |
| `rrr` | Reverse Rotate A y B | Ejecuta `rra` y `rrb` simultáneamente. |

---

## Recursos

### Referencias Clásicas
* **Videos sobre quick sort** - *Para ver como hacer la lógica de pivote y separación respecto al mismo*
* **Manual de C de GNU y Linux Programmer's Manual** (`man 3 malloc`, `man 2 write`).

### Uso de Inteligencia Artificial
Siguiendo las directrices del currículo de 42, las herramientas de IA (Gemini) se han empleado exclusivamente como soporte de consulta y documentación, sin generar ni copiar la lógica central del proyecto:
* **Estructuración de documentación:** Asistencia en la redacción, formato Markdown y organización de este archivo `README.md` a partir de la estructura del código fuente desarrollado por los autores.