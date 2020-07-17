package DesignPattern.FactoryPattern.FactoryMethodPattern;

/**
 * 工厂方法模式将不同的实现的创建实现了隔离以及抽象。
 * 当我们使用简单工厂模式时，如果需要创建多个对象，则需要使用工厂的创建语句多次，当我们需要修改创建的对象时，就需要修改所有的创建语句
 * 假设我们有10个公司，每个公司需要100辆奥迪，使用简单工厂，我们需要创建100个奥迪车对象，但是如果有5个公司，每个公司要求把其中5台改
 * 为宝马车，则我们需要在5处地方，修改25个奥迪对象，如果将实现隔离开，我们只需要将奥迪车的生产工厂修改为宝马车工厂即可,其余地方
 * 不需要改动(因为每个工厂的创建方法都是一样)
 *
 */
public class Test {
    public static void main(String[] args) {
        //使用工厂方法模式，当需要将奥迪改为宝马，只需要把工厂改为宝马车工厂即可，只需要修改一条语句
        CarFactory factory = new AoDiFactory();
        Car car1 = factory.create();
        Car car2 = factory.create();
//        car1.createCar();
//        car2.createCar();
        //如果用简单工厂创建多个对象
        /*Factory factory = new Factory();
        SampleFactory car1 = factory.create("奥迪");
        SampleFactory car2 = factory.create("奥迪");
        SampleFactory car3 = factory.create("奥迪");
        当需要全部改为宝马时，需要修改三条语句
        *
        * */
    }
}
