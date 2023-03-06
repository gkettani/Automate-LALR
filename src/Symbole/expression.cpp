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
