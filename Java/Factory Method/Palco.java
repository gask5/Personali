import java.util.Random;

public class Palco implements Posto {
    private final int numero;

    public Palco() {
        numero = new Random().nextInt(20) + 1;
    }

    @Override
    public int getCosto() {
        if (numero <= 5)
            return 50;
        else if (numero <= 10)
            return 40;
        else
            return 30;
    }

    @Override
    public String getPosizione() {
        return Integer.toString(numero);
    }

    @Override
    public String getSettore() {
        if (numero <= 5)
            return "Centrale Basso";
        if (numero <= 10)
            return "Centrale Alto";
        else
            return "Laterale";
    }
}