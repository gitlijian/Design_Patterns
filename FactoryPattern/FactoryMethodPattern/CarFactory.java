package DesignPattern.FactoryPattern.FactoryMethodPattern;

/**
 * 不同于简单工厂，简单工厂创建不同实现的类时，方法是耦合的，工厂方法模式则是将不同类的不同实现的创建过程给解耦
 * 简单工厂对修改开放(需要修改工厂类)，工厂方法模式对修改闭合，只对扩展开放，将不同的实现的创建过程也给隔离开来。
 */
public interface CarFactory {

    Car create();
}

class AoDiFactory implements CarFactory{
    public Car create(){
        return new AoDi();
    }
}

class BaoMaFactory implements CarFactory{
    public Car create(){
        Car car = new BaoMa();
        return car;
    }
}

class BenChiFactory implements CarFactory{
    public Car create(){
        Car car = new BenChi();
        return car;
    }
}

class DaZhongFactory implements CarFactory{
    public Car create(){
        Car car = new DaZhong();
        return car;
    }
}
