#include <iostream>
#include "automate.h"
#include "../Symbole/expression.h"

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
    pileEtats.top()->transition(*this, s);
}

void Automate::lecture() {
    pileEtats.push(new E0);

    while(!pileEtats.top()->transition(*this, lexer->Consulter())) { }

    Expression *e = (Expression *)pileSymboles.top();
    cout << e->eval() << endl;
}


void Automate::print() {
    cout << "Etats: ";
    while (!pileEtats.empty()) {
        cout << *pileEtats.top() << " ";
        pileEtats.pop();
    }

    cout << endl << "Symboles: ";
    while (!pileSymboles.empty()) {
        cout << *pileSymboles.top() << " ";
        pileSymboles.pop();
    }

    cout << endl;
}
