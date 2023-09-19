package br.com.castorsoft;

public class Televisao {
	
	String marca;
	String estado;
	int canal;
	
	Televisao(String marca, String estado, int canal){
		this.marca = marca;
		this.estado = estado;
		this.canal = canal;
	}
	
	void ligar() {
		this.estado = "Ligado";
	}
	
	void desligar() {
		this.estado = "Desligado";
	}
	
	int mudarCanal() {
		if(canal == 11) {
			canal = 13;
		} else if(canal == 13) {
			canal = 5;
		} else {
		canal +=3;
		}
		return this.canal;
	}
	
}