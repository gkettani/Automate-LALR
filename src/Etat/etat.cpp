#include "etat.h"
#include "../Symbole/symbole.h"
#include "../Automate/automate.h"
#include "../Symbole/expression.h"

bool E0::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case INT:
            a.decalage(s, new E3);
            break;
        case OPENPAR:
            a.decalage(s, new E2);
            break;
        case EXPR:
            a.decalage(s, new E1);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E1::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS:
            a.decalage(s, new E4);
            break;
        case MULT:
            a.decalage(s, new E5);
            break;
        case FIN:
            return true;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E2::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case INT:
            a.decalage(s, new E3);
            break;
        case OPENPAR:
            a.decalage(s, new E2);
            break;
        case EXPR:
            a.decalage(s, new E6);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E3::transition(Automate &a, Symbole * s) {
    Entier *e;

    switch (*s) {
        case PLUS:                
            e = (Entier *)a.popSymbol();
            a.reduction(1, new ExpressionCst(e->getValeur()));
            delete e;
            break;
        case MULT:
            e = (Entier *)a.popSymbol();
            a.reduction(1, new ExpressionCst(e->getValeur()));
            delete e;
            break;
        case CLOSEPAR:
            e = (Entier *)a.popSymbol();
            a.reduction(1, new ExpressionCst(e->getValeur()));
            delete e;
            break;
        case FIN:
            e = (Entier *)a.popSymbol();
            a.reduction(1, new ExpressionCst(e->getValeur()));
            delete e;
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E4::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case INT:
            a.decalage(s, new E3);
            break;
        case OPENPAR:
            a.decalage(s, new E2);
            break;
        case EXPR:
            a.decalage(s, new E7);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E5::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case INT:
            a.decalage(s, new E3);
            break;
        case OPENPAR:
            a.decalage(s, new E2);
            break;
        case EXPR:
            a.decalage(s, new E8);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E6::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS:
            a.decalage(s, new E4);
            break;
        case MULT:
            a.decalage(s, new E5);
            break;
        case CLOSEPAR:
            a.decalage(s, new E9);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E7::transition(Automate &a, Symbole * s) {
    Expression * e1;
    Expression * e2;

    switch (*s) {
        case PLUS:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionPlus(e1, e2));
            break;
        case MULT:
            a.decalage(s, new E5);
            break;
        case CLOSEPAR:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionPlus(e1, e2));
            break;
        case FIN:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionPlus(e1, e2));
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E8::transition(Automate &a, Symbole * s) {
    Expression * e1;
    Expression * e2;

    switch (*s) {
        case PLUS:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionMult(e1, e2));
            break;
        case MULT:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionMult(e1, e2));
            break;
        case CLOSEPAR:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionMult(e1, e2));
            break;
        case FIN:
            e1 = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            e2 = (Expression *)a.popSymbol();
            a.reduction(3, new ExpressionMult(e1, e2));
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}

bool E9::transition(Automate &a, Symbole * s) {
    Expression * e;

    switch (*s) {
        case PLUS:
            a.popAndDestroySymbol();
            e = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3, e);
            break;
        case MULT:
            a.popAndDestroySymbol();
            e = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3, e);
            break;
        case FIN:
            a.popAndDestroySymbol();
            e = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3, e);
            break;
        case CLOSEPAR:
            a.popAndDestroySymbol();
            e = (Expression *)a.popSymbol();
            a.popAndDestroySymbol();
            a.reduction(3, e);
            break;
        default:
            // gestion erreur
            return true;
    }
    return false;
}
