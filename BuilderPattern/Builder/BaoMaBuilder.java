package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.AoDiCar;
import DesignPattern.BuilderPattern.BaoMaCar;
import DesignPattern.BuilderPattern.Car;
import DesignPattern.BuilderPattern.component.CarDoor;

public interface BaoMaBuilder extends CarBuilder{

    @Override
    BaoMaCar createCar();


}
