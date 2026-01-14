# Voici un petit Makefile de base
# définition du compilateur
CPP=g++
# définition de la manière de supprimer les fichiers
RM=rm -f

# définition des flags de compilation
# -g pour debug - commenter cette ligne pour créer un exécutable sans debug
CFLAGS=-g

# vous mettez ici, la liste de tous vos fichiers d'implémentation
# i.e. tous les .cpp
SRC = integer.cpp main.cpp foobar.cpp

# cette règle fabrique la liste de tous les fichiers de code objet (les .o)
# i.e. ceux qu'on doit linker ensemble pour faire un exécutable
OBJ = $(SRC:.cpp=.o)

# là c'est la règle qui linke tous les fichiers .o ensemble
# le nom de l'exécutable sera integer

# une règle: comporte:
#   - à droite du : les dépendances (potentiellement vide)
#   - à gauche le nom de la règle à faire
# après chaque TABULATION pas des espaces !!
#   on a les commandes à exécuter

# Pour faire complètement l'exécutable integer on fera
# $ make integer
# qui:
# 1) regardera si un des .o définis dans la variable OBJ
#    a été modifié depuis la dernière édition de lien
#  si oui: a) on recompile le .cpp correspondant
#             (les dépendances sont respectées)
#          b) on refait le link ici ça fait
#             $(CPP)  $^                        -o $@
#             g++     integer.o main.o foobar.o -o integer
#  si non: on ne fait rien tout est déjà fait... 
integer  : $(OBJ)
	$(CPP) $^ -o $@

# si, dans un premier temps
# on ne veut pas maintenir les dépendances à jour proprement
# (sachant que si elles ne sont pas maintenues du tout le code va mal compiler...)
# on peut faire dépendre tous les fichiers d'implémentation
# de tous les header files *.h (voir règle %.o : %.cpp *.h)
# c'est moche c'est brute-force mais ça dépanne 
# vous écrirez vos dépendances correctement
# par exemple integer.cpp ne dépend PAS de foobar.h ...

# %.o%.cpp signifie pour passer d'un truc.cpp à un truc.o i.e. pour compiler
# *.h signifie on le fait dès qu'un des fichiers .h a été modifié (brute force)
#           $(CPP) $(CFLAGS) -o $@ -c $<
# donne sur integer.cpp
#           g++    -g        -o integer.o -c integer.cpp
#    remarquez le -o integer.o (i.e. mettre l'output de g++ -c integer.cpp dans le fichier integer.o)
%.o:%.cpp *.h
	$(CPP) $(CFLAGS) -o $@ -c $<

# et la règle pour tout bien nettoyer
# clean ne dépend de rien
# on détruit tous les fichiers .o et l'exécutable
# utile quand on a des erreurs dans les dépendances et que le link a fait n'importe quoi...
clean:
	$(RM) *.o integer

# laissez cette règle (elle permet d'appliquer la règle clean
#    quand il existe un fichier clean dans le répertoire...)
.PHONY: clean
