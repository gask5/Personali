
//GnrPosizioni e` un creator
import java.util.Set;
import java.util.TreeSet;

public abstract class GnrPosizioni {
    public static final int MAXPOSTI = 100;
    private final Set<String> posti = new TreeSet<>();

    public Posto prendiNumero(int x) {
        if (posti.size() == MAXPOSTI)
            return null;

        Posto p;
        do {
            p = getPosto(x);
        } while (posti.contains(p.getPosizione()));
        posti.add(p.getPosizione());
        return p;
    }

    public void printPostiOccupati() {
        for (String s : posti) {
            System.out.print(s + " ");
        }
    }

    public abstract Posto getPosto(int tipo);
}
