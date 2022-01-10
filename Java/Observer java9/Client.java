
public class Client {
    private Journal journal = new Journal();

    private Listener l1 = new Journalist("Fulvio");
    private Listener l2 = new Listener("Salvo");

    private Listener l3 = new Journalist("Mirko");
    private Listener l4 = new Journalist("Toto");

    private Listener l5 = new Listener("Ciccio");

    private Listener l6 = new Listener("Lino");

    public static void main(String[] args) throws InterruptedException {
        Client c = new Client();
        c.test();
        Thread.sleep(10000);

    }

    private void test() {
        journal.attachModa(l1);
        journal.attachModa(l2);
        journal.attachSport(l3);
        journal.attachSport(l4);
        journal.attachSport(l5);
        journal.attachModa(l6);
        journal.attachSport(l6);

        Article a1 = createArticle("Titolo sportivo", "Pallone d'oro a Lionel MESSI!");
        Article a2 = createArticle("Titolo Moda", "Fashion week a MILANO il 15 dicembre!");
        Article a3 = createArticle("Titolo Moda", "Fashion week a ROMA il 15 dicembre!");

        journal.insertSport(a1);
        journal.insertModa(a2);
        // journal.close();
    }

    private Article createArticle(String titolo, String corpo) {
        Article a = new Article();
        a.setTitolo(titolo);
        a.setCorpo(corpo);
        return a;
    }
}