package DesignPattern.BuilderPattern;

import DesignPattern.BuilderPattern.component.CarWheel;
import DesignPattern.BuilderPattern.component.CarWind;

public interface Car {
    void useCar(); //汽车抽象应该只关注自己是如何被使用的，而不关注自己是如何被创造的
}
