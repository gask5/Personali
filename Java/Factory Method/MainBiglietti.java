//Classe main
public class MainBiglietti {
    private static Posizioni cp = new Posizioni();

    public static void main(String[] args) {
        Posto pos = cp.prendiNumero(0);
        Biglietto b = new Biglietto(pos);
        b.intesta("Gabriele");

        System.out.println(b.getDettagli());

        new Biglietto(cp.prendiNumero(0));
        new Biglietto(cp.prendiNumero(0));
        cp.printPostiOccupati();
    }
}