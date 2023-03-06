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

        ostream& Print(ostream& os) const { 
            Symbole::Print(os);
            cout << " -> " << valeur;
            return  os; 
        }    

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

class ExpressionPlus : public ExpressionBinaire {
    
    public:
        ExpressionPlus(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~ExpressionPlus() { }
        int eval();

        ostream& Print(ostream& os) const { 
            Symbole::Print(os);
            cout << " -> " << *exprGauche << " + " << *exprDroite;
            return  os;
        }

};

class ExpressionMult : public ExpressionBinaire {
    
    public:
        ExpressionMult(Expression * e1, Expression * e2) : ExpressionBinaire(e1, e2) { }
        ~ExpressionMult() { }
        int eval();

        ostream& Print(ostream& os) const { 
            Symbole::Print(os);
            cout << " -> " << *exprGauche << " * " << *exprDroite;
            return  os;
        }
};
