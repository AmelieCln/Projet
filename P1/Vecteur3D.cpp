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
    std::string stri() const {
      return std::to_string(vecteur[0]) + " " + std::to_string(vecteur[1]) + " " + std::to_string(vecteur[2]);
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
  
// test de l'addition, on a cree la methode stri pour tranformer l'affichage du vecteur en string
  std::cout << "( " << vect1.stri() << " )" << " + " <<
               "( " << vect2.stri() << " ) = " <<
               "( " << vect1.addition(vect2).stri() << " ) " << std::endl;
  std::cout << "( " << vect2.addition(vect1).stri() << " ) " << std::endl;

// test de l'addition du vecteur nul

  Vecteur3D vectnul;
  vectnul.set_coord(0,0);
  vectnul.set_coord(1,0);
  vectnul.set_coord(2,0);
  
  std::cout << "( " << vect1.stri() << " )" << " + " <<
               "( " << vectnul.stri() << " ) = " <<
               "( " << vect1.addition(vectnul).stri() << " ) " << std::endl;
  std::cout << "( " << vectnul.addition(vect1).stri() << " ) " << std::endl;
  
// test de la soustraction :
  std::cout << "( " << vect1.stri() << " )" << " - " <<
               "( " << vect2.stri() << " ) = " <<
               "( " << vect1.soustraction(vect2).stri() << " ) " << std::endl;
  std::cout << "( " << vect2.soustraction(vect1).stri() << " ) " << std::endl;

// test de soustraction d'un vecteur à lui même :
  std::cout << "( " << vect1.stri() << " )" << " - " <<
               "( " << vect1.stri() << " ) = " <<
               "( " << vect1.soustraction(vect1).stri() << " ) " << std::endl;

// test addition oppose = soustraction:
  std::cout << "addition opposé: " << std::endl;
  std::cout << "( " << vect1.stri() << " )" << " + " <<
               "( " << vect2.oppose().stri() << " ) = " <<
               "( " << vect1.addition(vect2.oppose()).stri() << " ) " << std::endl;
  std::cout<< "soustraction: " << std::endl;
  std::cout << "( " << vect1.stri() << " )" << " - " <<
               "( " << vect2.stri() << " ) = " <<
               "( " << vect1.soustraction(vect2).stri() << " ) " << std::endl;

  std::cout << "3 * (" << vect1.stri() << " = ()" << (vect1.mult(3.0)).stri() << ")" << std::endl;

  std::cout << "(" << vect1.stri() << ") * (" << vect2.stri() << ") = " << vect1.prod_scal(vect2) << std::endl;
  std::cout << "(" << vect2.stri() << ") * (" << vect1.stri() << ") = " << vect2.prod_scal(vect1) << std::endl;

  std::cout << "(" << vect1.stri() << ") ^ (" << vect2.stri() << ") = (" << (vect1.prod_vect(vect2)).stri() << ")" << std::endl;

  std::cout << "||" << vect1.stri() << "||^2 = " << vect1.norme2() << std::endl;

  std::cout << "||" << vect1.stri() << "|| = " << vect1.norme() << std::endl;

  std::cout << "||" << vect2.stri() << "||^2 = " << vect2.norme2() << std::endl;

  std::cout << "||" << vect2.stri() << "|| = " << vect2.norme() << std::endl;
  return 0;
};
