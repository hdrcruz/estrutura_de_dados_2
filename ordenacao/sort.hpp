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

    void SelectionSort(int number_of_elements)
    {
      int iter,jter,minIndex,temp;
      for(iter = 0;iter<number_of_elements;iter++)
      {
        minIndex = iter;
        for(jter = iter+1; jter<number_of_elements;jter++)
        {
          if(array[jter] < array[minIndex]) minIndex = jter;
        }
          temp = array[iter];
          array[iter] = array[minIndex];
          array[minIndex] = temp;
      }
    }

    void ShellSort(int *array, int number_of_elements)
    {
      int iter, jter, increment, temp;
      for(increment = number_of_elements/2;increment > 0; increment /= 2)
      {
        for(i = increment; i<number_of_elements; i++)
        {
          temp = array[i];
          for(j = i; j >= increment ;j-=increment)
          {
            if(temp < array[j-increment])
            {
              array[j] = array[j-increment];
            }
            else
            {
              break;
            }
          }
          array[j] = temp;
        }
      }
    }



};
