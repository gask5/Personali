public class Client {
    private static H2o chimica = new H2o();

    public static void main(String[] args) {
        routine();
    }

    private static void routine() {
        chimica.aumentaTemperatura();
        chimica.aumentaTemperatura();
        chimica.mostra();
        chimica.aumentaTemperatura();
        chimica.abbassaTemperatura();
        chimica.aumentaTemperatura();
        chimica.mostra();

        chimica.abbassaTemperatura();
        chimica.abbassaTemperatura();
        chimica.abbassaTemperatura();

        chimica.mostra();

    }
}