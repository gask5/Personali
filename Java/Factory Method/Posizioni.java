//ConcreteCreator
public class Posizioni extends GnrPosizioni {
    @Override
    public Posto getPosto(int tipo) { // metodo Factory
        if (1 == tipo)
            return new Palco();
        return new Platea();
    }
}
