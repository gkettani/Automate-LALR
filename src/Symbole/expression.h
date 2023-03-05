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
        ExpressionCst(int v) : Expression() { }
        virtual ~ExpressionCst() { }
        virtual void Affiche();

    protected:
        int valeur;
};

class ExpressionBinaire : public Expression {
    
    public:
        ExpressionBinaire(Expression * e1, Expression * e2) : Expression(), exprGauche(e1), exprDroite(e2) { }
        virtual int eval() = 0;
        virtual ~ExpressionBinaire() { }
        
    protected:
        Expression * exprGauche;
        Expression * exprDroite;
};

class Plus : public ExpressionBinaire {
    
    public:
        Plus(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~Plus() { }
        virtual void Affiche();
        virtual int eval();
};

class Mult : public ExpressionBinaire {
    
    public:
        Mult(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~Mult() { }
        virtual void Affiche();
        virtual int eval();
};
