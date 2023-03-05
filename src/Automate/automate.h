#pragma once

#include "../Lexer/lexer.h"
#include "../Etat/etat.h"
#include <stack>
using namespace std;

class Automate {
    
    public:
        Automate(Lexer * l) : lexer(l), symboleCourant(l->Consulter()) { }
        ~Automate() { }
        
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);

    protected:
        Lexer * lexer;
        Symbole * symboleCourant;
        stack<Etat *> pileEtats;
        stack<Symbole *> pileSymboles;
};
