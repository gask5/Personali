//Biglietto e` un client del Product Posto
public class Biglietto {
    private String nome;
    private final Posto pos;

    public Biglietto(Posto p) {
        pos = p;
    }

    public void intesta(String s) {
        nome = s;
    }

    public String getDettagli() {
        String nomeTemp = (" Nome: ".concat(nome));
        String posTemp = (" Posizione: ").concat(pos.getPosizione());
        String costoTemp = (" Costo:").concat(Integer.toString(pos.getCosto()));
        return nomeTemp.concat(posTemp).concat(costoTemp);
    }

    public String getNome() {
        return nome;
    }

    public int getCosto() {
        return pos.getCosto();
    }

}
