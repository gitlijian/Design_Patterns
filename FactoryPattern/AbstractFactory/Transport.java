package DesignPattern.FactoryPattern.AbstractFactory;

/**
 * 前面的工厂方法模式可以看作抽象工厂方法的特例，即只有一个产品系列(接口)，假设我们出行只能选择开车的时候，我们可以使用工厂方法模式
 * 因此我只需要实现一个Car的接口即可。
 * 假设我们出行的地方较多时，需要先坐飞机再乘轮船最后开汽车才能到达，我们就面临多个接口的不同实现问题，所以就产生了很多种组合。
 * 而我们最终只能选择一种方式出行。(飞机有国航、东方航空等，轮船有游轮、快艇等，火车有高铁、普快等，汽车有奥迪、奔驰等)
 * 假设我们有500块，可以选择国航(飞机)+快艇（轮船）+奥迪（汽车）
 * 有700,可以选择国航(飞机)+游轮（轮船）+奥迪（汽车）
 * 有1000块，则可以选择东方航空(飞机)+游轮(轮船)+宝马(汽车)
 * 工厂方法模式，我们针对汽车，根据不同情况对用一个接口(同一种类)有不同的选择
 * 抽象工厂模式，我们根据不用的情况对不同的种类有不同的套餐选择
 * 针对每种套餐，我们可以创建一个具体的工厂用来创建这些实例。
 * 所以抽象工厂即工厂的工厂
 */
public interface Transport {
    Car useCar();
    Ship useShip();
    Air useAir();
}
//500元方案
class FiveMethodFactory implements Transport{
    @Override
    public Car useCar() {
        return new AoDi();
    }

    @Override
    public Ship useShip() {
        return new KuaiTing();
    }

    @Override
    public Air useAir() {
        return new GuoHang();
    }
}
//700方案
class SevenMethodFactory implements Transport{
    @Override
    public Car useCar() {
        return new AoDi();
    }

    @Override
    public Ship useShip() {
        return new YouLun();
    }

    @Override
    public Air useAir() {
        return new GuoHang();
    }
}
//1000方案
class ThousandsMethodFactory implements Transport{
    @Override
    public Car useCar() {
        return new BaoMa();
    }

    @Override
    public Ship useShip() {
        return new YouLun();
    }

    @Override
    public Air useAir() {
        return new DongFang();
    }
}
interface Car {
    void createCar();
}

interface Ship{
    void createShip();
}

interface Air{
    void createAir();
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

class YouLun implements Ship{
    public void createShip(){
        System.out.println("游轮");
    }
}

class KuaiTing implements Ship{
    public void createShip(){
        System.out.println("快艇");
    }
}

class GuoHang implements Air{
    public void createAir(){
        System.out.println("国航航班");
    }
}

class DongFang implements Air{
    public void createAir(){
        System.out.println("东方航空航班");
    }
}
