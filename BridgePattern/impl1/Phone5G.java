package DesignPattern.constructPattern.BridgePattern.impl1;

import DesignPattern.constructPattern.BridgePattern.impl1.Phone;

public class Phone5G implements Phone {
    @Override
    public void call() {
        System.out.println("使用5G手机打电话");
    }
    @Override
    public void online() {
        System.out.println("使用5G手机上网");
    }
}
