#include <iostream>
#include "automate.h"
#include "../Symbole/expression.h"

void Automate::decalage(Symbole * s, Etat * e) {
    pileEtats.push_back(e);
    pileSymboles.push_back(s);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        delete pileEtats.back();
        pileEtats.pop_back();
    }  
    pileEtats.back()->transition(*this, s);
}

int Automate::lecture() {
    pileEtats.push_back(new E0);

    while(!pileEtats.back()->transition(*this, lexer->Consulter())) { }

    if (pileSymboles.empty()) {
        return -1;
    }
    
    Expression *e = (Expression *)pileSymboles.back();
    if (e->isTerminal() || pileSymboles.size() > 1) {
        return -1;
    }
    return e->eval();
}

Symbole * Automate::popSymbol() {
    Symbole *e = pileSymboles.back();
    pileSymboles.pop_back();
    return e;
}

void Automate::popAndDestroySymbol() {
    delete pileSymboles.back();
    pileSymboles.pop_back();
}

void Automate::print() {
    cout << "Pile d'états : " << endl;
    for (long unsigned int i = 0; i < pileEtats.size(); i++) {
        cout << "Etat " << i << " : " << *pileEtats[i] << endl;
    }
    cout << "Pile de symboles : " << endl;
    for (long unsigned int i = 0; i < pileSymboles.size(); i++) {
        cout << "Symbole " << i << " : " << *pileSymboles[i] << endl;
    }
}

Automate::~Automate() {
    for (auto e : pileEtats) {
        delete e;
    }
    for (auto s : pileSymboles) {
        delete s;
    }

    delete lexer;
}
