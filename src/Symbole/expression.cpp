#include "expression.h"
#include <iostream>


int ExpressionPlus::eval() {
    return exprGauche->eval() + exprDroite->eval();
}

int ExpressionMult::eval() {
    return exprGauche->eval() * exprDroite->eval();
}

int ExpressionCst::eval() {
    return valeur;
}

void ExpressionCst::print() {
    cout << valeur;
}

void ExpressionPlus::print() {
    cout << "(";
    exprGauche->print();
    cout << " + ";
    exprDroite->print();
    cout << ")";
}

void ExpressionMult::print() {
    cout << "(";
    exprGauche->print();
    cout << " * ";
    exprDroite->print();
    cout << ")";
}
