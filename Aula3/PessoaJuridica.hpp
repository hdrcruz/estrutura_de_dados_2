class PessoaJuridica: public Pessoa{
    private:
        int cnpj;

    public:

        PessoaJuridica(){
            cnpj = 0;
        };

        PessoaJuridica(int valor){
            cnpj = valor;
        };

        void setCpf(int valor){
            cnpj = valor;
        };

        int getCpf(){
            return cnpj;
        };


};
