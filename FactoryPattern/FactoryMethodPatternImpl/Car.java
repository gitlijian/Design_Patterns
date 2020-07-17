package DesignPattern.FactoryPattern.FactoryMethodPattern;

public interface Car {
    void createCar();
}

class AoDi implements Car{
    public void createCar(){
        System.out.println("生产奥迪汽车");
    }
}

class BaoMa implements Car{
    public void createCar(){
        System.out.println("生产宝马汽车");
    }
}

class BenChi implements Car{
    public void createCar(){
        System.out.println("生产奔驰汽车");
    }
}

class DaZhong implements Car{
    public void createCar(){
        System.out.println("生产大众汽车");
    }
}
