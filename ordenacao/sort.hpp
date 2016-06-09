#include <string>
#include <iostream>

#define size 10

using namespace std;

class Sort{

  protected:

    int vetor[size];


  public:



    Sort(): vetor {7, 9, 4, 3, 6, 1, 18, 2, 10, 5}{
    }

    int getElementAt(int index){
      return vetor[index];
    }

    void mergeSort(){

    }

    void quickSort(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      esquerda = inicio;
      direita = fim;

      meio = (int) ((esquerda + direita) / 2);
      pivo = vetor[meio];

      do{
        while (vetor[esquerda] < pivo) esquerda++;
        while (vetor[direita] > pivo) direita--;

        if(esquerda <= direita){
           aux = vetor[esquerda];
           vetor[esquerda] = vetor[direita];
           vetor[direita] = aux;
           esquerda++;
           direita--;
        }
      }while(direita > esquerda);

      if(inicio < direita) quickSort(inicio, direita);
      if(esquerda < fim) quickSort(esquerda, fim);
    }

    void quickSortAlt(int inicio, int fim){
      int pivo, aux, esquerda, direita, meio;

      pivo = vetor[inicio];
      esquerda = pivo+1;
      direita = fim;

      while (esquerda <= direita) {
        if (vetor[esquerda] <= pivo) esquerda++;
        else if (vetor[direita] > pivo) direita--;
        else{
          aux = vetor[esquerda];
          vetor[esquerda] = vetor[direita];
          vetor[direita] = aux;
        }
      }

        if (inicio < direita) quickSortAlt(inicio,);
        if (esquerda < fim) quickSortAlt(,fim);

    }















};
