import java.util.concurrent.Flow.Subscriber;
import java.util.concurrent.Flow.Subscription;

public class Journalist extends Listener {

    Journalist(String name) {
        super(name);
        this.setJob("Journalist");
    }

    @Override
    public void onNext(Article p) {
        System.out.println("IN ANTEPRIMA!");
        super.onNext(p);
    }

}