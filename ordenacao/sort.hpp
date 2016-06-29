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

    void mergeSort(int inicio, int fim){
      int meio = (inicio + fim)/2;
      if (inicio < fim){
        mergeSort(inicio, meio);
        mergeSort(meio+1, fim);
        merge(inicio, meio, fim);
      }
    }

    void merge(int inicio, int meio, int fim){
      int aux[fim - inicio + 1];
      int pos = 0;
      int pos_esquerda = inicio;
      int pos_direita = meio+1;

      while (pos_esquerda <= meio && pos_direita <= fim){
        if (vetor[pos_esquerda] < vetor[pos_direita])
        {
          aux[pos] = vetor[pos_esquerda];
          pos++;
          pos_esquerda++;
        }
        else
        {
          aux[pos] = vetor[pos_direita];
          pos++;
          pos_direita++;
        }
      }
      while (pos_esquerda <= meio){
        aux[pos] = vetor[pos_esquerda];
        pos++;
        pos_esquerda++;
      }
      while (pos_direita <= fim) {
        aux[pos] = vetor[pos_direita];
        pos++;
        pos_direita++;
      }
      int iter;
      for (iter = 0; iter < pos; iter++) {
        vetor[iter + inicio] = aux[iter];
      }
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

    void insertionSort(int elementos)
    {
      int iter,jter;
      for(iter=1;iter<elementos;iter++)
      {
        int elem_atual = vetor[iter];
        jter = iter-1;
        while(jter>=0 && vetor[jter] > elem_atual)
        {
          vetor[jter+1] = vetor[jter];
          jter--;
        }
        vetor[jter+1] = elem_atual;
      }
    }

    void SelectionSort(int elementos)
    {
      int iter,jter,minIndex,temp;
      for(iter = 0;iter<elementos;iter++)
      {
        minIndex = iter;
        for(jter = iter+1; jter<elementos;jter++)
        {
          if(vetor[jter] < vetor[minIndex]) minIndex = jter;
        }
          temp = vetor[iter];
          vetor[iter] = vetor[minIndex];
          vetor[minIndex] = temp;
      }
    }



};
