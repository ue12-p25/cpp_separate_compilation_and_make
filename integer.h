#pragma once
#include <iostream>

// une classe d'exemple (simpliste et mal codé)
class Integer
{
    // comme on désire faire fonctionner le code:
    // Integer i;
    // std::cout << i;
    // on doit définir l'operator<< sur le type Integer
    // si il doit utiliser un attribut privé de la class
    // la classe doit lui donner accès en le déclarant friend
    friend std::ostream &operator<<(std::ostream &os, const Integer &i);

private: // private est le défaut des class (public celui des struct)
    int value = 0;

public:
    int get(); // déclaration sans définition
               // la définition est dans le .cpp

    void incr(); // déclaration sans définition
                 // la définition est dans ce .h

    void decr() { value -= 1; } // déclaration et définition
                                // par défaut decr sera inline
};

// on définit incr en dehors de la classe
// on doit spécifier que c'est la méthode incr de Integer avec Integer::incr

// on veut la définir inline
// 1) afin que le compilateur remplace les appels de cette fonction
//    par le code de la fonction
// 2) cette fonciton n'existe plus après la compilation
//    en fait une fonction inline n'a pas d'adresse

// ... en fait on DOIT la définir inline
// 1) parce que sinon elle sera DÉFINIE à chaque fois qu'on compile un .cpp qui inclut integer.h
// 2) au link on aura potentiellement plusieurs méthodes Integer::incr dans différents .o
// c++ refusera de faire l'édition de lien
//    puisqu'il existe une fonction définie plusieurs fois (multiple-defined)

inline void Integer::incr() { value += 1; }

// définition de l'opérateur << sur le Type Integer
// idem inline !! puisque définie dans un .h


inline std::ostream &operator<<(std::ostream &os, const Integer &i)
{
    // ok on aurait pu ne pas le déclarer friend et utiliser i.get()
    // mais on veut avoir un exemple de friend pour operator<<
    // os << i.get() << std::endl;
    os << i.value;
    return os; // important les << doivent pouvoir se chaîner
}