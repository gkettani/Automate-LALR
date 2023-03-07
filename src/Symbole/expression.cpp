#include "expression.h"

int ExpressionPlus::eval() {
    return exprGauche->eval() + exprDroite->eval();
}

int ExpressionMult::eval() {
    return exprGauche->eval() * exprDroite->eval();
}

int ExpressionCst::eval() {
    return valeur;
}
