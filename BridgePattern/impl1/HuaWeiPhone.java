package DesignPattern.constructPattern.BridgePattern.impl1;

public class HuaWeiPhone {
    private Phone phone;

    public HuaWeiPhone(Phone phone){
        this.phone = phone;
    }

    public void call(){
        System.out.println("华为手机");
        phone.call();
    }

    public void online(){
        System.out.println("华为手机");
        phone.online();
    }
}
