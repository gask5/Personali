public class Gassoso implements Stato {

    @Override
    public void mostraStato() {
        // TODO Auto-generated method stub
        System.out.println("Stato gassoso.");
    }

    @Override
    public Stato riscalda() {
        System.out.println("L'aumento di calore non portato differenze di stato.");
        return new Gassoso();
    }

    @Override
    public Stato raffredda() {
        // TODO Auto-generated method stub
        System.out.println("La dinuzione ha cambiato lo stato da GASSOSO a LIQUIDO.");
        return new Liquido();
    }

}