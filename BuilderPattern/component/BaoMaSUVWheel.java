package DesignPattern.BuilderPattern.component;

public class BaoMaSUVWheel implements CarWheel{
    @Override
    public void createWheel() {
        System.out.println("宝马suv越野车轮");
    }
}
