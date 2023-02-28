#include <array>
#include <iostream>
#include <cmath>

class Vecteur3D {
  private:
    std::array<double, 3> vecteur;
  public :
    void set_coord(std::size_t pos_coo, double coo){
      if (pos_coo>2) std::cerr << "out of bound"<< std::endl;
      else vecteur[pos_coo] = coo;
    }
    void affiche() const {
      std:: cout << vecteur[0] << " "<< vecteur[1]<< " "<< vecteur[2]<< std::endl;
    }
    bool compare(Vecteur3D const& autre, double precision = 1e-10) const {
      return  std::abs(autre.vecteur[0] - vecteur[0])< precision 
          and std::abs(autre.vecteur[1] - vecteur[1])< precision
          and std::abs(autre.vecteur[2] - vecteur[2])< precision;
    }
    Vecteur3D addition(Vecteur3D const& autre) const{
      Vecteur3D v;
      for (std::size_t i(0); i<3; ++i)
        v.vecteur[i]= autre.vecteur[i] + vecteur[i];
      return v;        
    }
    Vecteur3D oppose() const{
      return mult(-1);
    }
    Vecteur3D soustraction(Vecteur3D const& autre) const{
      return addition(autre.oppose());
    }
    Vecteur3D mult(double scale) const{
      Vecteur3D v;
      for (std::size_t i(0); i<3; ++i)
        v.vecteur[i]= scale * vecteur[i];
      return v;
    }
    double prod_scal(Vecteur3D const& autre) const {
      double x(0);
      for (std::size_t i(0); i<3; ++i)
        x += autre.vecteur[i] * vecteur[i];
      return x;
    }

    Vecteur3D prod_vect(Vecteur3D const& autre) const {
      Vecteur3D v;
      for (std::size_t i(0); i<3; ++i)
        v.vecteur[i]= vecteur[(i+1)%3]*autre.vecteur[(i+2)%3] - vecteur[(i+2)%3]*autre.vecteur[(i+1)%3];
      return v;
    }
    double norme2() const{
      return prod_scal(*this);
    }
    double norme() const {
      return sqrt(norme2());
    }
    Vecteur3D unitaire() const{
      return (norme()< 1e-10) ? *this : mult(1/norme());   
    }
};


int main(){
  Vecteur3D vect1;
  Vecteur3D vect3;
  Vecteur3D vect2;

  /* Cette partie sera revue dans 2 semaines
  * (constructeurs, surcharge des opérateurs).
  */
  // v1 = (1.0, 2.0, -0.1)
  vect1.set_coord(0, 1.0);
  vect1.set_coord(1, 2.0);
  vect1.set_coord(2, -0.1);

  // v2 = (2.6, 3.5,  4.1)
  vect2.set_coord(0, 2.6);
  vect2.set_coord(1, 3.5);
  vect2.set_coord(2, 4.1); 

  vect3 = vect1;

  std::cout << "Vecteur 1 : ";
  vect1.affiche();
  std::cout << std::endl;

  std::cout << "Vecteur 2 : ";
  vect2.affiche();
  std::cout << std::endl;

  std::cout << "Le vecteur 1 est ";
  if (vect1.compare(vect2)) {
      std::cout << "égal au";
  } else {
      std::cout << "différent du";
  }
  std::cout << " vecteur 2," << std::endl << "et est ";
  if (not vect1.compare(vect3)) {
      std::cout << "différent du";
  } else {
      std::cout << "égal au";
  }
  std::cout << " vecteur 3." << std::endl;
  return 0;

  std::cout << "( " << 
}