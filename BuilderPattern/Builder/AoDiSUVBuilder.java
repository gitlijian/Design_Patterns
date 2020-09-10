package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.AoDiCar;
import DesignPattern.BuilderPattern.component.*;

public class AoDiSUVBuilder implements AoDiBuilder {

    private AoDiCar aoDiCar;
    public AoDiSUVBuilder(){
        aoDiCar = new AoDiCar();
    }
    AoDiSUVBuilder(AoDiCar car){
        aoDiCar = car;
    }
    @Override
    public AoDiCar createCar() {
        attachDoor();
        attachWheel();
        return aoDiCar;
    }

    @Override
    public void attachWheel() {
        CarWheel carWheel = new AoDiSUVWheel();
        carWheel.createWheel();
        aoDiCar.setCarWheel(carWheel);
    }

    @Override
    public void attachDoor() {
        CarDoor carDoor = new AoDiSUVDoor();
        carDoor.createDoor();
        aoDiCar.setCarDoor(carDoor);
    }
}
