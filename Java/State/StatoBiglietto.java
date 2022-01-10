// Codice Java che implementa il design pattern State

// StatoBiglietto e' uno State
public interface StatoBiglietto {
    public void mostra();

    public StatoBiglietto intesta(String s);

    public StatoBiglietto paga();

    public StatoBiglietto cancella();
}