#include <string>
#include <iostream>

using namespace std;


class Pessoa
{

	protected:
		string nome;


	private:


	public:
		Pessoa()
		{
			nome = "";
		};


		Pessoa(string nm)
		{
			nome = nm;
		};

		~Pessoa()
		{
			cout << "Deletando instancia de Pessoa" << endl;
		};

		string getNome()
		{
			return nome;
		};

		void setNome(string nm)
		{
			nome = nm;
		};
};
