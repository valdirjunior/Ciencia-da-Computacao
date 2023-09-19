package br.com.castorsoft;

public class ContaCorrente {
    
    private String nome;
    private String cpf;
    private double saldo;
    private String numeroConta;
    private String agencia;

    public ContaCorrente() {
        this.nome = nome;
        this.cpf = cpf;
        this.saldo = 0;
        this.numeroConta = gerarNumeroConta();
        this.agencia = "123";
    }

    private String gerarNumeroConta() {
        return random;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCpf(){
        return this.cpf;
    }

    public Double getSaldo(){
        return this.saldo;
    }

    public String getAgencia(){
        return this.agencia;
    }

    public String set

    

}