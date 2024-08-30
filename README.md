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
\033[1;34m2. Conversion entre types de pointeurs ou références compatibles\033[0m
Pour convertir un pointeur d'un type de base vers un type dérivé ou l'inverse, si les types sont compatibles. Cependant, cela nécessite que les conversions soient connues et sûres à la compilation.

\033[1;32m```cpp\033[0m
\033[1;32mclass Base {};\033[0m
\033[1;32mclass Derived : public Base {};\033[0m

\033[1;32mBase* basePtr = new Derived();\033[0m
\033[1;32mDerived* derivedPtr = static_cast<Derived*>(basePtr);  // Conversion de pointeur de base en dérivé\033[0m
\033[1;32m```\033[0m

\033[1;34m3. Conversions explicites entre classes\033[0m
Utilisé pour appeler explicitement un constructeur de conversion ou un opérateur de conversion défini dans une classe.

\033[1;32m```cpp\033[0m
\033[1;32mclass Foo {\033[0m
\033[1;32mpublic:\033[0m
\033[1;32m    Foo(int x) { /*...*/ }\033[0m
\033[1;32m};\033[0m

\033[1;32mint num = 42;\033[0m
\033[1;32mFoo fooObject = static_cast<Foo>(num);  // Utilise le constructeur Foo(int)\033[0m
\033[1;32m```\033[0m

\033[1;34m4. Conversion de type énuméré\033[0m
Pour convertir un type énuméré vers un autre type numérique ou vice versa.

\033[1;32m```cpp\033[0m
\033[1;32menum class Colors { Red, Green, Blue };\033[0m
\033[1;32mint colorCode = static_cast<int>(Colors::Red);  // Convertit le type énuméré en entier\033[0m
\033[1;32m```\033[0m

\033[1;34mCaractéristiques de static_cast\033[0m
- \033[1;33mVérification à la compilation\033[0m : `static_cast` est vérifié à la compilation, ce qui le rend plus sûr que `reinterpret_cast`. Si la conversion est illégale, le compilateur générera une erreur.

- \033[1;33mPas de vérification à l'exécution\033[0m : Contrairement à `dynamic_cast`, `static_cast` ne fait pas de vérification à l'exécution. Cela signifie que si vous utilisez `static_cast` pour convertir un type de base en type dérivé de manière incorrecte, le résultat peut être imprévisible.

- \033[1;33mUtilisable avec les types de base et les types dérivés\033[0m : `static_cast` peut être utilisé pour effectuer des conversions ascendantes (upcast) et descendantes (downcast) entre types de base et types dérivés. Cependant, il est de la responsabilité du programmeur de s'assurer que la conversion descendante (downcast) est sûre.

\033[1;34mExemples supplémentaires\033[0m

\033[1;34mConversion ascendante (Upcast) avec static_cast\033[0m
Convertir un pointeur ou une référence de type dérivé en type de base est sûr et peut être fait implicitement, mais `static_cast` peut également être utilisé pour le rendre explicite :

\033[1;32m```cpp\033[0m
\033[1;32mclass Base {};\033[0m
\033[1;32mclass Derived : public Base {};\033[0m

\033[1;32mDerived derivedObject;\033[0m
\033[1;32mBase* basePtr = static_cast<Base*>(&derivedObject);  // Conversion de Derived* à Base*\033[0m
\033[1;32m```\033[0m

\033[1;34mConversion descendante (Downcast) avec static_cast\033[0m
Convertir un pointeur ou une référence de type base en type dérivé nécessite `static_cast` pour être explicite :

\033[1;32m```cpp\033[0m
\033[1;32mBase* basePtr = new Derived();\033[0m
\033[1;32mDerived* derivedPtr = static_cast<Derived*>(basePtr);  // Conversion de Base* à Derived*\033[0m
\033[1;32m```\033[0m

\033[1;34mPrécautions\033[0m
- \033[1;33mUsage incorrect peut provoquer des comportements indéfinis\033[0m : Utiliser `static_cast` pour des conversions qui ne sont pas sûres (comme un mauvais downcast) peut causer des comportements indéfinis.

- \033[1;33mDifférent de reinterpret_cast\033[0m : Contrairement à `reinterpret_cast`, `static_cast` ne change pas la représentation binaire du type, sauf dans des cas bien définis (comme les conversions de type numérique).

\033[1;34mConclusion\033[0m
`static_cast` est un outil puissant et sûr pour effectuer des conversions de type connues à la compilation. Il est recommandé de l'utiliser lorsque les types sont connus et compatibles et qu'il n'est pas nécessaire de vérifier la sécurité de la conversion à l'exécution.
