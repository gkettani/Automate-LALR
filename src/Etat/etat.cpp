#include <iostream>
#include "etat.h"
#include "../Symbole/symbole.h"
#include "../Automate/automate.h"
#include "../Symbole/expression.h"

using namespace std;

void Etat::print() const {
    cout << name << endl;
}

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
            break;
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
            break;
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
            break;
    }
    return false;
}

/**
 * Reduction de E -> val
 * - dépile le symbole de la stack
 * - Créer le symbole non terminal ExpressionCst
 * - Appeler la fonction de réduction
 */
bool E3::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS: {                
            int v = ((Entier *) a.pileSymboles.top())->getValeur();
            a.pileSymboles.pop();
            a.reduction(1, new ExpressionCst(v));
            break;
        }
        case MULT:
            // r5
            break;
        case CLOSEPAR: {
            int v = ((Entier *) a.pileSymboles.top())->getValeur();
            a.pileSymboles.pop();
            a.reduction(1, new ExpressionCst(v));
            break;
        }
        case FIN:
            // r5
            break;
        default:
            // gestion erreur
            break;
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
            break;
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
            break;
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
            break;
    }
    return false;
}


/**
 * Reduction de E -> E + E
 * - Dépile le symbole du top : un chiffre
 * - Dépile le plus
 * - Dépile le second nombre
 * - crée ExpressionPlus
 * - Appel de la fonction de reduction
 */
bool E7::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS:
            // r2
            break;
        case MULT:
            a.decalage(s, new E5);
            break;
        case CLOSEPAR: {
            int v1 = ((Entier *) a.pileSymboles.top())->getValeur();
            a.pileSymboles.pop();
            a.pileSymboles.pop();
            int v2 = ((Entier *) a.pileSymboles.top())->getValeur();
            a.pileSymboles.pop();
            a.reduction(3, new ExpressionPlus(new ExpressionCst(v1), new ExpressionCst(v2)));
            break;
        }
        case FIN:
            // r2
            break;
        default:
            // gestion erreur
            break;
    }
    return false;
}

/**
 * Reduction E -> E*E
 * - Dépile le premier nombre en top de stack
 * - Dépile le *
 * - Dépile le second nombre en top de stack
 * - Crée ExpressionMult
 * - Appel de la fonction de reduction
 */
bool E8::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS:
            // r3
            break;
        case MULT:
            // r3
            break;
        case CLOSEPAR:
            // r3
            break;
        case FIN:
            // r3
            break;
        default:
            // gestion erreur
            break;
    }
    return false;
}

/**
 * Réduction E -> ( E )
 * - Dépile le symbole du top : CLOSEPAR
 * - Récupère un pointeur vers E
 * - Dépile E
 * - Dépile le symbole suivant en top : OPENPAR
 * - Appel de la fonction de réduction en passant le pointeur de E
 */
bool E9::transition(Automate &a, Symbole * s) {
    switch (*s) {
        case PLUS:
            // r4
            break;
        case MULT:
            // r4
            break;
        case CLOSEPAR:
            // r4
            break;
        case FIN:
            // r4
            break;
        default:
            // gestion erreur
            break;
    }
    return false;
}
