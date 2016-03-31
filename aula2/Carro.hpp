class Carro: public Veiculo
{
	private:
		int tipoCambio;
		int numeroAssentos;

	public:
		Carro()
		{

		};

		Carro(string mc, string md, float pr, int tc, int na ):Veiculo(mc, md, pr)
		{
			tipoCambio =  tc;
			numeroAssentos = na;
		};

		~Carro()
		{
		};

		void setTipoCambio(int tc)
		{
			tipoCambio = tc;
		};

		int getTipoCambio()
		{
			return tipoCambio;
		};

		void setNumeroAssentos(int na)
		{
			numeroAssentos = na;
		};

		int getNumeroAssentos()
		{
			return numeroAssentos;
		};



};
