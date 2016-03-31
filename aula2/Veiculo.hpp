#include <string>
#include <iostream>

using namespace std;


class Veiculo
{

	protected:
		string marca;
		string modelo;
		float preco;

	private:
		int teste;

	public:
		Veiculo()
		{
			marca = "";
			modelo = "";
			preco = 0.0;
		};


		Veiculo(string mc, string md, float pr)
		{
			marca = mc;
			modelo = md;
			preco = pr;
		};

		~Veiculo()
		{
			cout << "Deletando instancia de veiculo" << endl;
		};

		int getTeste()
		{
			return teste;
		};

		void setTeste(int tst)
		{
			teste  = tst;
		};

		void setMarca(string mc)
		{
			marca = mc;
		};

		string getMarca()
		{
			return marca;
		};

		void setModelo(string md)
		{
			modelo = md;
		};

		string getModelo()
		{
			return modelo;
		};

		void setPreco(float pr)
		{
			preco = pr;
		};

		float getPreco()
		{
			return preco;
		};

};
