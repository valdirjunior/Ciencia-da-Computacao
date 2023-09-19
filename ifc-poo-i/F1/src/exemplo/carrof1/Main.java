package exemplo.carrof1;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Carro felipeMassa = new Carro(0, 15, "Ferrari");
		
		Scanner sc = new Scanner(System.in);
		int velo = 1;
		
		while (velo != 0) {
			System.out.println("O carro da marca "+ felipeMassa.nomeEquipe + " está a " + felipeMassa.velocidadeAtual+
					"km/h. Digite 1 para acelerar, 2 para frear e 0 para abandonar a corrida");
			velo = sc.nextInt();
			
			if(velo == 1) {
				felipeMassa.acelerar();
				if(felipeMassa.velocidadeAtual < (felipeMassa.velocidadeMaxima - 5)) {
					System.out.println("Você acelerou, a velocidade atual é: "+ felipeMassa.velocidadeAtual);	
				} else {
					System.out.println("Velocidade máxima atingida " + felipeMassa.velocidadeMaxima+" km/h.");
				}
				
			} else if(velo == 2) {
				felipeMassa.frear();
				System.out.println("Você freou, a velocidade atual é: "+ felipeMassa.velocidadeAtual);
			} else if( velo == 0 ){
				System.out.println("Fim.");
			} else{
				System.out.println("Valor incorreto, tente novamente");
			}
		}
		
	}
}
