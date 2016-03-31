#include "Veiculo.hpp"
#include "Carro.hpp"
#include "Moto.hpp"

int main(int argc, char **argv){

	string marca;
	string modelo;
	float valor;
	int numero;
	int assentos;
	int cambio;
	int cilindradas;
	int contador;


/*
	Veiculo veiculo;
	cout << "Informe a marca do veiculo:" << endl;
	cin >> texto;
	veiculo.setMarca(texto);

	cout << "Informe o modelo do veiculo:" << endl;
	cin >> texto;
	veiculo.odelo(texto);

	cout << "Informe o preco do veiculo:" << endl;
	cin >> valor;
	veiculo.setPreco(valor);

	cout << "Dados do veiculo:" << endl;
	cout << veiculo.getMarca() << " - ";
	cout << veiculo.getModelo() << " - ";
	cout << veiculo.getPreco() << endl << endl;

	Carro *carro;
	carro = new Carro();

	cout << "Informe a marca do carro:" <<endl;
	cin >> texto;
	carro->setMarca(texto);

	cout << "Informe o modelo do carro" << endl;
	cin >> texto;
	carro->setModelo(texto);

	cout << "Informe o preco do carro" << endl;
	cin >> valor;
	carro->setPreco(valor);


	cout << "Informe a quantidade de assentos:" << endl;
	cin >> assentos;
	carro->setNumeroAssentos(assentos);


	cout << "Informe o tipo de cambio do carro:" << endl;
	cin >> cambio;
	carro->setTipoCambio(cambio);
*/
/*
 Moto *moto;
 moto = new Moto("Marca","Modelo",45,150);

	cout << "Dados do carro:" << endl;
	cout << moto->getMarca() << " - ";
	cout << moto->getModelo() << " - ";
	cout << moto->getPreco() << " - ";
	cout << moto->getCilindradas() << endl << endl;
	delete moto;
*/

Moto *vetor_motos;
vetor_motos = new Moto[10];

for (contador = 0; contador < 2; contador++) {
	cout << "Dados para Moto "<< contador << ":" << endl;

	cout << "Informe a marca:" <<endl;
	cin >> marca;
	vetor_motos[contador].setMarca(marca);


	cout << "Informe o modelo:" << endl;
	cin >> modelo;
	vetor_motos[contador].setModelo(modelo);

	cout << "Informe o preco" << endl;
	cin >> valor;
	vetor_motos[contador].setPreco(valor);

	cout << "Informe as cilindradas" << endl;
	cin >> cilindradas;
	vetor_motos[contador].setPreco(cilindradas);

	cout << endl << endl;

	cin.clear();
}



delete [] vetor_motos;



	return 0;

}
