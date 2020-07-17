package DesignPattern.FactoryPattern.SampleFactory;

/**
 * 使用了简单工厂模式，后序需要扩展，只需要再添加实现类，更改Factory类即可。将类的不同实现解耦。而且简单工厂把具体的实现隐藏，用户
 * 只需要对照"说明书"使用即可(例如，想生产奥迪汽车就输入奥迪)，而具体使用哪个类生产汽车，工厂帮忙隐藏了。所以用户使用时，不需要关心
 * 具体使用哪个实现，所以实现了类的具体实现与使用的解耦。
 * 同时，如果某些类初始化的时候需要准备很多参数，我们可以将参数的准备放到工厂类中，我们使用简单工厂实现了类的创建与实现的解耦。当
 * 类的某一实现需要修改创建步骤，只需要修改工厂类即可，而不需要修改原来的实现(假设连接数据库，需要用户名、密码、数据库类型等变量，
 * 如果放到数据库连接类的具体实现中，当你需要修改的时候，意味着你需要把连接类的具体实现暴露，此时修改变量的同时，也可以修改你的增删
 * 改查操作，有代码泄漏的风险，而如果放在工厂类中，则数据库连接类对程序员隐藏)。
 * 但是当需要扩展的时候，需要额外添加一个实现类，但是还需要修改工厂类才可以，即对扩展开放,但是对修改也开放，违反开放-封闭原则。
 * 所以，为了不违法此原则，可以使用工厂方法模式。
 * 简单工厂应用场景：
 */
public class Test {
    public static void main(String[] args) {
        Factory factory = new Factory();
        SampleFactory car = factory.create("奥迪");
        car.createCar();
    }
}