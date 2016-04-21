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
	    string pai, esquerda, direita;
			direita = "vazio";
			esquerda = "vazio";
			pai = "vazio";
	    if (this->pai != NULL) pai = this->pai->nome;
	    if (this->filho_direita != NULL) direita = this->filho_direita->nome;
	    if (this->filho_esquerda != NULL) esquerda = this->filho_esquerda->nome;
			cout << endl << endl << "Nome: " << this->nome << endl;
			cout << "Idade: " << this->idade << endl;
			cout << "Direita: " << direita << " Esquerda: " << esquerda << " Pai: " << pai << endl;
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

		//percorre a arvore em busca de um valor e o apaga

		int removerValor(int valor, Pessoa ** raiz){

			Pessoa *apagar = this->buscar(valor);


			if (apagar == NULL) {
				cout << "Não encontrado" << endl;
				return 0;
			}

			// if(apagar->getPai() == NULL){
			// 	(*raiz) = apagar->removerNo();
			// 	(*raiz)->setPai(NULL);
			// 	delete apagar;
			// 	return 1;
			// }
			if(apagar->getPai() == NULL){

				(*raiz) = apagar->removerNo();
				(*raiz)->setPai(NULL);
				delete apagar;
				return 1;
			}

			if (apagar->isFolha()) apagar->removerFolha(); //no fola
			else if ((apagar->getFilhoDireita() == NULL) || (apagar->getFilhoEsquerda() == NULL)){ // no com 1 filho
							if (apagar->getFilhoEsquerda() != NULL) apagar->removerUnicoEsquerda(); // no com 1 filho a esquerda
							else apagar->removerUnicoDireita(); // no com 1 filho a direita
						}
						else apagar->removerCheio(); //no com 2 filhos


			// if (apagar->isFilhoDireita()) apagar->pai->setFilhoDireita(novo_no);
			// else apagar->pai->setFilhoEsquerda(novo_no);


      delete apagar;
			return 1;
		};


		void removerFolha(){ //remove folha e também nó com apenas 1 filho
			if (this->isFilhoDireita()) this->pai->setFilhoDireita(NULL);
			else this->pai->setFilhoEsquerda(NULL);
		}


		Pessoa* removerUnicoDireita(){ // no só tem filho a direita
			Pessoa *novo_no;
			novo_no = this->filho_direita;
			if (this->isFilhoDireita()) this->pai->setFilhoDireita(this->filho_direita);
			else this->pai->setFilhoEsquerda(this->filho_direita);
			this->filho_direita->setPai(this->pai);
			return novo_no;
		}


		Pessoa* removerUnicoEsquerda(){ //no só tem filho a esquerda
			Pessoa *novo_no;
			novo_no = this->filho_esquerda;
			if (this->isFilhoDireita()) this->pai->setFilhoDireita(this->filho_esquerda);
			else this->pai->setFilhoEsquerda(this->filho_esquerda);
			this->filho_esquerda->setPai(this->pai);
			return novo_no;
		}





		Pessoa* removerCheio(){
			Pessoa *novo_no, *auxiliar;
			auxiliar = this; //pai do novo nó, substituir por novo_no->getPai() depois...
			novo_no = this->filho_direita; //nó que deve tomar lugar do nó removido
			while(novo_no->getFilhoEsquerda()!=NULL){
							auxiliar = novo_no;
							novo_no = novo_no->getFilhoEsquerda();
			}
			if(auxiliar != this){
							novo_no->getFilhoDireita()->setPai(auxiliar);
							auxiliar->setFilhoEsquerda(novo_no->getFilhoDireita());
							this->filho_direita->setPai(novo_no);
							novo_no->setFilhoDireita(this->filho_direita);
			}
			if (this->filho_esquerda != NULL) this->filho_esquerda->setPai(novo_no);
			novo_no->setFilhoEsquerda(this->filho_esquerda);
			novo_no->setPai(this->getPai());
			if (this->isFilhoDireita()) this->pai->setFilhoDireita(novo_no);
			else this->pai->setFilhoEsquerda(novo_no);
			return novo_no;
		}



		//realiza as opera��es necessarias para manter a arvore bin�ria correta durante exclus�o
		//retorno: Endere�o de mem�ria para o objeto que deve substituir o no a ser removido
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
			return (this->filho_esquerda == NULL) && (this->filho_direita==NULL);
		};

		bool isFull(){
			return (this->filho_direita != NULL) && (this->filho_esquerda != NULL);
		};

		bool isFilhoDireita(){
			return (this->pai->getFilhoDireita() == this);
		}








};
