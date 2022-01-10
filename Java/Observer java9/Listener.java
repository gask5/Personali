import java.util.concurrent.Flow.Subscriber;
import java.util.concurrent.Flow.Subscription;

public class Listener implements Subscriber<Article> {
    private String job;
    protected Subscription sub;
    private String name;

    protected Listener(String name) {
        this.setName(name);
        this.setJob("Listener");
    }

    @Override
    public void onSubscribe(Subscription s) {
        System.out.println(job + " " + name + ": attached to something");
        sub = s;
        sub.request(1);
    }

    @Override
    public void onNext(Article p) {
        String nom = p.getTitolo() + " " + p.getCorpo();
        System.out.println(job + " " + name + " onNext: " + nom);
        sub.request(1);
    }

    @Override
    public void onError(Throwable throwable) {
        System.out.println(job + " " + name + ": errore");
    }

    @Override
    public void onComplete() {
        System.out.println(job + " " + name + ": completato");
    }

    protected void setJob(String s) {
        this.job = s;
    }

    protected void setName(String n) {
        this.name = n;
    }
}