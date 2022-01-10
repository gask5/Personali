import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.SubmissionPublisher;
import java.util.concurrent.Flow.Subscriber;

public class Journal {
    private List<Article> articoliModa = new ArrayList<>();
    private List<Article> articoliSport = new ArrayList<>();
    private SubmissionPublisher<Article> sport = new SubmissionPublisher<>();
    private SubmissionPublisher<Article> moda = new SubmissionPublisher<>();

    public void attachSport(Subscriber<Article> s) {
        sport.subscribe(s);
    }

    public void attachModa(Subscriber<Article> s) {
        moda.subscribe(s);
    }

    public boolean insertSport(Article p) {
        if (articoliSport.contains(p))
            return false;
        articoliSport.add(p);
        sport.submit(p);
        return true;
    }

    public boolean insertModa(Article p) {
        if (articoliModa.contains(p))
            return false;
        articoliModa.add(p);
        moda.submit(p);
        return true;
    }

    public void close() {
        System.out.println("Sottoscritti a moda: " + moda.getNumberOfSubscribers());
        System.out.println("Sottoscritti a sport: " + sport.getNumberOfSubscribers());
        sport.close();
        moda.close();
    }
}