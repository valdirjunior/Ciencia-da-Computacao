package br.com.castorsoft;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Televisao sala = new Televisao("philco", "Desligado", 5);
		
		int estado = 0;
		Scanner sc = new Scanner(System.in);
		
		while (estado != -1) {
			System.out.println("A televisão da marca "+ sala.marca + " está no canal "+ sala.canal 
					+ " e está "+ sala.estado);
			System.out.println("Digite 1 para ligar/desligar, Digite 2 para mudar de canal, Digite -1 para sair");
			estado = sc.nextInt();
			
			if(estado == 1) {
				if(sala.estado == "Ligado") {
					sala.desligar();
				} else {
					sala.ligar();
				}
			} else if(estado == 2) {
				sala.mudarCanal();
			} else if(estado == -1) {
				System.out.println("Fim.");
			} else {
				System.out.println("Comando Inválido.");
			}
		}
		
	}
}
