public class Liquido implements Stato {

    @Override
    public void mostraStato() {
        // TODO Auto-generated method stub
        System.out.println("Stato liquido.");
    }

    @Override
    public Stato riscalda() {
        // TODO Auto-generated method stub
        System.out.println("L'aumento di calore ha cambiato lo stato da LIQUIDO a GASSOSO.");
        return new Gassoso();
    }

    @Override
    public Stato raffredda() {
        // TODO Auto-generated method stub
        System.out.println("La diminuzione di calore ha cambiato lo stato da LIQUIDO a SOLIDO.");
        return new Solido();
    }

}
