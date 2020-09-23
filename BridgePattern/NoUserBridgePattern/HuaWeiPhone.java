package DesignPattern.constructPattern.BridgePattern.NoUserBridgePattern;

public class HuaWeiPhone implements Phone {
    @Override
    public void call() {
        System.out.println("使用华为手机打电话");
    }

    @Override
    public void online() {
        System.out.println("使用华为手机上网");
    }
}
