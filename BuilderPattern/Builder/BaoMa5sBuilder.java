package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.BaoMaCar;
import DesignPattern.BuilderPattern.component.*;

public class BaoMa5sBuilder implements BaoMaBuilder{
    private BaoMaCar baoMaCar;
    public BaoMa5sBuilder(){
        baoMaCar = new BaoMaCar();
    }
    public BaoMa5sBuilder(BaoMaCar car){
        baoMaCar = car;
    }
    @Override
    public void attachWheel() {
        CarWheel carWheel = new BaoMa5sWheel();
        carWheel.createWheel();
        baoMaCar.setCarWheel(carWheel);
    }
    @Override
    public void attachDoor(){
        CarDoor carDoor = new BaoMa5sDoor();
        carDoor.createDoor();
        baoMaCar.setCarDoor(carDoor);
    }
    @Override
    public BaoMaCar createCar() {

        attachWheel();
        attachDoor();
        return baoMaCar;
    }
}
