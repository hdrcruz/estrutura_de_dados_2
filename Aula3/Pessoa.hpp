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
		    string pai, esquerda, direita = "Nada";
		    if (this->pai != NULL) pai = this->pai->nome;
		    if (this->filho_direita != NULL) direita = this->filho_direita->nome;
		    if (this->filho_esquerda != NULL) esquerda = this->filho_esquerda->nome;
			cout << endl << endl << "Nome: " << this->getNome() << endl;
			cout << "Direita: " << direita << endl;
			cout << "Esquerda: " << esquerda << endl;
			cout << "Pai: " << pai << endl;
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

		//percorre a arvore em busca de uma valor e o apaga

		int removerValor(int valor){
			Pessoa *apagar = this->buscar(valor);
			if(apagar->getPai() == NULL){
                //this = apagar->removerNo();
                //this->setPai(NULL);
                //delete apagar;
				cout << "Apaga raiz implementar mais tarde!" << endl;
				return 1;
			}
            if (apagar->pai->getFilhoDireita() == apagar) apagar->pai->setFilhoDireita(apagar->removerNo());
            else apagar->pai->setFilhoEsquerda(apagar->removerNo());
            delete apagar;
			return 1;
		};

		//realiza as operações necessarias para manter a arvore binária correta durante exclusão
		//retorno: Endereço de memória para o objeto que deve substituir o no a ser removido

		Pessoa* removerNo(){
		    Pessoa *retorno, *auxiliar;
		    if (this->filho_direita == NULL){
                retorno = this->filho_esquerda;
                if (retorno != NULL) retorno->setPai(this->pai);
                return retorno;
		    }
		    auxiliar = this;
		    retorno = this->filho_direita;
		    while(retorno->getFilhoEsquerda()!=NULL){
                auxiliar = retorno;
                retorno = retorno->getFilhoEsquerda();
		    }
		    if(auxiliar != this){
                retorno->getFilhoDireita()->setPai(auxiliar);
                auxiliar->setFilhoEsquerda(retorno->getFilhoDireita());
                //auxiliar->getFilhoEsquerda()->setPai(auxiliar);
                this->filho_direita->setPai(retorno);
                retorno->setFilhoDireita(this->filho_direita);
		    }
		    if (this->filho_esquerda != NULL) this->filho_esquerda->setPai(retorno);
		    retorno->setFilhoEsquerda(this->filho_esquerda);
		    retorno->setPai(this->getPai());
		    return retorno;
		};


		bool isFolha(){
			return (this->getFilhoDireita() == NULL) && (this->getFilhoEsquerda()==NULL);
		};

		bool isFull(){
			return (this->getFilhoDireita() != NULL) && (this->getFilhoEsquerda()!=NULL);
		};








};
