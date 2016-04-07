#include "Pessoa.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

int main(int argc, char **argv){
  bool continuar = true;
  int idade;
  string nome;
  int i;

  Pessoa *raiz = NULL;

  //Pessoa *p1 = new Pessoa("Pessoa1",20);
  //Pessoa *p2 = new Pessoa("Pessoa2",10);
  //Pessoa *lista_pessoas;
  //lista_pessoas = new Pessoa[5];

  for (i = 0; i < 5; i++) {
    cout << "Inserir Nome: " << endl;
    cin >> nome;
    cout << "Inserir Idade: " << endl;
    cin >> idade;
    //lista_pessoas[i].setNome(nome);
    //lista_pessoas[i].setIdade(idade);
    Pessoa *pessoa = new Pessoa(nome, idade);
    if (raiz == NULL) {
      raiz = pessoa;
    }
    else{
      raiz->inserirFilho(pessoa);
    }
  }

  raiz->listarPre();

  raiz->apagar();






  //raiz = p1;
  //cout << "Inseriu esquerda " << p1->inserirFilho(p2) << endl;
  //cout << "Filho esquerdo: " << raiz->getFilhoEsquerda()->getNome() << endl;
  // cout << "Filho esquerdo: " << raiz->getFilhoEsquerda() << endl;
  // cout << "Filho esquerdo: " << raiz->getFilhoDireita() << endl;



  //delete p1;
  //delete p2;
  //delete [] lista_pessoas;
  //delete raiz;
return 0;
}
