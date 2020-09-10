package DesignPattern.BuilderPattern.component;

public class AoDi5sWheel implements CarWheel {
    @Override
    public void createWheel() {
        System.out.println("奥迪5s最新车轮");
    }
}
