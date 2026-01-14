#include <iostream>
#include "integer.h"
#include "foobar.h"

// appel de la fonction bar
// 1) normalement
// 2) en utilisant son adresse...

// déclaration d'un type pointeur (*) sur une fonction
//    qui renvoie void
//    et qui prend en Integer& en argument
using bar_ptr_type = void (*)(Integer &);

int main()
{
    Integer i;
    std::cout << "au départ i vaut " << i << std::endl;

    bar(i);
    std::cout << "a) i vaut " << i << std::endl;

    // appel de la fonction bar à travers deux pointeurs sur fonction
    // 1) le premier du type défini au dessus
    bar_ptr_type bar_ptr_1 = bar;  // ou &bar mais c'est identique
    bar_ptr_1(i);
    std::cout << "b) i vaut " << i << std::endl;

    // 2) directement sans définir le type bar_ptr_type
    // bar_ptr_1 est un pointeur (*bar_ptr_1)
    //    sur une fonction qui renvoie void
    //    et qui prend en Integer& en argument
    void (*bar_ptr_2)(Integer &) = bar;

    bar_ptr_2(i);
    std::cout << "c) i vaut " << i << std::endl;

    foo(i);
    std::cout << "d) i vaut " << i << std::endl;

    i.incr();
    std::cout << "e) i vaut " << i << std::endl;

    // horrrrible
    i.get() = 99;
    std::cout << "on fait l'instruction \"i.get()= 99;\"\n";
    std::cout << "f) on affiche i.get() " << i.get() << std::endl;
}