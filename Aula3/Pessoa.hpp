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
		Pessoa *pai;


	public:
		Pessoa()
		{
			nome = "";
			idade = 0;
			filho_esquerda = NULL;
			filho_direita = NULL;
			pai = NULL;
		};


		Pessoa(string nm, int ida)
		{
			nome = nm;
			idade = ida;
			filho_esquerda = NULL;
			filho_direita = NULL;
			pai = NULL;
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

		void setPai(Pessoa *pessoa){
			this->pai = pessoa;
		};

		Pessoa* getPai(){
			return this->pai;
		};

		Pessoa* getFilhoDireita(){
			return this->filho_direita;
		};

		Pessoa* getFilhoEsquerda(){
			return this->filho_esquerda;
		};

		int inserirFilho(Pessoa *filho) {
			if (filho->getIdade() < this->idade ){
				if(this->filho_esquerda==NULL){
					this->filho_esquerda = filho;
					filho->setPai(this);
					return 1;
				}
				else this->filho_esquerda->inserirFilho(filho);
			}
			else{
				if (this->filho_direita==NULL) {
					this->filho_direita = filho;
					filho->setPai(this);
					return 1;
				}
				else this->filho_direita->inserirFilho(filho);
			}
		};

		int listarPre(){
			cout << this->getNome() << endl;
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) this->filho_esquerda->listarPre();
				if (this->filho_direita != NULL) this->filho_direita->listarPre();
			}
		};


		int apagarArvore(){
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				delete this;
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) 	this->filho_esquerda->apagarArvore();
				if (this->filho_direita != NULL) this->filho_direita->apagarArvore();
				delete this;
			}
		}

		Pessoa* buscar(int valor){
			cout << "Nome Atual:" << this->nome << " Idade: " << this->idade << " Busca: " << valor << endl;
			if(this->idade == valor) return this;
			if ((this->idade < valor) && (this->filho_direita!=NULL))  return this->filho_direita->buscar(valor);
			if (this->filho_esquerda!=NULL)   return this->filho_esquerda->buscar(valor);
			return NULL;
		};

		int apagar(int valor){
			Pessoa *apagar = this->buscar(valor);
			if(apagar->getPai() == NULL){
				cout << "Apaga raiz implementar mais tarde!" << endl;
				return 1;
			}
			if (apagar->isFolha()) {
				if (apagar->pai->getFilhoDireita() == apagar) apagar->pai->setFilhoDireita(NULL);
				else apagar->pai->setFilhoEsquerda(NULL);
				delete apagar;
				return 0;
			}
			if (apagar->getFilhoDireita() != NULL){
				if (apagar->getFilhoDireita()->isFolha()){
					if (apagar->pai->getFilhoDireita() == apagar) apagar->pai->setFilhoDireita(apagar->getFilhoDireita());
					else apagar->pai->setFilhoEsquerda(apagar->getFilhoDireita());
					apagar->filho_direita->setPai(apagar->getPai());
					delete apagar;
					return 0;
				}
			}
			if (apagar->getFilhoEsquerda() != NULL){
				if (apagar->getFilhoEsquerda()->isFolha()){
					if (apagar->pai->getFilhoDireita() == apagar) apagar->pai->setFilhoDireita(apagar->getFilhoEsquerda());
					else apagar->pai->setFilhoEsquerda(apagar->getFilhoEsquerda());
					apagar->filho_esquerda->setPai(apagar->getPai());
					delete apagar;
					return 0;
				}
			}
			return 1;

		};

		bool isFolha(){
			return (this->getFilhoDireita() == NULL) && (this->getFilhoEsquerda()==NULL);
		};

		bool isFull(){
			return (this->getFilhoDireita() != NULL) && (this->getFilhoEsquerda()!=NULL);
		};





};
