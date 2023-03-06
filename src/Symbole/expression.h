#pragma once

#include "symbole.h"
using namespace std;


class Expression : public Symbole {
    
    public:
        Expression() : Symbole(EXPR) { }
        virtual int eval() = 0;
        virtual ~Expression() { }
};

class ExpressionCst : public Expression {
    
    public:
        ExpressionCst(int v) : Expression(), valeur(v) { }
        virtual ~ExpressionCst() { }
        
        int eval();

        // ostream& Print(ostream& os) const { return Symbole::Print(os) << ":" << valeur; }    

    protected:
        int valeur;
};

class ExpressionBinaire : public Expression {
    
    public:
        ExpressionBinaire(Expression * e1, Expression * e2) : Expression(), exprGauche(e1), exprDroite(e2) { }
        virtual int eval() = 0;
        virtual ~ExpressionBinaire() { }

        // ostream& Print(ostream& os) const { return Symbole::Print(os) << ":" << exprGauche << exprDroite; }
        
    protected:
        Expression * exprGauche;
        Expression * exprDroite;
};

class ExpressionPlus : public ExpressionBinaire {
    
    public:
        ExpressionPlus(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~ExpressionPlus() { }
        int eval();
};

class ExpressionMult : public ExpressionBinaire {
    
    public:
        ExpressionMult(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~ExpressionMult() { }
        int eval();
};
