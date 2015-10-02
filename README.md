# Practicas de Algorítmica

**Prácticas de la asignatura de Algorítmica de la Universidad de Granda (2014-2015)**

## Contenidos
1. __Eficiencia__: ejemplos sobre el cálculo de eficiencia en trozos de código y funciones.
2. __Divide y Vencerás__: consiste en implementar la multiplicación clásica de enteros largos y la multiplicación de enteros largos mediante el algoritmo de __Karatsuba y Offman__ y comparar la eficiencia de ambos algoritmos.
3. __Algoritmos Greedy__: implementación del problema de la mochila fraccional en C++. Teniendo un conjunto inicial de objetos, escoge aquellos que aportan mayor beneficio para una mochila de peso M, ya sea objetos enteros o fraccionados. Esto se resuelve haciendo uso de un algoritmo __Greedy__.
4. __Programación Dinámica__: implementación del problema de la mochila 0/1 en C++, pero en este caso sólo cogiendo objetos enteros (coger o no coger el objeto) y haciendo uso de un algoritmo de __Programación Dinámica__.
5. __Branch & Bound__: implementación de la mochila 0/1 en C++ haciendo uso de un algoritmo  __Branch and Bound__.

## Cómo usarlo

1. __Eficiencia__: para compilar usar:
      - *pdflatex -shell-escape efic.tex*: compilar dos veces para ver bien los enlaces.
      Nota: hay que tener el paquete *minted* de *LaTeX*, además de todo lo necesario para *LaTeX*.
2. __Divide y Vencerás__: al estar escrito en Python, es solo llamar de la siguiente forma:
      - *python multc.py entero1 entero2* para la multiplicación clásica de enteros largos.
      - *python multd.py entero1 entero2* para la multiplicación con el algortimo Divide y Vencerás de enteros largos.
3. __Algoritmos Greedy__: para poder ejecutar hay que hacer lo siguiente:
      - *make*: para compilar
      - *./bin/mochila B P B P ... PESOMOCHILA* siendo *B* el beneficio del objeto y *P* el peso del objeto
4. __Programacion Dinámica__: igual que el anterior:
      - *make*: para compilar
      - *./bin/mochila B P B P ... PESOMOCHILA*
4. __Branch & Bound__: igual que las dos anteriores:
      - *make*: para compilar
      - *./bin/mochila B P B P ... PESOMOCHILA*

