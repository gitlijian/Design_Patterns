package DesignPattern.BuilderPattern.component;

public class AoDiSUVDoor implements CarDoor {
    @Override
    public void createDoor() {
        System.out.println("奥迪suv型大车门");
    }
}
