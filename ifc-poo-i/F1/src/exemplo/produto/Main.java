package exemplo.produto;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		Produto batata = new Produto("Batatas Ruffles", 23.08, 23);
		
		batata.escreverDados();
		
		System.out.println("O valor total do produto "+ batata.nome+ " é de R$"+batata.calcularValorTotal());
		
		System.out.println("Digite o valor para alterar a quantidade do produto");
		int alterarValor = -8;
		
		System.out.println("O produto "+ batata.nome + " foi alterado em " + alterarValor + ". Sua nova quantidade é: " + batata.alterarQuantidade(alterarValor)+ ", seu novo valor total é: " + batata.calcularValorTotal());
		
	}
}