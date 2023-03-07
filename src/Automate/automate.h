#pragma once

#include <deque>
#include "../Lexer/lexer.h"
#include "../Etat/etat.h"
using namespace std;

class Automate {
    
    public:
        Automate() { }
        Automate(Lexer * l) : lexer(l) { }
        ~Automate();
        
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        int lecture();
        void print();
        Symbole * popSymbol();
        void popAndDestroySymbol();

    protected:
        Lexer * lexer;
        deque<Etat *> pileEtats;
        deque<Symbole *> pileSymboles;
};
