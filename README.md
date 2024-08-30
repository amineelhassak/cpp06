# `static_cast` en C++

`static_cast` est un opérateur de conversion de type en C++ utilisé pour effectuer des conversions de types entre types compatibles de manière sécurisée à la compilation. C'est l'un des quatre types de conversions de type (casts) fournis par C++ : `static_cast`, `dynamic_cast`, `const_cast`, et `reinterpret_cast`.

## Quand utiliser `static_cast` ?

`static_cast` est utilisé principalement dans les situations suivantes :

### 1. Conversion de types numériques
Pour convertir un type de donnée numérique en un autre. Par exemple, convertir un `double` en `int`, ou un `float` en `int`.

```cpp
double pi = 3.14;
int integerPi = static_cast<int>(pi);  // Conversion de double en int
```
