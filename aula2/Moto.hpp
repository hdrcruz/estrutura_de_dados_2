class Moto:public Veiculo
{
	private:
		int cilindradas;

	public:
		Moto()
		{
		};

		Moto(string mc, string md, float pr, int cl):Veiculo(mc, md, pr)
		{
			cilindradas = cl;
		};


		~Moto()
		{
			cout << "Apagando moto" << endl;
		};

		void setCilindradas(int cl)
		{
			cilindradas  = cl;
		};

		int getCilindradas()
		{
			return cilindradas;
		};


};
