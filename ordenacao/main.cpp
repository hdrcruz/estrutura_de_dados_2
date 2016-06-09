#include "sort.hpp"

int main(int argc, char **argv){



   Sort ordenador;


   int i;
   cout << "Vetor desordenado:" << endl;

   for(i = 0; i < 10; i++){
     cout << ordenador.getElementAt(i) << endl;
   }

   cout << "Vetor Ordenado: " << endl;

   ordenador.quickSortAlt(0,9);

   cout << "Vetor Ordenado: " << endl;


   for(i = 0; i < 10; i++){
     std::cout << ordenador.getElementAt(i) << std::endl;
   }
   return 0;
}
