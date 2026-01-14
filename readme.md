# compilation séparée

## introduction

L'idée de la compilation séparée est de décomposer un projet en plusieurs fichiers:

- des fichiers d'entête (header file) qui portent l'extension `.h`
- des fichiers d'implémentation (implementation file) qui portent l'extension `.cpp`

Chacun des fichiers d'implémentation sera compilé séparément pour produire le code object correspondant (object file) qui porte l'extension `.o`

Le but est:

- d'une part de décomposer un projet en entités logiques
- mais aussi, en cas de modifications, de ne recompiler que ce qui a été modifié  
afin de ne pas perdre de temps à recompiler inutilement des fichiers  
(ce qui peut être très long pour de gros projets)

Et naturellement la compilation séparée vient avec ses *inconvénient*:

1. gérer à-la-main toutes les compilations des fichiers `.cpp` en `.o` est très fastidieux  
   mais tout recompiler à chaque fois qu'on modifie quelque chose est très cher en temps

2. on peut obtenir de *mauvais exécutables* (corrupted), par exemple:

- on a une structure de donnée (une `class`ou une `struct`) définie dans un fichier d'entête `truc.h`
- on a défini certaines de ses méthodes dans un fichier d'implémentation `truc.cpp`
- on modifie la structure de donnée dans `truc.h`
- ... on **oublie** de recompiler le fichier d'implémentation `truc.cpp`
- on *linke* les `.o` avec une *vielle version* de `truc.o` qui n'est plus compatible avec `truc.h`
- l'exécutable va planter...

D'où l'idée depuis le début du langage `c` de proposer des systèmes pour compiler nos codes.

Le premier le plus *basique*  est le simple `Makefile` avec sa commande `make`. On définit dans le fichier `Makefile`:

- les dépendances entre les fichiers (qui sont fondées sur les dates des fichiers)
  - on ne recompile un `.cpp` que si lui ou un des `.h` dont il dépend (i.e. qu'il inclut) ont été modifiés depuis que son `.o` a été compilé  
     i.e. *sont plus récent* que le `.o`
- et les règles de compilation (comment compiler, linker, gérer les librairies non-standards...)

Il existe des systèmes plus évoluées, comme par exemple les `cmakefile` et la commande `cmake` mais on va utiliser quelque chose de basique - vous regarderez les autres par vous même.

Si vous n'avez pas `make`, faire dans un terminal (WSL ou mac)  

```
sudo apt-get install make
```

## devoirs

Faites dans un terminal (WSL ou mac):
les **7 tests** suivants les uns après les autres en lisant ce qui se passe (ce que vous raconte `make` et les éventuelles erreurs):

1.
    ```
    make integer
    ```

1.
    ```
    touch integer.h
    make integer
    ```

1.
    ```
    rm foobar.o
    make foobar.o
    ```

1.
    ```
    make integer
    ```

1.
    `make` sans argument appelle` *la première règle définie dans le makefile*.
    ```
    make clean
    make
    ```

1. Enlever le qualifier `inline` de la fonction `foo` du fichier `foobar.h`
    ```
    make
    ```

1.
    Remettez le `inline` devant `foo`.

    Mettez un `inline` devant la méthode `bar` de `foobar.cpp`

    ```
    make
    ```
