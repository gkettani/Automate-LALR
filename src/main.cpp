#include <iostream>
#include "Lexer/lexer.h"
#include "Automate/automate.h"


void test() {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      cout<<*s;
      cout<<endl;
      l.Avancer();
   }
}  


int main(void) {

   Automate a(new Lexer("(1+34)*123"));
   a.lecture();
   
   return 0;
}

