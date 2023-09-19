package introducao.pessoa;

public class Pessoa {
	
	String nome;
	char sexo;
	int anoNascimento;
	
	public Pessoa(String nome, char s, int anoNasc){
		this.nome = nome;
		this.sexo = s;
		this.anoNascimento = anoNasc;
	}
	
	void cumprimentar(){
		
		if(this.sexo == 'm') {
			System.out.println("Bom dia Sr. " + this.nome);
		} else if(this.sexo == 'f') {
			System.out.println("Bom dia Sra. " + this.nome);
		} else {
			System.out.println("Bom dia " + this.nome);
		}
		
	}
	
	int calcularIdade() {
		return 2023 - this.anoNascimento;
	}
	
}
