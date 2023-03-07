CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++17  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
# CXXFLAGS += -g                  # pour debugger
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all:: TestVecteur3D

Vecteur3D.o: Vecteur3D.cpp Vecteur3D.h

TestVecteur3D.o: TestVecteur3D.cpp Vecteur3D.h

TestVecteur3D: TestVecteur3D.o Vecteur3D.o