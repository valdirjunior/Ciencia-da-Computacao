package introducao.cachorro;

public class Cachorro {
	
	String nome;
	String raca;
	String cor;
	char sexo;
	double peso;
	
	void dormir(){
		System.out.println("O cachorro " + this.nome + " está dormindo");
	}
	void latir(){
		System.out.println("A raça " + this.raca + " segue latindo");
	}
	void comer(double pesoComida){
		this.peso += pesoComida;
		System.out.println(this.nome + " comeu e agora pesa " + this.peso + " kg");
	}
}
