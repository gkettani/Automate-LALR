#pragma once

#include "../Symbole/symbole.h"
using namespace std;

class Automate;

class Etat {

    public:
        Etat() { }
        virtual ~Etat() { }
        void print() const;
        virtual bool transition(Automate &a, Symbole * s) = 0;

    protected:
        
};

class E0 : public Etat {

    public:
        E0() { }
        virtual ~E0() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E1 : public Etat {

    public:
        E1() { }
        virtual ~E1() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E2 : public Etat {

    public:
        E2() { }
        virtual ~E2() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E3 : public Etat {

    public:
        E3() { }
        virtual ~E3() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E4 : public Etat {

    public:
        E4() { }
        virtual ~E4() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E5 : public Etat {

    public:
        E5() { }
        virtual ~E5() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E6 : public Etat {

    public:
        E6() { }
        virtual ~E6() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E7 : public Etat {

    public:
        E7() { }
        virtual ~E7() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E8 : public Etat {

    public:
        E8() { }
        virtual ~E8() { }
        virtual bool transition(Automate &a, Symbole * s);
};

class E9 : public Etat {

    public:
        E9() { }
        virtual ~E9() { }
        virtual bool transition(Automate &a, Symbole * s);
};
