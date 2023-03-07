#pragma once
#include <array>

class Vecteur3D {
  private:
    std::array<double, 3> vecteur;
  
  public :
    void set_coord(size_t pos_coo, double coo);
    void affiche() const;
    std::string stri() const;
    bool compare(Vecteur3D const& autre, double precision = 1e-10) const;
    Vecteur3D addition(Vecteur3D const& autre) const;
    Vecteur3D oppose() const;
    Vecteur3D soustraction(Vecteur3D const& autre) const;
    Vecteur3D mult(double scale) const;
    double prod_scal(Vecteur3D const& autre) const; 
    Vecteur3D prod_vect(Vecteur3D const& autre) const;
    double norme2() const;
    double norme() const;
    Vecteur3D unitaire() const;
};