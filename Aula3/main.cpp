#include "Pessoa.hpp"
//#include "PessoaFisica.hpp"
//#include "PessoaJuridica.hpp"

int main(int argc, char **argv){
  bool continuar = true;
  int idade;
  string nome;
  int i = 0;
  int j = 0;

  string lista_removidas[5][2];
  int quantidade_removida;

  Pessoa *raiz = NULL;
  Pessoa pessoa_removida;

  for (i = 0; i < 1; i++) {
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
  if (raiz!= NULL) raiz->listarOrdem();


  quantidade_removida = 0;
  for (i = 0; i < 1; i++) {
    cout << endl << endl << "Inserir Idade para REMOVER: " << endl;
    cin >> idade;
    pessoa_removida = raiz->removerValor(idade, &raiz);
    if (pessoa_removida.getIdade() != -1) {
      lista_removidas[i][0] = pessoa_removida.getNome();
      lista_removidas[i][1] = to_string(pessoa_removida.getIdade());
      j++;
      quantidade_removida++;
    }
  }

  if (raiz != NULL) raiz->listarOrdem();
  else cout << "Arvore VAZIA!" << endl;


  for (i = 0; i < quantidade_removida; i++) {
    cout << endl << endl << "Pessoa Removida: " << i << endl;
    cout << "Nome: " << lista_removidas[i][0] << endl;
    cout << "Idade: " << lista_removidas[i][1] << endl;
  }



  cout << endl << endl << "Apagando Arvore geral!" << endl;
  if (raiz != NULL) raiz->apagarArvore();

return 0;
}
