package DesignPattern.BuilderPattern;

import DesignPattern.BuilderPattern.component.CarDoor;
import DesignPattern.BuilderPattern.component.CarWheel;
import DesignPattern.BuilderPattern.component.CarWind;

public class BaoMaCar implements Car{

    private CarDoor carDoor;//车门
    private CarWheel carWheel;//车轮


    public void setCarDoor(CarDoor carDoor) {
        this.carDoor = carDoor;
    }

    public void setCarWheel(CarWheel carWheel) {
        this.carWheel = carWheel;
    }

    @Override
    public void useCar() {
        System.out.println("使用宝马车");
    }
}
