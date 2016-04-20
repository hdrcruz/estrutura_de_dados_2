#include "Pessoa.hpp"
//#include "PessoaFisica.hpp"
//#include "PessoaJuridica.hpp"

int main(int argc, char **argv){
  bool continuar = true;
  int idade;
  string nome;
  int i;

  Pessoa *raiz = NULL;

  for (i = 0; i < 8; i++) {
    cout << endl << "Inserir Nome: " << endl;
    cin >> nome;
    cout << "Inserir Idade: " << endl;
    cin >> idade;
    Pessoa *pessoa = new Pessoa(nome, idade);
    if (raiz == NULL) {
      raiz = pessoa;
    }
    else{
      raiz->inserirFilho(pessoa);
    }
  }

  cout << endl << endl << "Arvore antes da exclusão!" << endl;
  raiz->listarPre();

  cout << endl << endl << "Inserir Idade para buscar: " << endl;
  cin >> idade;

  //cout << raiz->buscar(idade) << endl;

  raiz->removerValor(idade, &raiz);

  cout << endl << endl << "Arvore depois da exclusão!" << endl;
  raiz->listarPre();


  cout << endl << endl << "Apagando Arvore geral!" << endl;
  raiz->apagarArvore();

return 0;
}
