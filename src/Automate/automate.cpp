#include <iostream>
#include "automate.h"

void Automate::decalage(Symbole * s, Etat * e) {
    pileEtats.push(e);
    pileSymboles.push(s);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        pileEtats.pop();
    }  
    // pileSymboles.push(s);
    pileEtats.top()->transition(*this, s);
}

void Automate::lecture() {
    pileEtats.push(new E0);

    pileEtats.top()->transition(*this, lexer->Consulter());

    pileEtats.top()->transition(*this, lexer->Consulter());

    pileEtats.top()->transition(*this, lexer->Consulter());
}

