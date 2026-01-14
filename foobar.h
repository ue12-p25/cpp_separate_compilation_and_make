#pragma once

#include "integer.h"

// une première fonction est déclarée ET définie ici
// DONC elle DOIT être qualifiée inline
// elle n'aura ainsi pas de corps - pas d'adresse
// les appels seront remplacés par le code

inline void foo(Integer &i)
{
    i.decr();
}

// une seconde fonction n'est que déclarée
// elle sera définie dans foobar.cpp
// les appels de bar seront de vrais appels de fonctions
// la fonction bar aura une adresse
void bar(Integer &);
