package DesignPattern.BuilderPattern.Builder;

import DesignPattern.BuilderPattern.Car;

public interface  CarBuilder {
     void attachWheel();//安装车轮
     void attachDoor(); //安装车门
     Car  createCar();
}
