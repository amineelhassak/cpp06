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
## 2. Conversion entre types de pointeurs ou références compatibles

Pour convertir un pointeur d'un type de base vers un type dérivé ou l'inverse, si les types sont compatibles. Cependant, cela nécessite que les conversions soient connues et sûres à la compilation.

```cpp
class Base {};
class Derived : public Base {};

Base* basePtr = new Derived();
Derived* derivedPtr = static_cast<Derived*>(basePtr);  // Conversion de pointeur de base en dérivé
```
## 3. Conversions explicites entre classes

Utilisé pour appeler explicitement un constructeur de conversion ou un opérateur de conversion défini dans une classe.

```cpp
class Foo {
public:
    Foo(int x) { /*...*/ }
};

int num = 42;
Foo fooObject = static_cast<Foo>(num);  // Utilise le constructeur Foo(int)
```
## 4. Conversion de type énuméré

Pour convertir un type énuméré vers un autre type numérique ou vice versa.

```cpp
enum class Colors { Red, Green, Blue };
int colorCode = static_cast<int>(Colors::Red);  // Convertit le type énuméré en entier
```
### Caractéristiques de `static_cast`

- **Vérification à la compilation** : `static_cast` est vérifié à la compilation, ce qui le rend plus sûr que `reinterpret_cast`. Si la conversion est illégale, le compilateur générera une erreur.

- **Pas de vérification à l'exécution** : Contrairement à `dynamic_cast`, `static_cast` ne fait pas de vérification à l'exécution. Cela signifie que si vous utilisez `static_cast` pour convertir un type de base en type dérivé de manière incorrecte, le résultat peut être imprévisible.

- **Utilisable avec les types de base et les types dérivés** : `static_cast` peut être utilisé pour effectuer des conversions ascendantes (upcast) et descendantes (downcast) entre types de base et types dérivés. Cependant, il est de la responsabilité du programmeur de s'assurer que la conversion descendante (downcast) est sûre.
## Exemples supplémentaires

### Conversion ascendante (Upcast) avec `static_cast`

Convertir un pointeur ou une référence de type dérivé en type de base est sûr et peut être fait implicitement, mais `static_cast` peut également être utilisé pour le rendre explicite :

```cpp
class Base {};
class Derived : public Base {};

Derived derivedObject;
Base* basePtr = static_cast<Base*>(&derivedObject);  // Conversion de Derived* à Base*
```
### Conversion descendante (Downcast) avec `static_cast`

Convertir un pointeur ou une référence de type base en type dérivé nécessite `static_cast` pour être explicite :

```cpp
class Base {};
class Derived : public Base {};

Base* basePtr = new Derived();
Derived* derivedPtr = static_cast<Derived*>(basePtr);  // Conversion de Base* à Derived*
```
## Précautions

- **Usage incorrect peut provoquer des comportements indéfinis** : Utiliser `static_cast` pour des conversions qui ne sont pas sûres (comme un mauvais downcast) peut causer des comportements indéfinis.

- **Différent de `reinterpret_cast`** : Contrairement à `reinterpret_cast`, `static_cast` ne change pas la représentation binaire du type, sauf dans des cas bien définis (comme les conversions de type numérique).

## Conclusion

`static_cast` est un outil puissant et sûr pour effectuer des conversions de type connues à la compilation. Il est recommandé de l'utiliser lorsque les types sont connus et compatibles et qu'il n'est pas nécessaire de vérifier la sécurité de la conversion à l'exécution.
| Type de Cast           | Description                                                                                 | Vérification à la Compilation | Vérification à l'Exécution | Utilisation Principale                                                        | Exemple de Code                                                                                                                                                                                             |
|------------------------|---------------------------------------------------------------------------------------------|-------------------------------|----------------------------|-------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **`static_cast`**      | Conversion de type entre types compatibles. Vérifié à la compilation.                      | Oui                           | Non                        | Conversions numériques, conversions entre types de pointeurs compatibles, conversions explicites entre classes. | ```cpp<br>// Conversion numérique<br>double pi = 3.14;<br>int integerPi = static_cast<int>(pi);  // Conversion de double en int<br><br>// Conversion entre types de pointeurs<br>class Base {};<br>class Derived : public Base {};<br>Base* basePtr = new Derived();<br>Derived* derivedPtr = static_cast<Derived*>(basePtr);  // Conversion de pointeur de base en dérivé<br><br>// Conversion explicite entre classes<br>class Foo {<br>public:<br>    Foo(int x) { /*...*/ }<br>};<br>int num = 42;<br>Foo fooObject = static_cast<Foo>(num);  // Utilise le constructeur Foo(int)<br>``` |
| **`dynamic_cast`**     | Conversion de type avec vérification à l'exécution. Utilisé principalement pour le polymorphisme. | Oui                           | Oui                        | Conversion entre types de base et dérivé dans le contexte du polymorphisme (requiert RTTI). | ```cpp<br>// Conversion avec vérification à l'exécution<br>class Base { virtual ~Base() {} };<br>class Derived : public Base {};<br>Base* basePtr = new Derived();<br>Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Conversion avec vérification à l'exécution<br><br>// Exemple avec des pointeurs<br>Base* basePtr = new Derived();<br>Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);<br>if (derivedPtr) {<br>    // Conversion réussie<br>}<br>else {<br>    // Conversion échouée<br>}<br><br>// Exemple avec des références<br>Base& baseRef = Derived();<br>try {<br>    Derived& derivedRef = dynamic_cast<Derived&>(baseRef);<br>} catch (std::bad_cast&) {<br>    // Conversion échouée<br>}<br>``` |
| **`const_cast`**       | Ajoute ou retire la constance ou la volatilité d'un type.                                  | Oui                           | Non                        | Modification des attributs `const` ou `volatile` d'un objet.                 | ```cpp<br>// Retirer constabilité<br>void print(const int* value) { std::cout << *value << std::endl; }<br>int num = 10;<br>print(&num);<br>const_cast<int*>(&num) = 20;  // Retirer constabilité<br><br>// Ajouter constabilité<br>int* ptr = new int(5);<br>const int* constPtr = const_cast<const int*>(ptr);<br>std::cout << *constPtr << std::endl;  // Ajouter constabilité<br><br>// Conversion const<->non-const<br>const int value = 100;<br>int& nonConstRef = const_cast<int&>(value);<br>nonConstRef = 200;  // Modifier la valeur<br>``` |
| **`reinterpret_cast`** | Conversion entre types de données qui n'ont pas nécessairement de relation entre eux.     | Non                           | Non                        | Conversion bas niveau, comme la manipulation directe de bits ou d'adresses.  | ```cpp<br>// Conversion de int* à char*<br>int num = 65;<br>char* ptr = reinterpret_cast<char*>(&num);<br>std::cout << *ptr << std::endl;  // Affiche le premier octet de num<br><br>// Conversion entre pointeurs non liés<br>float value = 3.14f;<br>int* intPtr = reinterpret_cast<int*>(&value);<br>std::cout << *intPtr << std::endl;  // Affiche les bits de value interprétés comme int<br><br>// Conversion de pointeurs d'objets<br>struct A { int x; };<br>struct B { int y; };<br>A a;<br>B* b = reinterpret_cast<B*>(&a);<br>b->y = 10;  // Modifier les données via B*<br>``` |
