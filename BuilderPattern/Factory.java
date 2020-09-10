package DesignPattern.BuilderPattern;

import DesignPattern.BuilderPattern.Builder.AoDi5sBuilder;
import DesignPattern.BuilderPattern.Builder.AoDiSUVBuilder;
import DesignPattern.BuilderPattern.Builder.BaoMa5sBuilder;
import DesignPattern.BuilderPattern.Builder.BaoMaSUVBuilder;

public class Factory {
    private Car car;

    public Car create(String name){
        switch (name){
            case "宝马SUV":
                BaoMaSUVBuilder baoMaSUVBuilder = new BaoMaSUVBuilder();
                car = baoMaSUVBuilder.createCar();
                break;
            case "宝马5s":
                BaoMa5sBuilder baoMa5sBuilder = new BaoMa5sBuilder();
                car = baoMa5sBuilder.createCar();
                break;
            case "奥迪SUV":
                AoDiSUVBuilder aoDiSUVBuilder = new AoDiSUVBuilder();
                car = aoDiSUVBuilder.createCar();
                break;
            case "奥迪5s":
                AoDi5sBuilder aoDi5sBuilder = new AoDi5sBuilder();
                car = aoDi5sBuilder.createCar();
                break;
            default:
                car = null;

        }
        return car;
    }
}
