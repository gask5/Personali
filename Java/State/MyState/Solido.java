public class Solido implements Stato {

    @Override
    public void mostraStato() {
        // TODO Auto-generated method stub
        System.out.println("Stato solido.");
    }

    @Override
    public Stato riscalda() {
        // TODO Auto-generated method stub
        System.out.println("L'aumento di calore ha cambiato lo stato da SOLIDO a LIQUIDO.");
        return new Liquido();
    }

    @Override
    public Stato raffredda() {
        // TODO Auto-generated method stub
        System.out.println("La diminuzione di calore non ha portato nessun cambiamento di stato.");
        return new Solido();
    }

}
