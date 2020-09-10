package DesignPattern.BuilderPattern;

//构建者模式更关注于对象的构建过程，使用构建者创造出来的对象的构建流程是相同的
//而工厂模式则更注重于生产对象的结果，即关注整体的构建，所以如果是构建步骤完全一样的产品，可以使用构造者模式来构造对象，外层
// 再使用工厂模式来生产。而如果对象的构建流程不相同，则需要具体情况具体分析，所以工厂模式可以构建生产流程不相同的各种对象
//所以，工厂模式 注重同意抽象的不同种类的实现，比如车--->奥迪、宝马   而构建者模式更多是体现同一对象的不同表现形式，比如奥迪suv，
// 奥迪跑车，但他们的本质都是奥迪
//本例 假设 有宝马车和奥迪车,使用简单工厂分别生产宝马和奔驰，使用构建者模式分别生产不同颜色的宝马和奔驰
//builder用来构建奥迪的不同表现形式
//factory用来生成car的不同实现
public class Test {
    public static void main(String[] args) {
        Factory factory  = new Factory();

        Car AoDi = factory.create("宝马SUV");
        AoDi.useCar();
    }
}
