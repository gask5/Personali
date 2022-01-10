public class H2o {
    private Stato acqua = new Liquido();

    public void mostra() {
        acqua.mostraStato();
    }

    public void aumentaTemperatura() {
        acqua = acqua.riscalda();
    }

    public void abbassaTemperatura() {
        acqua = acqua.raffredda();
    }
}
