package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.BaoMaCar;
import DesignPattern.BuilderPattern.component.BaoMaSUVDoor;
import DesignPattern.BuilderPattern.component.BaoMaSUVWheel;
import DesignPattern.BuilderPattern.component.CarDoor;
import DesignPattern.BuilderPattern.component.CarWheel;

public class BaoMaSUVBuilder implements BaoMaBuilder{
    private BaoMaCar baoMaCar;

    public BaoMaSUVBuilder(){
        baoMaCar = new BaoMaCar();
    }
    BaoMaSUVBuilder(BaoMaCar car){
        baoMaCar = car;
    }
    @Override
    public void attachWheel() {
        CarWheel carWheel = new BaoMaSUVWheel();
        carWheel.createWheel();
        baoMaCar.setCarWheel(carWheel);
    }
    @Override
    public void attachDoor(){
        CarDoor carDoor = new BaoMaSUVDoor();
        carDoor.createDoor();
        baoMaCar.setCarDoor(carDoor);
    }
    @Override
    public BaoMaCar createCar() {
        attachDoor();
        attachWheel();
        return baoMaCar;
    }


}
