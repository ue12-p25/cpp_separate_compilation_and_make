// besoin d'inclure le fichier d'entête pour compiler le fichier
#include "integer.h"

// ceci est un exemple de cours
// dans un vrai code, cette fonction devrait être
// inline dans le .h

// cette méthode ne doit PAS être qualifiée inline dans ce .cpp
// les .cpp ne sont PAS inclus
// donc pas de possibilité d'indiquer le corps de la fonction aux fichiers l'appelant... 
int Integer::get()
{
    return value;
}

// en fait une fonction déclarée inline dans un .cpp est locale au fichier
// ça peut être utile mais pas pour Integer::get