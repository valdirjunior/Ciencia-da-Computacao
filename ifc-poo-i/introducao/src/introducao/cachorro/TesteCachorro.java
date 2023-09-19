package introducao.cachorro;

public class TesteCachorro {
	
	public static void main(String[] args) {
		Cachorro rex = null;
		rex = new Cachorro();
		
		rex.nome = "Rex da Silva";
		rex.cor = "caramelo";
		rex.peso = 10;
		rex.raca = "M";
			

		rex.dormir();
	}
}