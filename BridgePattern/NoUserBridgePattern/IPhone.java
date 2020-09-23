package DesignPattern.constructPattern.BridgePattern.NoUserBridgePattern;

public class IPhone implements Phone {
    @Override
    public void call() {
        System.out.println("使用苹果打电话");
    }

    @Override
    public void online() {
        System.out.println("使用苹果上网");
    }
}
