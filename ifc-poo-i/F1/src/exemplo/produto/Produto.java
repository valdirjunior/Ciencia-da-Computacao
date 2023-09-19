package exemplo.produto;

public class Produto {
	
	String nome;
	double valor;
	int quantidade;
	
	Produto(String nome, double valor, int qntd){
		this.nome = nome;
		this.valor = valor;
		this.quantidade = qntd;
	}
	
	void escreverDados() {
		System.out.println("O produto "+ this.nome + " de custo R$" + this.valor + " tem " + this.quantidade + " itens em estoque");
	}
	
	double calcularValorTotal() {
		return this.valor * this.quantidade;
	}
	
	
	int alterarQuantidade(int qntd) {
		
		this.quantidade = this.quantidade + qntd;
		
		return this.quantidade;
	}
	
}
