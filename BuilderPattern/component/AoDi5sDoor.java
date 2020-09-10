package DesignPattern.BuilderPattern.component;

public class AoDi5sDoor implements CarDoor{
    @Override
    public void createDoor() {
        System.out.println("使用奥迪最新5代车门");
    }
}
