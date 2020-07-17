package DesignPattern.FactoryPattern.AbstractFactory;

/**
 * 虽然抽象工厂可以实现不同接口的不同实现的组合
 * 但是当我们如果又新增一个接口(加入又新加入了自行车、火车)时，我们需要修改Transport接口，同时更改该接口的实现类(这也是工厂方法模式
 * 的缺点，我们上面说的汽车工厂，将Car抽象为了一个接口，假设我们需要在汽车中新增一个造车轮的方法，则所有该接口的实现类都需要修改)
 * 并且还要新增火车的对应不同实现(使用简单工厂或者工厂方法模式或者其他模式)
 * 所以不易扩展
 * 可以使用简单工厂来改进该模式，因为Transport使用工厂方法模式抽象为了一个接口，可以将其降为简单工厂模式
 * 即使用简单工厂模式实现Transport，这样，我们新增的时候，只需要修改Transport这个简单工厂类即可。
 * 更好的方法是利用反射来实现抽象工厂。
 */
public class Test {
    public static void main(String[] args) {
        //普通模式
        Transport fiveMethodFactory = new FiveMethodFactory();
        Car car = fiveMethodFactory.useCar();
        Ship ship = fiveMethodFactory.useShip();
        Air air = fiveMethodFactory.useAir();
        car.createCar();
        ship.createShip();
        air.createAir();
        Transport sevenMethodFactory = new SevenMethodFactory();
        Car car1 = sevenMethodFactory.useCar();
        Ship ship1 = sevenMethodFactory.useShip();
        Air air1 = sevenMethodFactory.useAir();
        car1.createCar();
        ship1.createShip();
        air1.createAir();

        //简单工厂模式
        SampleFactory sampleFactory = new SampleFactory();
        sampleFactory.setMoney("1000");
        Car car2 = sampleFactory.createCar();
        Ship ship2 = sampleFactory.createShip();
        Air air2 = sampleFactory.createAir();
        car2.createCar();
        ship2.createShip();
        air2.createAir();

        //反射


    }
}
