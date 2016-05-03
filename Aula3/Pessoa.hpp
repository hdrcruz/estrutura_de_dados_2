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
		

		int listarPre(Pessoa * raiz){
	    /*string pai, esquerda, direita;
			direita = "vazio";
			esquerda = "vazio";
			pai = "vazio";
	    if (this->pai != NULL) pai = this->pai->nome;
	    if (this->filho_direita != NULL) direita = this->filho_direita->nome;
	    if (this->filho_esquerda != NULL) esquerda = this->filho_esquerda->nome;*/
			cout << endl << endl << "Nome: " << this->nome << endl;
			/*cout << "Idade: " << this->idade << endl;
			cout << "Direita: " << direita << " Esquerda: " << esquerda << " Pai: " << pai << endl;*/
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) this->filho_esquerda->listarPre(raiz);
				if (this->filho_direita != NULL) this->filho_direita->listarPre(raiz);
			}
		};
		
		int listarOrdem(){
			if (this->isFolha()){
				cout << endl << endl << "Nome: " << this->nome << endl;
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) this->filho_esquerda->listarOrdem();
				cout << endl << endl << "Nome: " << this->nome << endl;
				if (this->filho_direita != NULL) this->filho_direita->listarOrdem();
			}
		};


		int apagarArvore(){
			if ((this->filho_esquerda == NULL) && (this->filho_direita==NULL)) {
				delete this;
				return 0;
			}
			else{
				if (this->filho_esquerda != NULL) this->filho_esquerda->apagarArvore();
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

		Pessoa removerValor(int valor, Pessoa ** raiz){
			Pessoa retorno;
			retorno.setIdade(-1);
			retorno.setNome("NULO");
			Pessoa *apagar = this->buscar(valor);
			if (apagar == NULL) {
				cout << "Não encontrado" << endl;
				return retorno;
			}
			if (apagar->isFolha()) apagar->removerFolha(raiz); //no fola
			else if ((apagar->getFilhoDireita() == NULL) || (apagar->getFilhoEsquerda() == NULL)){ // no com 1 filho
							if (apagar->getFilhoEsquerda() != NULL) apagar->removerUnicoEsquerda(raiz); // no com 1 filho a esquerda
							else apagar->removerUnicoDireita(raiz); // no com 1 filho a direita
						}
						else apagar->removerCheio(raiz); //no com 2 filhos
			retorno.setIdade(apagar->getIdade());
			retorno.setNome(apagar->getNome());
			delete apagar;
			return retorno;
		};


		void removerFolha(Pessoa ** raiz){ //remove folha
			Pessoa *substituto = NULL; 
			if(this->pai == NULL){
				cout << (*raiz)->getNome() << endl;
				*raiz = substituto;			
			}
			else	if (this->isFilhoDireita()) this->pai->setFilhoDireita(NULL);
					else this->pai->setFilhoEsquerda(NULL);						
		}


		Pessoa* removerUnicoDireita(Pessoa ** raiz){ // no só tem filho a direita
			Pessoa *substituto;
			substituto = this->filho_direita;
			if(this->pai == NULL){
				cout << (*raiz)->getNome() << endl;
				*raiz = substituto;
				(*raiz)->setPai(NULL);
				cout << (*raiz)->getNome() << endl;				
			}
			else{
				if (this->isFilhoDireita()) this->pai->setFilhoDireita(this->filho_direita);
				else this->pai->setFilhoEsquerda(this->filho_direita);
				if (this->filho_direita != NULL) this->filho_direita->setPai(this->pai);				
			}			
			return substituto;
		}


		Pessoa* removerUnicoEsquerda(Pessoa ** raiz){ //no só tem filho a esquerda
			Pessoa *substituto;
			substituto = this->filho_esquerda;
			if(this->pai == NULL){
				cout << (*raiz)->getNome() << endl;
				*raiz = substituto;
				(*raiz)->setPai(NULL);
				cout << (*raiz)->getNome() << endl;
			}
			else{
				if (this->isFilhoDireita()) this->pai->setFilhoDireita(this->filho_esquerda);
				else this->pai->setFilhoEsquerda(this->filho_esquerda);
				if (this->filho_esquerda != NULL) this->filho_esquerda->setPai(this->pai);
			}						 
			return substituto;
		}

		Pessoa* removerCheio(Pessoa ** raiz){
			Pessoa *substituto, *auxiliar;
			auxiliar = this; //pai do nó substituto, substituir por substituto->getPai() depois...
			substituto = this->filho_direita; //nó que deve tomar lugar do nó removido
			while(substituto->getFilhoEsquerda()!=NULL){
							auxiliar = substituto;
							substituto = substituto->getFilhoEsquerda();
			}
			if(auxiliar != this){
							if(substituto->getFilhoDireita() != NULL) substituto->getFilhoDireita()->setPai(auxiliar);
							if(auxiliar != NULL) auxiliar->setFilhoEsquerda(substituto->getFilhoDireita());							
							this->filho_direita->setPai(substituto);
							substituto->setFilhoDireita(this->filho_direita);
			}
			if (this->filho_esquerda != NULL) this->filho_esquerda->setPai(substituto);
			substituto->setFilhoEsquerda(this->filho_esquerda);
			substituto->setPai(this->getPai());
			if(this->pai == NULL){
				cout << (*raiz)->getNome() << endl;
				*raiz = substituto;
				(*raiz)->setPai(NULL);
				cout << (*raiz)->getNome() << endl;
			} else	if (this->isFilhoDireita()) this->pai->setFilhoDireita(substituto);
					else this->pai->setFilhoEsquerda(substituto);			
			return substituto;
		}


		//realiza as opera��es necessarias para manter a arvore bin�ria correta durante exclus�o
		//retorno: Endere�o de mem�ria para o objeto que deve substituir o no a ser removido
		Pessoa* removerNo(){
		    Pessoa *substituto, *auxiliar;
		    if (this->filho_direita == NULL){
                substituto = this->filho_esquerda;
                if (substituto != NULL) substituto->setPai(this->pai);
                return substituto;
		    }
		    auxiliar = this;
		    substituto = this->filho_direita;
		    while(substituto->getFilhoEsquerda()!=NULL){
                auxiliar = substituto;
                substituto = substituto->getFilhoEsquerda();
		    }
		    if(auxiliar != this){
                substituto->getFilhoDireita()->setPai(auxiliar);
                auxiliar->setFilhoEsquerda(substituto->getFilhoDireita());
                //auxiliar->getFilhoEsquerda()->setPai(auxiliar);
                this->filho_direita->setPai(substituto);
                substituto->setFilhoDireita(this->filho_direita);
		    }
		    if (this->filho_esquerda != NULL) this->filho_esquerda->setPai(substituto);
		    substituto->setFilhoEsquerda(this->filho_esquerda);
		    substituto->setPai(this->getPai());
		    return substituto;
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

		Pessoa * getRaiz(){ //retorna a raiz da arvore a partir de qualquer nó
			Pessoa *raiz;
			raiz = this->pai;
			while (raiz->pai!=NULL) {
				raiz = raiz->getPai();
			}
		}
		
		bool isRaiz(){
			return (this->pai == NULL);			
		}


};
