#include <iostream>
#include <cmath>
#include "Vecteur3D.h"

void Vecteur3D::set_coord(size_t pos_coo, double coo){
      if (pos_coo>2) std::cerr << "out of bound"<< std::endl;
      else vecteur[pos_coo] = coo;
    }

void Vecteur3D::affiche() const {
      std:: cout << vecteur[0] << " "<< vecteur[1]<< " "<< vecteur[2]<< std::endl;
    }

std::string Vecteur3D::stri() const {
      return std::to_string(vecteur[0]) + " " + std::to_string(vecteur[1]) + " " + std::to_string(vecteur[2]);
    }

bool Vecteur3D::compare(Vecteur3D const& autre, double precision) const {
      return  std::abs(autre.vecteur[0] - vecteur[0])< precision 
          and std::abs(autre.vecteur[1] - vecteur[1])< precision
          and std::abs(autre.vecteur[2] - vecteur[2])< precision;
    }

Vecteur3D Vecteur3D::addition(Vecteur3D const& autre) const{
      Vecteur3D v;
      for (size_t i(0); i<3; ++i)
        v.vecteur[i]= autre.vecteur[i] + vecteur[i];
      return v;        
    }

Vecteur3D Vecteur3D::oppose() const{
      return mult(-1);
    }

Vecteur3D Vecteur3D::soustraction(Vecteur3D const& autre) const{
      return addition(autre.oppose());
    }

Vecteur3D Vecteur3D::mult(double scale) const{
      Vecteur3D v;
      for (size_t i(0); i<3; ++i)
        v.vecteur[i]= scale * vecteur[i];
      return v;
    }

double Vecteur3D::prod_scal(Vecteur3D const& autre) const {
      double x(0);
      for (size_t i(0); i<3; ++i)
        x += autre.vecteur[i] * vecteur[i];
      return x;
    }

Vecteur3D Vecteur3D::prod_vect(Vecteur3D const& autre) const {
      Vecteur3D v;
      for (std::size_t i(0); i<3; ++i)
        v.vecteur[i]= vecteur[(i+1)%3]*autre.vecteur[(i+2)%3] - vecteur[(i+2)%3]*autre.vecteur[(i+1)%3];
      return v;
    }

double Vecteur3D::norme2() const{
      return prod_scal(*this);
    }

double Vecteur3D::norme() const {
      return sqrt(norme2());
    }

Vecteur3D Vecteur3D::unitaire() const{
      return (norme()< 1e-10) ? *this : mult(1/norme());   
    }