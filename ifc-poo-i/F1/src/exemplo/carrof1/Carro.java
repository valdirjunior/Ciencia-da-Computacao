package exemplo.carrof1;

public class Carro {
	
	int velocidadeAtual;
	int velocidadeMaxima;
	String nomeEquipe;
	
	Carro(int veloAtual, int veloMax, String nomeEquipe){
		this.velocidadeAtual = veloAtual;
		this.velocidadeMaxima = veloMax;
		this.nomeEquipe = nomeEquipe;
	}
	
	int acelerar(){
		if(velocidadeAtual < (velocidadeMaxima - 4)) {
			this.velocidadeAtual +=5;
			return this.velocidadeAtual;	
		} else {
			return velocidadeMaxima;
		}
	}
	
	int frear() {
		if(this.velocidadeAtual > 10) {
			this.velocidadeAtual -=10;
		} else {
			this.velocidadeAtual = 0;
		}
		return this.velocidadeAtual;
	}
	
}
