#include <string>
#include <iostream>

using namespace std;


class Pessoa
{

	protected:
		string nome;
		int idade;


	private:
		Pessoa *filho_esquerda;
		Pessoa *filho_direita;


	public:
		Pessoa()
		{
			nome = "";
			idade = 0;
			filho_esquerda == NULL;
			filho_direita == NULL;
		};


		Pessoa(string nm, int ida)
		{
			nome = nm;
			idade = ida;
			filho_esquerda = NULL;
			filho_direita = NULL;
		};

		~Pessoa()
		{
			cout << "Deletando instancia de Pessoa " << this->nome << endl;
		};

		string getNome()
		{
			return nome;
		};

		void setNome(string nm)
		{
			nome = nm;
		};


		int getIdade()
		{
			return idade;
		};

		void setIdade(int valor)
		{
			idade = valor;
		};

		void setFilhoEsquerda(Pessoa *pessoa){
			this->filho_esquerda = pessoa;
		};

		void setFilhoDireita(Pessoa *pessoa){
			this->filho_direita = pessoa;
		};

		Pessoa* getFilhoEsquerda(){
			return this->filho_esquerda;
		};

		Pessoa* getFilhoDireita(){
			return this->filho_direita;
		};

		int inserirFilho(Pessoa *filho) {
			if (filho->getIdade() < this->getIdade()) {
				if(this->filho_esquerda==NULL){
					this->filho_esquerda = filho;
					return 1;
				}
				else{
					this->filho_esquerda->inserirFilho(filho);
				}
			}
			else{
				if (this->filho_direita==NULL) {
					this->filho_direita = filho;
					return 1;
				}
				else {
					this->filho_direita->inserirFilho(filho);
				}
			}
		};

		int listarPre(){
			cout << this->getNome() << endl;
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) {
					this->filho_esquerda->listarPre();
				}
				if (this->filho_direita != NULL) {
					this->filho_direita->listarPre();
				}

			}
		};


		int apagar(){
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				delete this;
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) {
					this->filho_esquerda->apagar();
				}
				if (this->filho_direita != NULL) {
					this->filho_direita->apagar();
				}
				delete this;
			}

		}



};
