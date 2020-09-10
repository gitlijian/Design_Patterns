package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.AoDiCar;
import DesignPattern.BuilderPattern.BaoMaCar;
import DesignPattern.BuilderPattern.Car;

public interface AoDiBuilder extends CarBuilder {

    @Override
    AoDiCar createCar();

}
