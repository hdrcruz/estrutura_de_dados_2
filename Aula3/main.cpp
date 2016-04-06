#include "Pessoa.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

int main(int argc, char **argv){

    string nome;
    int cpf;
    int cnpj;

    PessoaFisica fisica;
	cout << "Informe o nome:" << endl;
	cin >> nome;
	fisica.setNome(nome);

    cout << "Informe o cpf:" << endl;
	cin >> cpf;
	fisica.setCpf(cpf);

	cout << endl << "NOME: " << fisica.getNome() << endl;
	cout << "CPF: " << fisica.getCpf() << endl;

    PessoaJuridica juridica;
	cout << endl << "Informe o nome:" << endl;
	cin >> nome;
	juridica.setNome(nome);

    cout << "Informe o cnpj:" << endl;
	cin >> cnpj;
	juridica.setCpf(cnpj);

	cout << endl << "NOME: " << juridica.getNome() << endl;
	cout << "CNPJ: " << juridica.getCpf() << endl;


return 0;
}
