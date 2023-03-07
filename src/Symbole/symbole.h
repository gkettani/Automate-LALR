#pragma once

#include <string>
#include <iostream>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      
      bool isTerminal() const { return ident<EXPR; }
      virtual ostream& Print(ostream& os) const { return os << Etiquettes[ident]; }

      // Surchage d'operateur --------------------------------
      operator int() const { return ident; }
      friend ostream & operator <<(ostream &os, const Symbole &s) { return s.Print(os); } 

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      
      int getValeur() const { return valeur; }
      ostream& Print(ostream& os) const { return os << Etiquettes[ident] << "(" << valeur << ")"; }

   protected:
      int valeur;
};
