package introducao.pessoa;

public class Main {
	public static void main(String[] args) {
		
		Pessoa p1 = new Pessoa("asas", 'm', 2015);
		
		
		p1.cumprimentar();
		
		int idade = p1.calcularIdade();
		System.out.println("Sua idade é: "+idade);
		
	}
}
