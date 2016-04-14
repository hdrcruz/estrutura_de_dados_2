#include "Pessoa.hpp"
//#include "PessoaFisica.hpp"
//#include "PessoaJuridica.hpp"

int main(int argc, char **argv){
  bool continuar = true;
  int idade;
  string nome;
  int i;

  Pessoa *raiz = NULL;

  for (i = 0; i < 5; i++) {
    cout << "Inserir Nome: " << endl;
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

  cout << "Arvore antes da exclusão!" << endl;
  raiz->listarPre();

  cout << "Inserir Idade para buscar: " << endl;
  cin >> idade;

  //cout << raiz->buscar(idade) << endl;

  raiz->apagar(idade);

  cout << "Arvore depois da exclusão!" << endl;
  raiz->listarPre();


  cout << "Apagando Arvore geral!" << endl;
  raiz->apagarArvore();

return 0;
}
