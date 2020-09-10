package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.AoDiCar;
import DesignPattern.BuilderPattern.component.AoDi5sDoor;
import DesignPattern.BuilderPattern.component.AoDi5sWheel;
import DesignPattern.BuilderPattern.component.CarDoor;
import DesignPattern.BuilderPattern.component.CarWheel;

public class AoDi5sBuilder implements AoDiBuilder{
    private AoDiCar aoDiCar;

    public AoDi5sBuilder(){
        aoDiCar = new AoDiCar();
    }

    AoDi5sBuilder(AoDiCar car){
        aoDiCar = car;
    }

    @Override
    public void attachWheel() {
        CarWheel carWheel = new AoDi5sWheel();
        carWheel.createWheel();
        aoDiCar.setCarWheel(carWheel);
    }

    @Override
    public void attachDoor() {
        CarDoor carDoor = new AoDi5sDoor();
        carDoor.createDoor();
        aoDiCar.setCarDoor(carDoor);
}

    @Override
    public AoDiCar createCar() {
        attachDoor();
        attachWheel();
        return aoDiCar;
    }
}
