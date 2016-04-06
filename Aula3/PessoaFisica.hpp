class PessoaFisica: public Pessoa{

    private:
        int cpf;

    public:

        PessoaFisica(){
            cpf = 0;
        };

        PessoaFisica(int valor){
            cpf = valor;
        };

        void setCpf(int valor){
            cpf = valor;
        };

        int getCpf(){
            return cpf;
        };


};
