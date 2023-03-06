#include <iostream>
#include "Lexer/lexer.h"
#include "Automate/automate.h"


void test() {
   string chaine("(123+34)");

   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      cout<<*s;
      cout<<endl;
      l.Avancer();
   }
}  


int main(void) {

   Automate a(new Lexer("(1+24)+(123*2)+58*2"));
   a.lecture();
   a.print();
   
   return 0;
}

