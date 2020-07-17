package DesignPattern.FactoryPattern.SampleFactory;

/*
工厂模式可以实现解耦，提升扩展性。
将同一个抽象对象的不同实现分离开来。可以使得当需要扩展或者改动某一实现时，只需要修改对应的实现即可，不需要更改其他实现(比如下面的
三种生产汽车的实现，需要再添加一个汽车制造商时，只需要再创建一个SampleFactory的实现类即可)。
这时候如何制造对应的类，就需要创建一个工厂类，来负责根据不同情况，生成不同的类。
 */
public interface SampleFactory {
    void createCar();
}

class AoDi implements SampleFactory{
    public void createCar(){
        System.out.println("生产奥迪汽车");
    }
}

class BaoMa implements SampleFactory{
    public void createCar(){
        System.out.println("生产宝马汽车");
    }
}

class BenChi implements SampleFactory{
    public void createCar(){
        System.out.println("生产奔驰汽车");
    }
}

class DaZhong implements SampleFactory{
    public void createCar(){
        System.out.println("生产大众汽车");
    }
}

class Factory{
    public  SampleFactory create(String brand){
        SampleFactory car = null;
        switch (brand){
            case "奥迪":
                car = new AoDi();
                break;
            case "宝马":
                car = new BaoMa();
                break;
            case "奔驰":
                car = new BenChi();
                break;
            default:
                car = new DaZhong();
                break;
        }
        return car;
    }
}
