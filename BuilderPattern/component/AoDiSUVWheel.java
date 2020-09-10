package DesignPattern.BuilderPattern.component;

public class AoDiSUVWheel implements CarWheel {
    @Override
    public void createWheel() {
        System.out.println("奥迪最新suv山地车轮");
    }
}
