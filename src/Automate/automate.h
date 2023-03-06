#pragma once

#include <stack>
#include "../Lexer/lexer.h"
#include "../Etat/etat.h"
using namespace std;

class Automate {
    
    public:
        Automate(Lexer * l) : lexer(l) { }
        ~Automate() { }
        
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void lecture();
        void print();

    // protected:
        Lexer * lexer;
        stack<Etat *> pileEtats;
        stack<Symbole *> pileSymboles;
};
